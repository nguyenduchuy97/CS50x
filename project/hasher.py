import hashlib
import argparse
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

def hash_file(file_path, algorithm):
    """
    Hash a file using the specified algorithm.

    :param file_path: The path to the file to hash (string).
    :param algorithm: The hashing algorithm to use (string).
    :return: The hexadecimal hash of the file.
    """
    try:
        hash_obj = hashlib.new(algorithm)
        with open(file_path, 'rb') as f:
            for chunk in iter(lambda: f.read(4096), b""):
                hash_obj.update(chunk)
        return hash_obj.hexdigest()
    except ValueError:
        pass

    # If hashlib fails, try pycryptodome.
    try:
        if algorithm in pycryptodome_algorithms:
            if algorithm.startswith('SHAKE'):
                hash_obj = pycryptodome_algorithms[algorithm].new(length=64)
            else:
                hash_obj = pycryptodome_algorithms[algorithm].new()
            with open(file_path, 'rb') as f:
                for chunk in iter(lambda: f.read(4096), b""):
                    hash_obj.update(chunk)
            return hash_obj.hexdigest()
        else:
            return f"Algorithm {algorithm} is not supported."
    except Exception as e:
        return str(e)

def main():
    # Command-line argument parsing.
    parser = argparse.ArgumentParser(description='Hashing tool supporting various algorithms.')
    parser.add_argument('algorithm', type=str, help='The hashing algorithm to use.')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-m', '--message', type=str, help='The message to hash.')
    group.add_argument('-f', '--file', type=str, help='The file path to hash.')

    args = parser.parse_args()

    # Get the list of available algorithms from both libraries.
    hashlib_algorithms = hashlib.algorithms_available
    pycryptodome_algorithms_list = list(pycryptodome_algorithms.keys())
    all_algorithms = sorted(set(hashlib_algorithms).union(pycryptodome_algorithms_list))

    if args.algorithm not in all_algorithms:
        print(f"Algorithm {args.algorithm} is not available. Available algorithms are: {', '.join(all_algorithms)}")
        return

    if args.message:
        # Hash the message using the specified algorithm.
        hashed_message = hash_message(args.message, args.algorithm)
        print(f"Hashed message using {args.algorithm}: {hashed_message}")
    elif args.file:
        # Hash the file using the specified algorithm
        hashed_file = hash_file(args.file, args.algorithm)
        print(f"Hashed file using {args.algorithm}: {hashed_file}")

if __name__ == "__main__":
    main()
