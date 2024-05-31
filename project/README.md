# Extended Hashing Generator
#### Video Demo:  <URL HERE>
#### Description: Extended Hashing Generator
#### Overview
This project consists of a command-line program written in C that provides various hashing functionalities. The program allows users to compute the hash of a file, input from standard input, or a provided string using different cryptographic hash algorithms. Additionally, it includes a `Makefile` for building the program.

#### Files
##### hash.c
`hash.c` is the main source file of the program. It contains the implementation of the hashing functionalities, including hashing a file (hash_file), hashing input from standard input (`hash_stdin`), and hashing a provided string (`hash_string`). The file also defines helper functions for printing hashes (`print_hash`) and displaying usage information (`print_usage`). Furthermore, the `main` function orchestrates the execution flow based on the command-line arguments provided by the user.

##### Makefile
The `Makefile` automates the compilation and linking process of the program. It defines rules for compiling individual source files, linking object files to create the executable, and cleaning up build artifacts. Additionally, the `Makefile` specifies compiler flags (`CFLAGS`) and libraries to link against (`LIBS`). This file simplifies the build process and ensures consistency across different platforms.

#### Design Choices

##### Supporting Multiple Hashing Algorithms
The program supports a wide range of cryptographic hash algorithms, including MD2, MD4, MD5, SHA-1, SHA-2 (224, 256, 384, 512), SHA-3 (224, 256, 384, 512), SHAKE128, SHAKE256, BLAKE2B512, and BLAKE2S256. This choice offers users flexibility in selecting the appropriate algorithm based on their security requirements and performance considerations.

##### Handling Input Flexibility
The program provides flexibility in input sources, allowing users to hash data from a file, standard input, or a provided string. This design choice accommodates various use cases, such as hashing large files, piping data from other commands, or hashing short strings directly from the command line. Additionally, the program handles input errors gracefully, providing informative error messages to the user.

##### Modular Code Structure
The code is organized into modular functions, each responsible for a specific hashing task. This modular structure enhances readability, maintainability, and extensibility of the codebase. By encapsulating functionality into smaller functions, it becomes easier to understand, test, and modify individual components without affecting the overall behavior of the program.

##### Makefile for Build Automation
The inclusion of a Makefile simplifies the build process and ensures reproducible builds across different environments. By defining rules for compiling source files and linking dependencies, the Makefile automates the build workflow, reducing the risk of manual errors and inconsistencies. Additionally, the Makefile enables incremental builds, avoiding unnecessary recompilation of unchanged source files.

#### Usage
##### Hashing a Message
! You should move in the directory where hasher is locating to execute the syntax command as instruction below.
To hash a message using the `SHA-256` algorithm:`./hasher sha256 "Hello, world!"`<br>

##### Hashing a File
! You should move in the directory where hasher is locating to execute the syntax command as instruction below.
To hash a message using the `SHA-256` algorithm:`./hasher sha256 path/to/your/file.txt`<br>

To hash a file using the `SHA-256` algorithm with one of these commands:
To hash a message using the `SHA-256` algorithm:`python hasher sha256 -f path/to/your/file.txt`<br>
If you are using Unix-like you can do as following:<br>
Add executable permission for `hasher` with command: `chmod +x hasher`<br>
Then you can execute the program without preceeding python: `hasher sha256 -f path/to/your/file.txt"`

##### Getting Help
To display the help message and see all available options:
`python hasher -h` or `hasher -h`

#### My words
This is an extended hashing program I build for my own and also for you all. It is a powerful and flexible tool for generating cryptographic hashes. By combining the capabilities of `hashlib` and `pycryptodome`, it has extensive algorithm support. Its command-line interface ensures ease of use in various environments, making it a valuable tool for us. This project demonstrates careful consideration of users needs and efficient handling of different data types, from short messages to large files.
<br>
As I was playing CTF challlenges, I met a lot of them and have to use different tools for different algorithms. So I'm free for those that makes me sick out of its way now. I hope this tool helps someone like me can play CTF with smoothiest experiences.<br>
Thanks for reading.
