from cs50 import get_string

text = get_string("Text: ")
length = len(text)
letters = 0
words = 0
sentences = 0

for i in text:
    if i.index() == Length:
        break
    elif i.ascii_letters():
        letters += 1
    elif i.whitespace():
        words += 1
    elif i in [".", "!", "?"]:
        sentences += 1
grade = 0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8

if grade < 0:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
