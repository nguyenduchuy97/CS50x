from cs50 import get_string
from math import floor

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
grade = 0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8
floor(grade)

if grade < 0:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
