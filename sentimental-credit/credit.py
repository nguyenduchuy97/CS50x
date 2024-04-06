from CS50 import get_int
import re

sum = 0
length = 0
second_digit = 0

number = get_int("Number: ")

while number > 99:
    second_digit = round(number / 10)

length = len(number)
