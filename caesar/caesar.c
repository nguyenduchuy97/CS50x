#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int l = strlen(argv[1]);
    int k = atoi(argv[1]);

    for (int x = 0; x < l; x++)
    {
        if (!isdigit(argv[1][x]) || k < 0)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    string p = get_string("plaintext:  ");
    int len = strlen(p);

    for (int i = 0; i < len; i++)
    {
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
