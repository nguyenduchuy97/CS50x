from cs50 import get_string
import panda as pd

text = get_string("Text: ")
length = len(text)
letters = 0
words = 0
sentences = 0

for i in text:
    if i == length:
        break
    elif text[i].ascii_letters():
        letters += 1
    elif text[i].whitespace():
        words += 1
    elif text[i] in [".", "!", "?"]:
        sentences += 1
grade = 0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8

if grade < 0:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
