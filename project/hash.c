#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void print_hash(const char *algorithm, const unsigned char *digest, unsigned int length) {
    printf("%s: ", algorithm);
    for (unsigned int i = 0; i < length; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

void hash_input(const char *input, const char *algorithm) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    md = EVP_get_digestbyname(algorithm);
    if (!md) {
        printf("Unknown message digest %s\n", algorithm);
        exit(1);
    }

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input, strlen(input));
    EVP_DigestFinal_ex(mdctx, digest, &digest_len);
    EVP_MD_CTX_free(mdctx);

    print_hash(algorithm, digest, digest_len);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <algorithm> <input>\n", argv[0]);
        return 1;
    }

    const char *algorithm = argv[1];
    const char *input = argv[2];

    OpenSSL_add_all_digests();

    hash_input(input, algorithm);

    EVP_cleanup();
    return 0;
}
