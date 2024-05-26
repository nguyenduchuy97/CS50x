from art import text2art
import sys


# Generate ASCII art text
greet1 = text2art("Hash Generator by")
greet2 = text2art(" Huy", font='block', chr_ignore=True)

# Print the ASCII art
print(greet1)
print(greet2)


def main():
    while True:
        print("""Choose one of the hash algorithms:

SHA-1"___"SHA-224"___"SHA-256"___"SHA-384"___"SHA512"
"SHA3_224"___"SHA3_256"___"SHA3_384"___"SHA3_512"

    *! Press "Ctrl + C" or "exit()" to quit.
              """)
        hash_type = input("Choose a hash algorithm: ").lower()

        if hash_type == 'exit()':
            break

if __name__ == '__main__':
    main()
