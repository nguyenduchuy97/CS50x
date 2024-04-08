from CS50 import get_int
import re

sum = 0
length = 0
two_digit = 0
digit = 0
step = False

number = get_string("Number: ")
length = len(number)
int(number)

while number > 99:
    two_digit = number // 10

while number > 0:
    number %= 10

    if step is True:
        digit *= 2

        if digit > 9:
            digit = digit % 10 + digit // 10

        sum += digit
        number //= 10
        step = not step

if length == 15
