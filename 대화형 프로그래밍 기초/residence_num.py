#2020114658 이윤서
#3주차 과제_2_주민등로번호에서 출신 지역 출력


while True :
    id_num = input("주민등록번호를 입력하세요: ")           #주민등록번호 입력
    area_num = int(id_num[8:10])
    if area_num>95 :                                      #올바른 주민등록번호인지 판단
        print("잘못된 주민등록번호입니다.")
    else :
        break

#지역판단
if area_num<=8 :
    area='서울'
elif area_num<=12 :
    area='부산'
elif area_num<=15 :
    area='인천'
elif area_num<=25 :
    area='경기'
elif area_num<=34 :
    area='강원'
elif area_num<=47 :
    area='충청'
elif area_num<=66 :
    area='전라'
elif area_num<=91 :
    area='경상'
else :
    area='제주'


print("%s: 출생 지역은 %s입니다."%(id_num, area))          #결과출력