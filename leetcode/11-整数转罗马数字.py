num = int(input())

re = ''
# 先分解个位数：
a = num%10
if(a==9):
    re+='IX'
elif(a<9 and a>=5):
    re+='V'+'I'*(a-5)
elif(a==4):
    re+='IV'
else:
    re+='I'*a

if(num<10):
    print(re)
    exit()

# 分解十位
b = (num%100-a)//10
if(b==9):
    re ='XC' + re
elif(b<9 and b>=5):
    re = 'L'+'X'*(b-5) + re
elif(b==4):
    re = 'XL' + re
else:
    re = 'X'*b +re

if(num<100):
    print(re)
    exit()

# 分解白位：
c = (num%1000-a-b)//100
if(c==9):
    re = 'CM' + re
elif(c<9 and c>=5):
    re = 'D'+'C'*(c-5) + re
elif(c==4):
    re = 'CD' + re
else:
    re = 'C'*c + re

if(num<1000):
    print(re)
    exit()
# 分解更高位
d = num//1000
re = 'M'*d +re

print(re)