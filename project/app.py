from art import text2art
import hashlib

# Generate ASCII art text
greet1 = text2art("Hash Generator by")
greet2 = text2art(" Huy", font='block', chr_ignore=True)

# Print the ASCII art
print(greet1)
print(greet2)


def main():
    alg  = ["MD5", "SHA_1", "SHA_224", "SHA_256", "SHA_384", "SHA512", "SHA3_224", "SHA3_256", "SHA3_384", "SHA3_512", "SHAKE_128", "SHAKE_256"]
    while True:
        print("""Choose one of the hash algorithms: MD5 , SHA_1 , SHA_224 , SHA_256 , SHA_384 , SHA512 , SHA3_224 , SHA3_256 , SHA3_384 , SHA3_512
            SHAKE_128 , SHAKE_256
!!! Press "Ctrl + C" or "exit()" to quit.
              """)

        hash_type = input("Choose a hash algorithm: ").upper()

        if hash_type == 'exit()':
            break

        if hash_type in alg:
            text = input("Input your password: ")
            if len(text) > 50 or len(text) < 1:
                print("Your password length between 1 to 50 characters")
            if hash_type == "SHAKE_128" or hash_type == "SHAKE_128":
                length = int(input("Input length hash: "))
                if length < 0:
                    print("the length must be between 1 - 255 chars")

                hashee = hash_generator(hash_type, text, length)
                print(f"{hash_type} hash: {hashee}\n Length: {length}")
                break

            hashe = hash_generator(hash_type, text)
            print(f"{hash_type} hash: {hashe}")
        else:
            print("Invalid hash type.")
        break

def hash_generator(hash_alg, text, length):

    if hash_alg == 'MD5':
        return hashlib.md5(text.encode()).hexdigest()

    elif hash_alg == 'SHA_1':
        return hashlib.sha1(text.encode()).hexdigest()

    elif hash_alg == 'SHA_224':
        return hashlib.sha224(text.encode()).hexdigest()

    elif hash_alg == 'SHA_256':
        return hashlib.sha256(text.encode()).hexdigest()

    elif hash_alg == 'SHA_384':
        return hashlib.sha384(text.encode()).hexdigest()

    elif hash_alg == 'SHA512':
        return hashlib.sha512(text.encode()).hexdigest()

    elif hash_alg == 'SHA3_224':
        return hashlib.sha3_224(text.encode()).hexdigest()

    elif hash_alg == 'SHA3_256':
        return hashlib.sha3_256(text.encode()).hexdigest()

    elif hash_alg == 'SHA3_384':
        return hashlib.sha3_384(text.encode()).hexdigest()

    elif hash_alg == 'SHA3_512':
        return hashlib.sha3_512(text.encode()).hexdigest()

    elif hash_alg == 'SHAKE_128':
        return hashlib.shake_128(text.encode()).hexdigest(length)

    elif hash_alg == 'SHAKE_256':
        return hashlib.shake_256(text.encode()).hexdigest(length)

if __name__ == '__main__':
    main()
