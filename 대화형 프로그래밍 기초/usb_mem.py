#2020114658 이윤서
#3주차 과제_1_USB 메모리 쇼핑 금액 계산

memory=input("USB 메모리 용량(GB)을 입력하세요(128, 64, 32, 16): ")        #USB용량입력
type=input("USB 메모리 타입을 입력하세요(slide, cap, rotat): ")            #USB타입입력
num=int(input("USB 메모리 개수를 입력하세요: "))                           #USB개수입력

#용량별가격계산
if memory=='128' :
    price=45000
elif memory=='64' :
    price=32000
elif memory=='32' :
    price=16000
else :
    price=8000

#타입별가격계산
if type=='slide' :
    price=price+2000
elif type=='cap' :
    price=price+1000

print('USB 하나의 가격은 %d'%price)       #USB가격
total=price*num                          #배송비제외 총금액

#배송비계산
if total<30000 :
    delivery_fee=3000
else :
    delivery_fee=0

#결과출력
print('전체 USB 금액: %d'%(total+delivery_fee))
print('배송료: %d  전체 지불 금액: %d'%(delivery_fee, total))