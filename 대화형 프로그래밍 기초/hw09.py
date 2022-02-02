# 2020114658 이윤서
# 9주차 과제_기념일 계산


import datetime as dt

def howmany() :
    return today-start

def anniversary() :
    days100= dt.timedelta(days=100)
    days200= dt.timedelta(days=200)
    days300= dt.timedelta(days=300)
    days500= dt.timedelta(days=500)
    days1000= dt.timedelta(days=1000)
    after100days = start +days100
    after200days = start +days200
    after300days = start +days300
    after500days = start +days500
    after1000days = start +days1000
    print('100일: %d년 %d월 %d일' %(after100days.year, after100days.month, after100days.day))
    print('200일: %d년 %d월 %d일' %(after200days.year, after200days.month, after200days.day))
    print('300일: %d년 %d월 %d일' %(after300days.year, after300days.month, after300days.day))
    print('500일: %d년 %d월 %d일' %(after500days.year, after500days.month, after500days.day))
    print('1000일: %d년 %d월 %d일' %(after1000days.year, after1000days.month, after1000days.day))

today = dt.date.today()
start = dt.date(2020,1,1)
howmany = howmany()
print('연애 시작일: 2020년 1월 1일')
print('오늘 날짜: %d년 %d월 %d일' %(today.year, today.month, today.day))
print('연애 시작일로부터 경과한 날짜: %d일' %howmany.days)
print('-----------------------------------')
anniversary()