import django
from xml.etree import ElementTree
from datetime import datetime, date, timedelta
import pip._vendor.requests

import schedule
import time

import os
# Python이 실행될 때 DJANGO_SETTINGS_MODULE이라는 환경 변수에 현재 프로젝트의 settings.py파일 경로를 등록합니다.
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'cims.settings')

# 이제 장고를 가져와 장고 프로젝트를 사용할 수 있도록 환경을 만듭니다.
django.setup()

from coronicStatus.models import CoronicStatusOfRegion, CoronicStatusOfKorea

def getCoronicOfStatusData():
    # get today's date
    today = datetime.today().strftime('%Y%m%d')

    # get today coronic information through API
    url = 'http://openapi.data.go.kr/openapi/service/rest/Covid19/getCovid19SidoInfStateJson'
    params = {'serviceKey': '2OCjKTdtNKX2G7YWs2awIP5jVNrtaJ2546EqSVDXtXVtj6/UIwrIqp4I9dPQmT4Qmpnb0snYczcCuL+XqdOMtw==',
              'pageNo': '1', 'numOfRows': '19', 'startCreateDt': today, 'endCreateDt': today}
    response = pip._vendor.requests.get(url, params=params)
    coronicStatus = response.content

    root = ElementTree.fromstring(coronicStatus)

    # save region name
    region = ['Total', '서울', '부산', '대구', '인천', '광주', '대전', '울산', '세종', '경기도', '강원도', '충청북도', '충청남도', '전라북도', '전라남도', '경상북도', '경상남도', '제주', '검역']
    
    # save the number of Coronic
    todayCoronic = []
    for root_e in root.iter('incDec'):
        todayCoronic.append(int(root_e.text))

    todayCoronic.reverse()
    
    yesterday = (date.today() - timedelta(1)).strftime('%Y.%m.%d')
    year, month, day = yesterday.split('.')
    
    return region, year, month, day, todayCoronic

def auto():
    if __name__ == '__main__':
        region, year, month, day, coronicCount = getCoronicOfStatusData()
        for i in range(0, len(region)):
            if region[i] == 'Total':
                queryset = CoronicStatusOfKorea.objects.all()

                if queryset.count():
                    data = queryset.first()
                    temp = data.coronicCount
                    data.year = year
                    data.month = month
                    data.day = day
                    data.coronicCount = coronicCount[i]
                    data.coronicGap = coronicCount[i] - temp
                    data.save()
                else:
                    CoronicStatusOfKorea(year=year, month=month, day=day, coronicCount=coronicCount[i], coronicGap=0).save()
            else:    
                queryset = CoronicStatusOfRegion.objects.all()
                if queryset.count() == len(region) - 1:
                    if queryset.get(region=region[i]):
                        data = queryset.get(region=region[i])
                        temp = data.coronicCount
                        data.year = year
                        data.month = month
                        data.day = day
                        data.coronicCount = coronicCount[i]
                        data.coronicGap = coronicCount[i] - temp
                        data.save()
                else:
                    CoronicStatusOfRegion(region=region[i], year=year, month=month, day=day, coronicCount=coronicCount[i], coronicGap=0).save()

schedule.every().day.at("12:00").do(auto)

while True:
    schedule.run_pending()
    time.sleep(1)