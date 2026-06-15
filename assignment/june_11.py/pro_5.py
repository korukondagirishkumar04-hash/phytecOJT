start=int(input("enter the number"))
stop=int(input("enter the number"))

if(start<0 or stop<0):
    print("invalid")

else:
    print("prime number are")
    for num in range(start,stop+1):
        if(num<2):
            continue
        is_prime=True
        for i in range(2,num):
            if(num%i==0):
                is_prime=False
                break
        if is_prime:
            print(num,end="  ")
            