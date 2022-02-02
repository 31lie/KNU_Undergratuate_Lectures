#2020114658 이윤서
#5주차 과제1_Zigzag 배열 출력문제

#array 배열 선언
array = [[0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0]]

print('Zigzag Array')
a=1

#리스트 입력
for i in range (5) :            #행
    if i%2==0 :                 #오른쪽 증가
        for j in range (5) :
            array[i][j]=a
            a+=1
    else :                      #왼쪽증가
        for j in range (5,0,-1) :
            array[i][j-1]=a
            a+=1


#리스트 출력
for i in range (5) :
    for j in range (5) :
        print('{0:3d}'.format(array[i][j]),end=' ')
    print()
