# print 1 to 100 if divisible by 3 it is fizz,by 5 it buzz


for i in range(1,100):
    if i%3==0 and i%5==0:
        print("fizzbuzz")
    elif i%3==0:
        print("fizz")
    elif i%5==0:
        print("buzz")
    else:
        print(i)