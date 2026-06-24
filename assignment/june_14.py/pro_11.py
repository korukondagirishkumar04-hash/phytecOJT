# reverse number

s=int(input("enter the number"))
digit=0
rev=0
while s>0:
    digit=s%10
    rev=rev*10+digit
    s=s//10
print(rev)
    