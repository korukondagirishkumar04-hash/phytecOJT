num=int(input("enter the number"))
rev=0
digit=0
while(num):
    digit=num%10
    rev=rev*10+digit
    num=num//10
print(rev)    
print("orginal number print")
org=0
digit=len(str(rev))
for i in range(digit):
    rem=rev%10
    org=org*10+rem
    rev=rev//10
print(org)    