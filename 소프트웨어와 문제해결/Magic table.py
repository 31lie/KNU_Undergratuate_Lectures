# 2020114658 이윤서
# 13주차 과제_마방진




def move(size):
    global x,y,table
    y,x=0,(size//2)
    num=0
    for i in range (size**2):
        num+=1
        table[y][x]=num
        pre_x=x
        pre_y=y
        y=y-1
        x=x+1
        if y<0 :
            y=size-1
        if x>size-1:
            x=0
        if table[y][x]!=0:
            y=pre_y+1
            x=pre_x


def printing(size):
    print('Magic Square(%dx%d)'%(size,size))
    for i in range(size):
        for j in range(size):
            print('%4d'%table[i][j],end='')
        print()

def main(size):
    global table
    table = [[0]*size for i in range(size)]
    move(size)
    printing(size)



while True:
    size = int(input('홀수차 배열의 크기를 입력하세요: '))
    if size%2!=0:
        main(size)
        break
    else:
        print('짝수를 입력하였습니다. 다시 입력하세요.')
