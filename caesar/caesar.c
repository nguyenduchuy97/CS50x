#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char argv[])
{
    int k = ;
    if (argc == 2 && isdigit(argv[1]) && (int) argv[1] >= 0)
    {
        k = (int) argv[1];
        string plain = get_string("Plaintext: ");
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

}
