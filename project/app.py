from art import text2art
import sys


# Generate ASCII art text
greet1 = text2art("Hash Generator by")
greet2 = text2art(" Huy", font='block', chr_ignore=True)

# Print the ASCII art
print(greet1)
print(greet2)


def main(hash):
    if not hash:
        print("Choose one of the hash algorithms.\nMD5, SHA1, SHA")
