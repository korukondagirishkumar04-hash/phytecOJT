# count digit in a number

s=int(input("enter the number:"))

count=0
while s>0:
   count+=1
   s=s//10
print(count)    