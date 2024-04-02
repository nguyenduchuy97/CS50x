height = 0

while True:
    try:
        # Get input
        height = input("Height: ")
        # Take the positive integer between 1 to 8
        if height in range(1,9):
            break
    except:
        continue

for i in range(height):
    # Print spaces to right-align the pyramid
    print((height - i - 1) * " ", end="")

    # Print '#' characters for the pyramid
    print((i + 1) * "#")
