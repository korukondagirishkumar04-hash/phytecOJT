# sum of N natural number

n=int(input("enter the number:"))
sum=0
if(n>0):
    for n in range(1,n+1):
        sum=sum+n
print(sum)