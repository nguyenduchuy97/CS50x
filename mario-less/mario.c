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
    for(int i; i<n;i++)
    {
        for(int j=0;j<n;n--)
        {
            printf(' ');
        }
        printf("#")
    }
}
