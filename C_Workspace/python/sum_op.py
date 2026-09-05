a=float(input("enter the number:"))
b=float(input("enter the number:"))
op=input("operation(+,-,/*)")

if op=='+':
    print("result",a+b)
elif op=='-':
    print("result",a-b)
elif op=='*':
    print("result",a*b)
elif op=='/':
    print("result",a/b)
else:
    print("invalid")
