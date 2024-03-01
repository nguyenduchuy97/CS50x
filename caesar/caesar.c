#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char argv[])
{
    int key;
    if (argc == 2 && isdigit(argv[1]))
    {
        key = (int) argv[1];
        string plain = get_string("Plaintext: ");
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
    }
    
}
