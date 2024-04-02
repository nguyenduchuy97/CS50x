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
    
