# find factors of a number


s=int(input("enter the number"))
factorial=1
for i in range(1,s+1):
    if s%i==0:
        print(i)
    