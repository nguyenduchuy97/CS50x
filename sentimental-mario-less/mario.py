height = 0
while True:
    height = int(input("Height: "))
    if height in range(1,9):
        break

for i in range(height):
    for j in range(height):
        if j == 0:
            print("", end="")
        else:
            print((height - j) * " ", end="")
    print((i + 1) * "#")



