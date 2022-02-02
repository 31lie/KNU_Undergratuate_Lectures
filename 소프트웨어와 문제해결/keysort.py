#2020114658 이윤서
#7주차 과제_키 정렬

import random

def ascending(list) :
    for i in range(len(list)-1) :
        small = list[i+1]
        for j in range(i+1,len(list)) :
            if list[j]<small :
                small=list[j]
        if list[i]>small :
            a=list.index(small)
            temp=list[i]
            list[i]=list[a]
            list[a]=temp
        print(list)

def descending(list) :
    for i in range(len(list)-1) :
        big = list[i+1]
        for j in range(i+1,len(list)) :
            if list[j]>big :
                big=list[j]
        if list[i]<big :
            a=list.index(big)
            temp=list[i]
            list[i]=list[a]
            list[a]=temp
        print(list)



randarray = random.sample(range(120,170),10)

print('초기 자료값: ', randarray)
print('----------------------------------------------------')
print('오름차순 정렬')
ascending(randarray)
print('----------------------------------------------------')
print('내림차순 정렬')
descending(randarray)
print('----------------------------------------------------')