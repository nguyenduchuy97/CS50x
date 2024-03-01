#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]);
    int l = strlen(argv[1]);

    // Make sure every character in argv[1] is a digit
    for (int x = 0; x < l; x++)
    {
        if (!isdigit(argv[1][x]) || k < 0)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    // Prompt user for plaintext
    string p = get_string("plaintext:  ");
    int len = strlen(p);

    // For each character in the plaintext:
    for (int i = 0; i < len; i++)
    {
        // Rotate the character if it's a letter
        p[i] = rotate(p[i], k);
    }
    printf("ciphertext: %s\n", p);
    return 0;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = (c - 'A' + n) % 26 + 'A';
        }
        else
        {
            c = (c - 'a' + n) % 26 + 'a';
        }
        return c;
    }
    else
    {
        return c;
    }
}
