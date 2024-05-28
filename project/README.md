# Extended Hashing Generator
#### Video Demo:  <URL HERE>
#### Description: Extended Hashing Generator
#### Overview
The Extended Hashing Program is a versatile command-line tool designed to hash both messages and files using a wide variety of cryptographic hashing algorithms. It combines the capabilities of Python's built-in `hashlib` library and the `pycryptodome` library to provide extensive support for numerous hashing algorithms. This tool is ideal for anyone like me who like playing CTF challenges that required verious hashing algorithm types, because really don't like have to install a lot of tools for different algorithms so I combine them all together for our convenience.

#### Project Structure
`hasher`
This is the main script of the project. It handles command-line arguments, processes input data, and generates hashes using the specified algorithms. The script includes the following key components:

1. Import Statements:

    - `hashlib` for built-in hashing algorithms.
    - `argparse` for parsing command-line arguments.
    - Various hashing modules from `pycryptodome for` additional algorithm support.

2. Algorithm Mapping:
    - A dictionary (`pycryptodome_algorithms`) that maps algorithm names to their respective classes from `pycryptodome`.

3. Function `hash_message`:

    - Takes a message (string) and an algorithm (string) as input.
    - Attempts to create a hash using `hashlib` first. If unsuccessful, it tries `pycryptodome`.
    - Returns the hexadecimal digest of the hashed message.

4. Function hash_file:

    - Takes a file path (string) and an algorithm (string) as input.
    - Reads the file in chunks to handle large files efficiently.
    - Attempts to create a hash using hashlib first. If unsuccessful, it tries pycryptodome.
    - Returns the hexadecimal digest of the hashed file contents.

5. Function main:

    - Uses argparse to handle command-line arguments.
    - Combines available algorithms from hashlib and pycryptodome.
    - Validates the specified algorithm.
    - Calls hash_message or hash_file based on the input type (message or file).
    - Prints the resulting hash to the console.


