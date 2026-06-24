# leap year or not

year=int(input("enter the number:"))
if (year%4==0) or (year%400==0)and (year%100!=0):
    print("leapyear")
else:
    print("not leapyear")
