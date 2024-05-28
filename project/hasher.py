import hashlib
from Crypto.Hash import (
    MD2, MD4, MD5, SHA1, SHA224, SHA256, SHA384, SHA512, SHA3_224, SHA3_256,
    SHA3_384, SHA3_512, BLAKE2b, BLAKE2s, SHAKE128, SHAKE256, HMAC, CMAC
)

# Mapping algorithm names to their respective functions.
pycryptodome_algorithms = {
    'MD2': MD2, 'MD4': MD4, 'MD5': MD5, 'SHA1': SHA1,
    'SHA224': SHA224, 'SHA256': SHA256, 'SHA384': SHA384,
    'SHA512': SHA512, 'SHA3_224': SHA3_224, 'SHA3_256': SHA3_256,
    'SHA3_384': SHA3_384, 'SHA3_512': SHA3_512, 'BLAKE2b': BLAKE2b,
    'BLAKE2s': BLAKE2s, 'SHAKE128': SHAKE128, 'SHAKE256': SHAKE256,
    'HMAC': HMAC, 'CMAC': CMAC
}

def hash_message(message, algorithm):
    """
    Hash a message using the specified algorithm.

    :param message: The message to hash (string).
    :param algorithm: The hashing algorithm to use (string).
    :return: The hexadecimal hash of the message.
    """
    # Try hashlib first.
    try:
        hash_obj = hashlib.new(algorithm)
        hash_obj.update(message.encode('utf-8'))
        return hash_obj.hexdigest()
    except ValueError:
        pass

    # If hashlib fails, try pycryptodome.
    try:
        if algorithm in pycryptodome_algorithms:
            if algorithm.startswith('SHAKE'):
                hash_obj = pycryptodome_algorithms[algorithm].new(data=message.encode('utf-8'), length=64)
            else:
                hash_obj = pycryptodome_algorithms[algorithm].new(data=message.encode('utf-8'))
            return hash_obj.hexdigest()
        else:
            return f"Algorithm {algorithm} is not supported."
    except Exception as e:
        return str(e)

def main():
    # Get the list of available algorithms from both libraries.
    hashlib_algorithms = hashlib.algorithms_available
    pycryptodome_algorithms_list = list(pycryptodome_algorithms.keys())
    all_algorithms = sorted(set(hashlib_algorithms).union(pycryptodome_algorithms_list))

    print("Available algorithms:", ", ".join(all_algorithms))

    # Get user input for the message and algorithm.
    message = input("Enter the message to hash: ")
    algorithm = input("Enter the hashing algorithm to use: ")

    # Hash the message using the specified algorithm
    hashed_message = hash_message(message, algorithm)
    print(f"Hashed message using {algorithm}: {hashed_message}")

if __name__ == "__main__":
    main()
