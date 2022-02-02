#2020114658 이윤서
#4주차 과제_로또번호 자동생성 프로그램


import random

while True :
    n = int(input('로또를 몇장 구매하시겠습니까? '))
    if n<=0 :                       #구매종료
        print('종료합니다.')
        break
    else :                          #구매지속
        print('랜덤하게 생성된 로또 번호입니다.')
        i=1
        for i in range(1,n+1) :                         #구매장수체크
                print('[%d]:' %i, end=' ')
                for s in range(7) :                     #로또번호출력
                    random_num= random.randint(1,46)
                    print('%4d'%random_num, end=' ')
                print()






