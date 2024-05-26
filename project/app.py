from art import text2art
import sys


# Generate ASCII art text
greet1 = text2art("Hash Generator by")
greet2 = text2art(" Huy", font='block', chr_ignore=True)

# Print the ASCII art
print(greet1)
print(greet2)


def main(hashee):
    len_hash = len(hashee)
    while not hashee:
        print("""Choose one of the hash algorithms.\n
              SHA-1, SHA-224, SHA-256, SHA-384,SHA512, SHA3_224,
              SHA3_256, SHA3_384, SHA3_512""")
        
