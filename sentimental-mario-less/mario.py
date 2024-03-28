
def pyramid(space, brick):







def main():
    height = 0
    while True:
        height = int(input("Height: "))
        if height in range(1,9):
            break

    for i in range(height):
        for j in range(height):
            if 
            print((height - j) * " ", end="")
        print((i + 1) * "#")


main()


