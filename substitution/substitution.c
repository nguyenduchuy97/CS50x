#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, string n);

int main(int argc, string argv[])
{
    // Only accept 2 arguments
    if (argc != 2)
    {
        printf("Usage %s key\n", argv[0]);
        return 1;
    }

    int len_k = strlen(argv[1]);

    // Only accept 26 characters and alphabet characters.
    if (len_k != 26)
    {
        printf("The key must contains 26 characters.\n");
        return 1;
    }

    for (int x = 0; x < len_k; x++)
    {

        if (!isalpha(argv[1][x]))
        {
            printf("The key must contains only alphabet characters.\n");
            return 1;
        }

        for (int j = x + 1; j < len_k; j++)
        {
            if (argv[1][x] == argv[1][j])
            {
                printf("The key must not contains duplicate characters.\n");
                return 1;
            }
        }
    }
    // Input plain text.
    string p = get_string("plaintext:  ");
    int len_p = strlen(p);

    for (int i = 0; i < len_p; i++)
    {
        // Substitution process with the key
        p[i] = rotate(p[i], argv[1]);
    }

    printf("ciphertext: %s\n", p);
    return 0;
}

char rotate(char c, string n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = toupper(n[c - 'A']);
        }
        else
        {
            c = tolower(n[c - 'a']);
        }
        return c;
    }
    else
    {
        return c;
    }
}
