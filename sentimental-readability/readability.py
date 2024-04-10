from cs50 import get_string
import math

text = get_string("Text: ")
length = len(text)
letters = 0
words = 0
sentences = 0

for i in text:
    if i.isalpha():
        letters += 1
    elif i.isspace():
        words += 1
    elif i in [".", "!", "?"]:
        sentences += 1

L = letters / words * 100.0
S = sentences / words * 100.0
grade = 0.0588 * L - 0.296 * S - 15.8

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {math.floor(grade)}")
