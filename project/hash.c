#include <openssl/md5.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

// Function to print the hash
void print_hash(unsigned char *hash, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to hash using MD5
void hash_md5(const char *data) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)data, strlen(data), hash);
    printf("MD5: ");
    print_hash(hash, MD5_DIGEST_LENGTH);
}

// Function to hash using SHA1
void hash_sha1(const char *data) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)data, strlen(data), hash);
    printf("SHA1: ");
    print_hash(hash, SHA_DIGEST_LENGTH);
}

// Function to hash using SHA256
void hash_sha256(const char *data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data, strlen(data), hash);
    printf("SHA256: ");
    print_hash(hash, SHA256_DIGEST_LENGTH);
}

// Function to hash using SHA512
void hash_sha512(const char *data) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512((unsigned char*)data, strlen(data), hash);
    printf("SHA512: ");
    print_hash(hash, SHA512_DIGEST_LENGTH);
}

int main() {
    const char *data = "Hello, world!";
    printf("Hashing the string: %s\n", data);

    hash_md5(data);
    hash_sha1(data);
    hash_sha256(data);
    hash_sha512(data);

    return 0;
}
