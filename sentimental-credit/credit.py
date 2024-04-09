from cs50 import get_int
from cs50 import get_string

sum = 0
length = 0
step = False

card = get_string("Number: ")
length = len(card)
number = int(card)
two_digit = int(card)

while True:
    if two_digit < 100:
        break
    two_digit //= 10

while number > 0:

    digit = number % 10

    if step is True:
        digit *= 2

        if digit > 9:
            digit = digit % 10 + digit // 10

        sum += digit
        number //= 10
        step = not step

if length == 15 and (two_digit in [34,37]) and (sum % 10 == 0):
    print("AMEX")

elif length == 16 and (two_digit in [51, 52, 53, 54,55]) and (sum % 10 == 0):
    print("MASTERCARD")

elif (length in [13,16]) and (two_digit in range(40,50)) and (sum % 10 == 0):
    print("VISA")

else:
    print("INVALID")
