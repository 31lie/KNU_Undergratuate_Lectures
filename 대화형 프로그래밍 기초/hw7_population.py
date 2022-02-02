#2020114658 이윤서
#7주차 과제_연렫대별 인구 분포 조사




'''
    homework: 연렫대별 인구 분포 조사
    - dictionary 생성 및 각 연령대별 인구 분포 계산
    - 투표 가능 인구 조사

       [0]     [1]    [2]     [3]     [4]     [5]     [6]     [7]     [8]      [9]
     | 0~9 | 10~19 | 20~29 | 30~39 | 40~49 | 50~59 | 60~69 | 70~79 | 80~89 | 90~100 |
     +-----+-------+-------+-------+-------+-------+-------+-------+-------+--------+

'''
import matplotlib.pyplot as plt
import numpy as np

def draw_barchart(citya_keylist, citya_valuelist, cityb_valuelist):
    x_labels = citya_keylist

    index = np.arange(len(x_labels))
    width = 0.4

    fig, ax = plt.subplots()
    rect1 = ax.bar(index - width/2, citya_valuelist, width, label="City A")
    rect2 = ax.bar(index + width/2, cityb_valuelist, width, label="City B")

    ax.set_xlabel('age')
    ax.set_ylabel('Population')                     # y축 레이블
    ax.set_title("The demographics of two cities")  # 그래프 타이틀

    plt.xticks(index + (width/10), x_labels)                   # X축 데이터
    plt.legend(fontsize=9, loc="upper right")
    plt.savefig('barchart01.png')
    plt.close()



def draw_piechart(citya_total, citya_value, cityb_total, cityb_value, title_name):
    '''
        Pic chart를 그려줌
        citya_total: City A's total population
        citya_value: City A's a specific value

        cityb_total: City B's total population
        cityb_value: City B's a specific value
    '''
    citya_list = [citya_value, citya_total-citya_value]
    cityb_list = [cityb_value, cityb_total-cityb_value]
    label_list = [title_name , ""]

    fig, (ax1, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(12, 6))

    # City A의 pie chart
    ax1.pie(citya_list, labels=label_list, autopct="%.1f%%")
    ax1.set_title("City A's " +  title_name)

    # City B의 pie chart
    ax2.pie(cityb_list, labels=label_list, autopct="%.1f%%")
    ax2.set_title("City B's " + title_name)
    plt.savefig(title_name+".png")
    plt.close()



def population_analysis():
    global citya_keylist,  citya_valuelist, cityb_valuelist, citya_total, citya_votable, cityb_total, cityb_votable, citya_old, cityb_old
    draw_barchart(citya_keylist, citya_valuelist, cityb_valuelist)
    draw_piechart(citya_total, citya_votable, cityb_total, cityb_votable, 'Voting rate')
    draw_piechart(citya_total, citya_old, cityb_total, cityb_old, 'Old people rate')






#---------------------------------------------------------------------






#도시별 딕셔너리 생성
dict_citya={'0-9':80, '10-19':100, '20-29':140, '30-39':160, '40-49':200, '50-59':240, '60-69':195, '70-79':160, '80-89':80, '90-99':20}
dict_cityb={'0-9':120, '10-19':200, '20-29':300, '30-39':360, '40-49':400, '50-59':300, '60-69':40, '70-79':25, '80-89':20, '90-99':10}

#전체인구현황_key,value 리스트 변환
citya_keylist=[]
for item in dict_citya.keys():
    citya_keylist.append(item)

citya_valuelist=[]
for item in dict_citya.values():
    citya_valuelist.append(item)

cityb_valuelist=[]
for item in dict_cityb.values():
    cityb_valuelist.append(item)




#도시A 전체 인구수 계산
citya_total=0
for i in range(len(citya_keylist)) :
    citya_total=citya_total+citya_valuelist[i]

#도시B 전체 인구수 계산
cityb_total=0
for i in range(len(citya_keylist)) :
    cityb_total=cityb_total+cityb_valuelist[i]

#도시A 20세 이상 인구수 계산
citya_votable=0
for i in range(len(citya_keylist)) :
    if i>1 :
        citya_votable=citya_votable+dict_citya[citya_keylist[i]]

#도시B 20세 이상 인구수 계산
cityb_votable=0
for i in range(len(citya_keylist)) :
    if i>1 :
        cityb_votable=cityb_votable+dict_cityb[citya_keylist[i]]


#도시A 70세 이상 인구수 계산
citya_old=0
for i in range(len(dict_citya)) :
    if i>6 :
        citya_old=citya_old+dict_citya[citya_keylist[i]]

#도시B 70세 이상 인구수 계산
cityb_old=0
for i in range(len(dict_citya)) :
    if i>6 :
        cityb_old=cityb_old+dict_cityb[citya_keylist[i]]


population_analysis()


print('Key', citya_keylist)
print('City A:', citya_valuelist)
print('City B:', cityb_valuelist)
print('City A voting number: {0}, total number: {1}, voting rate: {2:.1f}%'.format(citya_votable, citya_total,(citya_votable/citya_total)*100))
print('City B voting number: {0}, total number: {1}, voting rate: {2:.1f}%'.format(cityb_votable, cityb_total,(cityb_votable/cityb_total)*100))
print('City A old peole number: {0}, total number: {1}, old people rate: {2:.1f}%'.format(citya_old, citya_total,(citya_old/citya_total)*100))
print('City B old peole number: {0}, total number: {1}, old people rate: {2:.1f}%'.format(cityb_old, cityb_total,(cityb_old/cityb_total)*100))

