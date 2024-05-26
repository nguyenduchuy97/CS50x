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

                'SHA-1' - 'SHA-224' - 'SHA-256' - 'SHA-384' - 'SHA512'
                'SHA3_224' - 'SHA3_256' - 'SHA3_384' - 'SHA3_512'

    *! Press 'Ctrl + C' or 'exit()' to quit.
              """)
        hash_type = input("Choose a hash algorithm: ").lower()
        if hash_type == 'exit()':
            break

if __name__ == '__main__':
    main()
