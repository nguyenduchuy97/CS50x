from cs50 import get_string
import math

text = get_string("Text: ")
length = len(text)
letters = 0
words = 0
sentences = 0

for i in text:
    if i == None:
        break
    elif i.isalpha():
        letters += 1
    elif i.isspace():
        words += 1
    elif i in [".", "!", "?"]:
        sentences += 1
L = letters / words * 100
S = sentences / words * 100
grade = 0.0588 * L - 0.296 * S - 15.8
grade = math.floor(grade)

if grade < 0:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
