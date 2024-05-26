from art import text2art
import hashlib

# Generate ASCII art text
greet1 = text2art("Hash Generator by")
greet2 = text2art(" Huy", font='block', chr_ignore=True)

# Print the ASCII art
print(greet1)
print(greet2)


def main():
    alg  = ["SHA_1", "SHA_224", "SHA_256", "SHA_384", "SHA512", "SHA3_224", "SHA3_256", "SHA3_384", "SHA3_512"]
    while True:
        print("""Choose one of the hash algorithms: SHA_1 , SHA_224 , SHA_256 , SHA_384 , SHA512 , SHA3_224 , SHA3_256 , SHA3_384 , SHA3_512

!!! Press "Ctrl + C" or "exit()" to quit.
              """)

        hash_type = input("Choose a hash algorithm: ").upper()

        if hash_type == 'exit()':
            break

        if hash_type in alg:
            text = input("Input your password")
            if len(text) > 50 or len(text) < 1:
                print("Your password length between 1 to 50 characters")
            hashee = hash_generator(hash_alg, text)
            print(hashee)

def hash_generator(hash_alg, text):
    
    pass

if __name__ == '__main__':
    main()
