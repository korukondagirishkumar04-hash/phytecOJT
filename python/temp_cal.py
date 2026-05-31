climate=int(input("enter the condition:"))

if ((climate>=10) and (climate<=30)):
    print("warm condition")
elif ((climate>=30) and (climate<=50)):
    print("hot condition")
elif ((climate>=0)  and (climate<=10)):
    print("cold condition")
else:
    print("invalid")