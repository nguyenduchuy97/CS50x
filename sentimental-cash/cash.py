from cs50 import get_float

coins = 0
dollars = 0.0
while True:
    dollars = get_float("Change owed: ")

    if dollars > -1:
        break
dollars = dollars * 100

while dollars > 0:
    if dollars > 24:
        dollars -= 25
        coins += 1
    elif dollars > 9:
        dollars -= 10
        coins += 1
    elif dollars > 4:
        dollars -= 5
        coins += 1
    elif dollars > 0:
        dollars -= 1
        coins += 1

print(coins)
