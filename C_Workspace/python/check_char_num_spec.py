a = input("Enter the character: ")

if ((a >= 'A' and a <= 'Z') or
    (a >= 'a' and a <= 'z')):

    print("ALPHABET")

elif (a >= '0' and a <= '9'):

    print("NUMBER")

else:

    print("SPECIAL CHARACTER")