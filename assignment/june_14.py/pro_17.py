# sum of number in a given range


n=int(input("enter the number:"))
ran=int(input("enter range:"))
sum=0
for i in range(n,ran+1):
    sum+=i
print(sum)