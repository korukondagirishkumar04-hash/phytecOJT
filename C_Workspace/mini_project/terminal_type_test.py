#Python program that measures the time taken by a user to type a given paragraph

import time

# Paragraph to type
paragraph = """Python is a high-level programming language.
It is easy to learn and widely used for web development"""

print("********** Typing Speed Test **********")
print("\nType the following paragraph exactly as shown:\n")
print(paragraph)

input("\nPress Enter when you are ready to start...")

# Start timer
start_time = time.time()

# User input
typed_text = input("\nStart typing:\n")

# End timer
end_time = time.time()

# Calculate time
time_taken = end_time - start_time

print("\n----------- Result -----------")
print(f"Time Taken : {time_taken:.2f} seconds")

# Check correctness
if typed_text == paragraph:
    print("Status : Correctly Typed")
else:
    print("Status : There are mistakes in your typing.")