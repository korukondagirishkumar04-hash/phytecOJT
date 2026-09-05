# count python program separate consonants and vowels


b=input("enter the character.:").lower()
vowels=""
consonant=""
vcount=0
ccount=0
for ch in b:
    if ch.isalpha():
        if ch in "aeiou":
            vowels+=ch
            vcount=vcount+1
        else:
            consonant+=ch
            ccount=ccount+1
print("vowels",vowels)
print(vcount)
print("consonant",consonant)
print(ccount)