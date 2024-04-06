from CS50 import get_int
import re

sum = 0
length = 0
second_digit = 0
digit = 0
booll = False

number = get_string("Number: ")
length = len(number)
int(number)

while number > 99:
    second_digit = rint(number) // 10

while number > 0:
    number %= 10

    if booll is True:
        digit *= 2

        if digit > 9:
            digit = digit % 10 + digit // 10


