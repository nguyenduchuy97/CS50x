#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    (
        printf("Usage %s key\n", argv[0]);
        return 1;
    )
    int len_k = strlen(argv[1]);
    for (int i = 0; i < len_k; i++)
    {
        if (!isalpha(argv[1][i]) || len_k != 26)
        {
            printf("The key must contains 26 characters.\n");
            return 1;
        }
    }
    string p = get_string("plaintext:  ");
    int len_p = strlen(p);

    

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
