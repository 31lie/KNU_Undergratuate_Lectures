#2020114658 이윤서
#5주차 과제_자판기 프로그램


#종료함수 정의
def finish() :
    print('-'*30)
    print('커피 자판기 동작을 종료합니다.')
    print('-' * 30)

#메뉴함수 정의
def menuSelect() :
    print(menu)
    selectmenu=int(input('메뉴를 선택하세요: '))
    return selectmenu

#블랙커피함수 정의
def blackCoffee() :
    global coffee, water, papercup, change_coin, coin
    coffee=coffee-30
    water= water-100
    papercup=papercup-1
    coin = coin-300
    print('블랙 커피를 선택하셨습니다. 잔돈: %d'%coin)

#프림커피함수 정의
def frimaCoffee() :
    global coffee, water, papercup, change_coin, frima, coin
    coffee=coffee-15
    frima=frima-15
    water=water-100
    papercup=papercup-1
    coin = coin-300
    print('프림 커피를 선택하셨습니다. 잔돈: %d' %coin)

#설탕프림커피함수 정의
def sugarCoffe() :
    global coffee, water, papercup, change_coin, frima, sugar, coin
    coffee=coffee-10
    frima=frima-10
    sugar=sugar-10
    water=water-100
    papercup=papercup-1
    coin=coin-300
    print('설탕 프림 커피를 선택하셨습니다. 잔돈: %d' %coin)

#재고판단함수_블랙커피정의
def stock_blackCoffee() :
    global start
    if water<100 and coffee<30 and cup<1 :
        print('재고가 부족합니다.')
    else :
        start=1


#재고판단함수_프림커피정의
def stock_frimaCoffee() :
    global start
    if water<100 and coffee<15 and frima<15 and cup<1 :
        print('재고가 부족합니다.')
    else :
        start=1


#재고판단함수_설탕커피정의
def stock_sugarCoffee() :
    global start
    if water<100 and coffee<10 and frima<10 and sugar<10 and cup<1 :
        print('재고가 부족합니다.')
    else :
        start=1

#잔돈판단함수
def change_available() :
    stop=0
    if coin<300 :
        print('잔돈이 부족해서 종료합니다.')
        finish()
        stop=1
        return stop
    else :
        return stop

#---------------------------------------------코드 시작------------------------------

#초기 자판기 상황
change_coin, water, coffee, frima, sugar, papercup = 10000, 1000, 500, 500, 500, 30

#진행변수 설정
start=0

#메뉴판
menu = '''\
------------------------------------
        커피 자판기 (300원)
1. 블랙 커피
2. 프림 커피
3. 설탕 프림 커피
4. 재고 현황
5. 종료\
'''

coin=int(input('동전을 투입하세요: '))          #동전입력
change_coin=change_coin+coin

while True :
    if not coin>= 300 :
        print('돈이 부족합니다. %d원: '%coin)
        finish()
        break
    else :
        select=menuSelect()
        if select==1 :
            stock_blackCoffee()
            if start==1 :
                blackCoffee()
                if change_available()==1 :
                    break

            else :
                break
        elif select==2 :
            stock_frimaCoffee()
            if start==1 :
                frimaCoffee()
                if change_available()==1 :
                    break
            else:
                break
        elif select==3 :
            stock_sugarCoffee()
            if start==1 :
                sugarCoffe()
                if change_available()==1 :
                    break
            else :
                break
        elif select==4 :
            print('------------------------------')
            print('재고 현황:')
            print('커피: %dg, 프림: %dg, 설탕: %dg'%(coffee, frima, sugar))
            print('물: %dml, 종이컵: %d개' %(water, papercup))
            print('자판기 남은 돈: %d원, 잔돈 현황: %d원'%(change_coin-coin,coin))
        else :
            finish()
            break






