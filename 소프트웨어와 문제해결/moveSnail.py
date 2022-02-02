#2020114658 이윤서
#4주차 과제_달팽이 이동

#시작, 마지막 지점 설정과 날짜변수 설정
start=0
finish=0
i=1

#50미터에 도착하기 전까지 반복
while finish<=50 :
    finish=start+3                                                                                                #3미터씩 이동
    print('day %d, 시작위치: %d 미터, 달팽이의 마지막 위치: %d 미터' % (i, start, finish))                          #이동결과 출력
    start=finish                                                                                                  #다음날출발위치=전날도착위치
    i=i+1                                                                                                         #day 증가
print('우물을 탈출하는 데 걸린 날은 %d일 입니다.'%(i-1))                                                            #최종결과출력