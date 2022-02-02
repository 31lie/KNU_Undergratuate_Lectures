# 2020114658 이윤서
# 11주차 과제_알파벳 빈도수 계산 프로그램

'''
    Homework: 알파벳 빈도수 계산 프로그램
    - 파일 입력: loremipsum.txt 파일
    - 문자열을 읽어서 각 알파벳 소문자, 대문자의 빈도수를 계산하고 이를 그래프로 표시함

'''

import matplotlib.pyplot as plt

def draw_barchart(outfile, keylist, valuelist):
    plt.bar(keylist, valuelist)

    plt.xlabel('Alphabet')
    plt.ylabel("Count")
    plt.savefig(outfile)
    print(outfile + " is saved.")
    plt.close()



infile = open('loremipsum.txt', "r")
lower_freqs = {}
upper_freqs = {}

for line in infile:
    for char in line.strip():
        if char.isalpha():
            if char.islower():
                if char in lower_freqs:
                    lower_freqs[char]+=1
                else:
                    lower_freqs[char]=1
            if char.isupper():
                if char in upper_freqs:
                    upper_freqs[char] += 1
                else:
                    upper_freqs[char] = 1

infile.close()

def f2(x):
    return x[1]

sorted_lower_freqs = sorted(lower_freqs.items(),reverse=True, key=f2)
sorted_upper_freqs = sorted(upper_freqs.items(),reverse=True, key=f2)

print(sorted_upper_freqs)
print(sorted_lower_freqs)

upper_keylist = []
for i in range (len(sorted_upper_freqs)):
    upper_keylist.append(sorted_upper_freqs[i][0])

upper_valuelist=[]
for i in range (len(sorted_upper_freqs)):
    upper_valuelist.append(sorted_upper_freqs[i][1])

lower_keylist = []
for i in range(len(sorted_lower_freqs)):
    lower_keylist.append(sorted_lower_freqs[i][0])

lower_valuelist = []
for i in range(len(sorted_lower_freqs)):
    lower_valuelist.append(sorted_lower_freqs[i][1])



draw_barchart('upper.png', upper_keylist, upper_valuelist)
draw_barchart('lower.png', lower_keylist, lower_valuelist)

