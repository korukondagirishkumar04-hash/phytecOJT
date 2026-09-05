user = "girish"
password = "1234"

chances = 3

while chances > 0:

    u = input("enter the user: ")
    p = input("enter the pass: ")

    if (u == user and p == password):
        print("login successful")
        break

    else:
        chances -= 1
        print("chances left:", chances)

if chances == 0:
    print("account blocked")