# hangman

import random

fruit = [
    "apple", "mango", "guava", "kiwi", "custard apple",
    "grapes", "cherry", "blue berry", "apricot", "peach",
    "pomegranate", "pine apple", "avocado", "star fruit",
    "banana", "straw berry"
]

# Select random fruit
word = random.choice(fruit)

# Create hidden display
display = []

for ch in word:
    if ch == " ":
        display.append(" ")
    else:
        display.append("_")

chances = 6

print("=============================")
print("      HANGMAN GAME")
print("=============================")
print("Guess the Fruit Name")

while chances > 0 and "_" in display:

    print("\nWord:", " ".join(display))
    print("Chances Left:", chances)

    guess = input("Enter a letter: ").lower()

    found = False

    for i in range(len(word)):
        if word[i] == guess and display[i] == "_":
            display[i] = guess
            found = True

    if found:
        print("Correct Guess!")
    else:
        chances -= 1
        print("Wrong Guess!")

# Final Result
if "_" not in display:
    print("\nCongratulations! You Won!")
else:
    print("\nGame Over! You Lost!")

print("The Correct Word is:", word)