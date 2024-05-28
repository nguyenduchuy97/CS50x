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

#### Design Choices

##### Combining `hashlib` and `pycryptodome`
One of the primary design decisions was to combine `hashlib` and `pycryptodome` to leverage the strengths of both libraries. `hashlib` is part of the Python standard library and provides robust implementations of common hashing algorithms. However, its algorithm set is somewhat limited. `pycryptodome` extends the range of available algorithms significantly, including less common ones like `MD2` and `BLAKE2`. This combination ensures that users have access to a comprehensive set of cryptographic hash functions.

##### Command-Line Interface (CLI)
Another key design choice was to implement the program as a command-line tool. The CLI approach makes the tool flexible and easy to use in various environments, including scripts and automation pipelines. The use of `argparse` ensures that the tool can handle multiple input types and provides a user-friendly interface with clear usage instructions.

##### Handling Large Files
When designing the `hash_file` function, special consideration was given to efficiently handle large files. Reading the file in chunks (using `iter(lambda: f.read(4096), b"")`) prevents excessive memory usage, making the tool suitable for hashing files of virtually any size.

#### Usage
The Extended Hashing Program can be used to hash messages and files using a variety of algorithms. Below are some examples of how to use the tool from the command line.

##### Hashing a Message
To hash a message using the `SHA-256` algorithm:`python hasher sha256 -m "Hello, world!"`<br>
If you are using Unix-like you can do as following:<br>
Add executable permission for `hasher` with command: `chmod +x hasher`<br>
Then you can execute the program without preceeding python: `hasher sha256 -m "Hello, world!"`

##### Hashing a File
To hash a file using the SHA-256 algorithm with one of these commands:
To hash a message using the `SHA-256` algorithm:`python hasher sha256 -f path/to/your/file.txt`<br>
If you are using Unix-like you can do as following:<br>
Add executable permission for `hasher` with command: `chmod +x hasher`<br>
Then you can execute the program without preceeding python: `hasher sha256 -f path/to/your/file.txt"`

##### Getting Help
To display the help message and see all available options:
`python hasher -h` or `hasher -h`

#### My words
The Extended Hashing Program is a powerful and flexible tool for generating cryptographic hashes. By combining the capabilities of hashlib and pycryptodome, it offers extensive algorithm support. Its command line interface ensures ease of use in various environments, making it a valuable tool for us. This project demonstrates careful consideration of user needs and efficient handling of different data types, from short messages to large files.
<br>
As I was playing CTF challlenges, I met a lot of them and have to use different tools for different algorithms. So I'm free for those that makes me sick out of its way now. I hope this tool helps someone like me can play CTF with smoothiest experiences.<br>
Thanks for reading.
