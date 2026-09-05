# first sum of three and remove the third value 

def add(a,b,c):
    total=a+b+c
    print("sum of three numbers",total)
    total=a+b
    print("removing the third number",total)
n1=int(input("enter the first number"))
n2=int(input("enter the second number"))
n3=int(input("enter the third number"))
add(n1,n2,n3)