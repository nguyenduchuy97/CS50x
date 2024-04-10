from cs50 import get_string
import panda as pd

text = get_string("Text: ")
length = len(text)
letters = 0
words = 0
sentences = 0

for i in text:
    if text[i] == None:
        break
    elif text.ascii_letters():
        letters += 1
    elif text.whitespace():
        words += 1
    elif 
