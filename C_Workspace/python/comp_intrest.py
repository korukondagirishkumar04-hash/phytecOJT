p = float(input("Enter  amount:"))
r = float(input("Enter rate: "))
t = float(input("Enter time: "))
a = p * ((1 + r/100) ** t)
ci = a - p
print("Compound Interest:", ci)