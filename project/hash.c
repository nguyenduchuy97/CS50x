#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Set buffer size for reading an input file.
#define BUFFER_SIZE 4096

// Print output of a hashed result.
void print_hash(const char *algorithm, const unsigned char *digest, unsigned int length) {
    printf("%s: ", algorithm);
    for (unsigned int i = 0; i < length; i++) {
        // The %02x is the output for 
        printf("%02x", digest[i]);
    }
    printf("\n");
}

void hash_file(const char *filename, const char *algorithm) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    FILE *file;

    file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    md = EVP_get_digestbyname(algorithm);
    if (!md) {
        printf("Unknown message digest %s\n", algorithm);
        fclose(file);
        exit(1);
    }

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        EVP_DigestUpdate(mdctx, buffer, bytes_read);
    }

    EVP_DigestFinal_ex(mdctx, digest, &digest_len);
    EVP_MD_CTX_free(mdctx);
    fclose(file);

    print_hash(algorithm, digest, digest_len);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <algorithm> <filename>\n", argv[0]);
        return 1;
    }

    const char *algorithm = argv[1];
    const char *filename = argv[2];

    OpenSSL_add_all_digests();

    hash_file(filename, algorithm);

    EVP_cleanup();
    return 0;
}
