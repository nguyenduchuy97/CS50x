height = 0
while True:
    # Get input
    height = int(input("Height: "))

    # positive integer between 1 and 8, inclusive.
    if height in range(1, 9):
        break

for i in range(height):
    # Print spaces to right-align the pyramid
    print((height - i - 1) * " ", end="")

    # Print '#' characters for the pyramid
    print((i + 1) * "#")
