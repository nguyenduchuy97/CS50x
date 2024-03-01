#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, string argv[])
{
    if (argc != 2)
    (
        printf("Usage %s key\n", argv[0]);
        return 1;
    )
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(argv[1][i]) || len != 26)
        {
            printf("The key must contains 26 characters.\n");
            return 1;
        }
    }

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
