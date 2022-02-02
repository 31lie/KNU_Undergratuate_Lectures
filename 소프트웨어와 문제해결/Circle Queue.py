# 2020114658 이윤서
# 12주차 과제_원형 음식 주문



def order_food(size):
    global rear, front, num
    if front%size==(rear+1)%size:
        is_full(size)
    else:
        rear=(rear+1)%size
        num+=1
        if len(table)==8:
            table[rear]=num
        else:
            table.insert(rear,num)
            print_now(size)

def is_full(size):
    global rear,front
    if front%size==(rear+1)%size:
        print('--------------------------')
        print('주문이 밀려 있습니다.')
        print('--------------------------')

def provide_food(size):
    global rear, front, provide
    if front==rear:
        is_empty()
    else:
        front=(front+1)%size
        provide+=1
        table[front]=0
        print('음식 제공: %d'%provide)
        if front == rear:
            is_empty()
        else:
            print_now(size)

def is_empty():
    if front==rear:
        print('--------------------------')
        print('주문한 음식이 없습니다.')
        print('--------------------------')

def calculate(size):
    global rear, front
    if rear<front:
        food = rear-front+size
    else:
        food = rear-front
    return food


def print_now(size):
    global rear,front
    print('--------------------------')
    print('front:%d, rear:%d, 주문 음식수:%d'%(front,rear,calculate(size)))
    print('Queue: ', end='')
    i=(front+1)%size
    while i!=rear:
        print('[%d]: %d'%(i,table[i]),end=' ')
        i=(i+1)%size
    if i==rear:
        print('[%d]: %d' % (i, table[i]))
    print('--------------------------')

#메인함수
def main(size):
    while True:
        print(menu)
        select=input('메뉴를 선택하세요: ')
        if select=='1':
            order_food(size)
        elif select=='2':
            provide_food(size)
        elif select=='3':
            print_now(size)
        elif select=='4':
            print('종료합니다.')
            break
        else:
            print('잘못된 입력입니다. 다시 입력하세요.')



#초기값 및 큐 사이즈
front=0
rear=0
queue_size=8
num=0
provide=0

#메뉴
menu='''\
1. 음식 주문 접수
2. 주문 음식 제공
3. 주문 현황 출력
4. 종료\
'''

#테이블 생성
table=[0]

#메인함수 호출
main(queue_size)