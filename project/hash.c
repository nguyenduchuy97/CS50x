#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Macro for buffer size to read file chunks
#define BUFFER_SIZE 4096

// Function to print the computed hash in hexadecimal format
void print_hash(const char *algorithm, const unsigned char *digest, unsigned int length) {
    printf("%s: ", algorithm);
    for (unsigned int i = 0; i < length; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

// Function to hash the contents of a file
void hash_file(const char *filename, const char *algorithm) {
    EVP_MD_CTX *mdctx;  // Message Digest Context
    const EVP_MD *md;   // Message Digest Method
    unsigned char digest[EVP_MAX_MD_SIZE];  // Array to store the resulting hash
    unsigned int digest_len;  // Length of the resulting hash
    unsigned char buffer[BUFFER_SIZE];  // Buffer to read file chunks
    size_t bytes_read;  // Number of bytes read from the file
    FILE *file;  // File pointer

    // Open the file in binary read mode
    file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    // Get the message digest method for the specified algorithm
    md = EVP_get_digestbyname(algorithm);
    if (!md) {
        printf("Unknown message digest %s\n", algorithm);
        fclose(file);
        exit(1);
    }

    // Initialize the message digest context
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);

    // Read the file in chunks and update the hash
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        EVP_DigestUpdate(mdctx, buffer, bytes_read);
    }

    // Finalize the hash computation
    EVP_DigestFinal_ex(mdctx, digest, &digest_len);
    EVP_MD_CTX_free(mdctx);
    fclose(file);

    // Print the resulting hash
    print_hash(algorithm, digest, digest_len);
}

// Function to hash the input from standard input (stdin)
void hash_stdin(const char *algorithm) {
    EVP_MD_CTX *mdctx;  // Message Digest Context
    const EVP_MD *md;   // Message Digest Method
    unsigned char digest[EVP_MAX_MD_SIZE];  // Array to store the resulting hash
    unsigned int digest_len;  // Length of the resulting hash
    unsigned char buffer[BUFFER_SIZE];  // Buffer to read input chunks
    size_t bytes_read;  // Number of bytes read from stdin

    // Get the message digest method for the specified algorithm
    md = EVP_get_digestbyname(algorithm);
    if (!md) {
        printf("Unknown message digest %s\n", algorithm);
        exit(1);
    }

    // Initialize the message digest context
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);

    // Read stdin in chunks and update the hash
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, stdin)) != 0) {
        EVP_DigestUpdate(mdctx, buffer, bytes_read);
    }

    // Finalize the hash computation
    EVP_DigestFinal_ex(mdctx, digest, &digest_len);
    EVP_MD_CTX_free(mdctx);

    // Print the resulting hash
    print_hash(algorithm, digest, digest_len);
}

// Function to display the usage of the program
void print_usage(const char *program_name) {
    printf("Usage: %s <algorithm> <filename>\n", program_name);
    printf("       %s <algorithm> - (to hash from standard input)\n", program_name);
    printf("Available algorithms:\n");
    printf("  md2, md4, md5, sha1, sha224, sha256, sha384, sha512\n");
    printf("  sha3-224, sha3-256, sha3-384, sha3-512, shake128, shake256\n");
    printf("  blake2b512, blake2s256\n");
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    const char *algorithm = argv[1];
    const char *filename = argv[2];

    // Initialize OpenSSL's digest algorithms
    OpenSSL_add_all_digests();

    // Check if the input is from stdin
    if (strcmp(filename, "-") == 0) {
        hash_stdin(algorithm);
    } else {
        hash_file(filename, algorithm);
    }

    // Clean up OpenSSL
    EVP_cleanup();

    return 0;
}
