#include <cs50.h>
#include <stdio.h>

void pyramid(int n);
int main(void)
{

int num;
    do
    {
        num = get_int("Height: ");
    }
    while(num <= 0);
    pyramid(num);
}

void pyramid(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j=0; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
