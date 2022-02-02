#2020114658 이윤서
#2주차 과제_BMI 계산

name=input("이름을 입력하세요: ")                   #이름입력
height=int(input("키(cm)를 입력하세요: "))          #키입력
weight=int(input("몸무게(kg)을 입력하세요: "))      #몸무게입력

bmi=weight/(height*0.01)**2                        #BMI지수계산

print("%s님의 BMI는 %.1f 입니다."%(name,bmi))         #결과값출력
