from cs50 import get_float

coins = 0
cents = 0.0
while True:
    cents = get_float("Change owed: ")

    if cents > -1:
        break

while cents > 0:
    if cents > 24:
        cents -= 25
        coins += 1
    elif cents > 9:
        cents -= 10
        coins += 1
    elif cents > 4:
        cents -= 5
        coins += 1
    elif cents > 0:
        cents -= 1
        coins += 1

print(coins)
