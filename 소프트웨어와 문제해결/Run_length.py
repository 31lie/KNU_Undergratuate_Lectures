#2020114658 이윤서
#8주차 과제_데이터 압축

#압축함수
def encoding(string) :
    encoding=''
    count=1
    for i in range (len(string)-1) :
        if string[i]==string[i+1] :
            count+=1
            if i==len(string)-2 :
                encoding += str(count) + string[i]
        else :
            encoding+=str(count)+string[i]
            count=1
    if string[-1]!=string[-2] :
        encoding+='1'+string[-1]
    return encoding

#디코딩함수
def decoding(string) :
    decoding=''
    for i in range(0,len(string),2) :
        decoding+=string[i+1]*int(string[i])
    return decoding



original=input('압축할 문자열을 입력하시오: ')
encoding_string=encoding(original)
print('압축된 문자열: %s'%encoding_string)
decoding_string=decoding(encoding_string)
print('원본 문자열: %s'%decoding_string)