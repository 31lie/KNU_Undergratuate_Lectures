#2020114658 이윤서
#10주차 과제_테니스 공


def push_ball():
    global count, top,case
    if count==5:
        print('케이스가 꽉 찼습니다.')
    else :
        count+=1
        top+=1
        case.insert(0,count)
        printing()

def pop_ball():
    global count, top, case
    if count==0:
        print('케이스가 비어있습니다.')
    else :
        case.remove(count)
        print('Pop(%d)'%count)
        count -= 1
        top -= 1
        if count==0:
            print('케이스가 비어있습니다.')
        else:
            printing()

def printing():
    global count, top, case
    if count==0:
        print('케이스가 비어있습니다.')
    else:
        print('[공의 개수]: %d'%count)
        for i in range(top+1):
            print('%d'%case[i], end=' ')
        print()



case=[]
top=-1
count=0

while True :
    print('------------------------------')
    print('1. 테니스 공 넣기')
    print('2. 테니스 공 꺼내기')
    print('3. 테니스 공 개수 출력')
    print('4. 종료')
    select = input('메뉴를 선택하세요: ')
    if select=='1' :
        push_ball()
    elif select=='2' :
        pop_ball()
    elif select=='3' :
        printing()
    elif select=='4' :
        break
    else :
        print('잘못된 메뉴 선택입니다.')