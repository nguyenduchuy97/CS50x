height = 0
while True:
    height = int(input("Height: "))
    if height in range(1,9):
        break

for i in range(height):
    for j in range(height):
        print((height - j - 1) * " ", end="")
    print((i + 1) * "#")



