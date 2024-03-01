#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    int k = atoi(argv[1]);

    if (argc == 2 && isdigit(*argv[1]) && k >= 0)
    {
        string p = get_string("plaintext:  ");
        int len = strlen(p);
        char ci[len];
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        ci = rotate(p[i], k);
    }
    printf("ciphertext: %s", ci);
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
