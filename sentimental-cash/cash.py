from cs50 import get_float

cents = 0.0
while True:
    cents = get_float("Change owed: ")

    if cents >= 0:
        break

def quaters(cent):
    quater = 0
    while cent > 24:
        cent -= 25.0
        quater += 1
    return quater

def dimes(cent):
    dime = 0
    while cent > 9:
        cent -= 10.0
        dime += 1
    return dime

def nickels(cent):
    nickel = 0
    while cent > 4:
        cent -= 5.0
        nickel += 1
    return nickel

def pennies(cent):
    pennie = 0
    while cent > 0:
        cent -= 1.0
        pennie += 1
    return pennie

def main():
    quater = quaters(cent)
    dime = dimes(cent)
    nickel = nickels(cent)
    pennie = pennies(cent)
