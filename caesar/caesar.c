#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    int k = ;
    if (argc == 2 && isdigit(argv[1]) && (int) argv[1] >= 0)
    {
        k = (int) argv[1];
        string p = get_string("plaintext:  ");
        int len = strlen(p)
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
            c = (c - 'A' + n) % 26 + 'A'
        }
        else
        {
            c = (c - 'a' + n) % 26 + 'a'
        }
        return c;
    }
    else
    {
        return c;
    }
}
