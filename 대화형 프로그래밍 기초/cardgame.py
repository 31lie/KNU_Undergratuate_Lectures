#2020114658 이윤서
#6주차 과제_카드게임

import random

#리스트출력함수 정의
def print_func(listname) :
    cnt=0
    for element in listname :
        print(element, end=' ')
        cnt+=1
        if cnt%13==0 :
            print()

#뽑는함수 정의
def randomcard(listname,amount) :
    randomlist=list()
    for i in range (amount) :
        a=random.randrange(0,len(listname)-1)
        randomlist.append(listname[a])
        listname.remove(listname[a])
    return randomlist

#점수계산함수 정의
def score_calc(list) :
    score=0
    for j in range (len(list)):
        if list[j][0] == '♣' :
            score=score+4*(list[j][1])
        elif list[j][0] == '♠' :
            score=score+3*(list[j][1])
        elif list[j][0] == '◆' :
            score=score+2*(list[j][1])
        elif list[j][0] == '♥' :
            score=score+1*(1*list[j][1])
    return score


#승패판별함수 정의
def find_winner(score1,score2) :
    result='Player1 Win'
    if score1<score2 :
        result = 'Player2 Win'
    if score1==score2 :
        result = 'Winner isn\'t exist'
    print(result)



#-----------------코드 시작--------------------------------

#무늬숫자카드리스트 정의
card_number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
card_suit = ['♠', '♥', '♣', '◆']
card = list()

#카드리스트 입력
for i in range(len(card_suit)) :
    for j in range(len(card_number)) :
        card.append((card_suit[i],card_number[j]))
#무늬숫자카드리스트 정의
card_number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
card_suit = ['♠', '♥', '♣', '◆']
card = list()

#카드리스트 입력
for i in range(len(card_suit)) :
    for j in range(len(card_number)) :
        card.append((card_suit[i],card_number[j]))

#초기카드 출력
print('초기 카드 생성')
print_func(card)

#섞은카드 출력
print('Shuffled Card')
random.shuffle(card)
print_func(card)

#카드분배 및 점수계산
print('Dealing five cards')
player1 = 0
player2 = 0
for i in range (2) :
    playercard=randomcard(card,5)
    print('Player%d: '%(i+1),playercard)
    score_calc(playercard)
    playerscore=score_calc(playercard)
    if i==0 :
        player1=playerscore
    if i==1 :
        player2=playerscore

#최종점수 및 결과 출력
print('Player1: %d, Player2: %d'%(player1,player2))
find_winner(player1,player2)