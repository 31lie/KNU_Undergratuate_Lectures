#2020114658 이윤서
#6주차 과제_에라토스테네스의 체




#출력함수 정의
def print_func(num_list,count) :
    cnt=0
    for i in range (count) :
        print('%4s'%num_list[i], end=' ')
        cnt+=1
        if cnt%10==0 :
            print()

#배수제거함수 정의
def remove_num(num_list,count,prime) :
    for i in range (count) :
        if int(wholeNum[i])%int(prime)==0 and int(wholeNum[i])!=int(prime) :
            num_list[i]='X'

#----------------코드 시작--------------

#리스트 생성
wholeNum=[]
primeNum=[]

#리스트 저장
i=2
while i<=100 :
    wholeNum.append(i)
    i+=1

#오리지널 출력
print('Original Number =>')
print_func(wholeNum,99)

#배수제거 출력
multiple=['2','3','5','7']
primeNum=wholeNum.copy()
i=0

for i in range (4) :
    print()
    print('Remove %s\'s multiple numbers'%multiple[i])
    remove_num(primeNum, 99, multiple[i])
    print_func(primeNum, 99)
    print()

print('Prime numbers: ')
print_func(primeNum, 99)