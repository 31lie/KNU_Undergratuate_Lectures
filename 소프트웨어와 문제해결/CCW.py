#2020114658 이윤서
#5주차 과제2_배열 반시계방향 rotate

#array 배열 선언
array = [[1, 2, 3, 4, 5],
         [6, 7, 8, 9, 10],
         [11, 12, 13, 14, 15],
         [16, 17, 18, 19, 20],
         [21, 22, 23, 24, 25]]

#rotaArray 배열 선언
rotateArray = [[0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0]]

#Original Array 출력
print('Original Array')
for i in range (5) :
    for j in range (5) :
        print('{0:3d}'.format(array[i][j]), end=' ')
    print()

#rotateArray 값 저장
for i in range (5) :
    for j in range (5) :
        rotateArray[4-j][i]=array[i][j]

#rotateArray 출력
print()
print('CCW 90 Rotated Array')
for i in range (5) :
    for j in range (5) :
        print('{0:3d}'.format(rotateArray[i][j]), end=' ')
    print()
