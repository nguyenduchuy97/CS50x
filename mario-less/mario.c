#include <cs50.h>
#include <stdio.h>

void print_row(int n);
int main(void)
{

int num;
    do
    {
        num = get_int("Height: ");
    }
    while(num <= 0);
    print_row(num);
}

void print_row(int n)
{
    for(int i=0; i<n;i++)
    {
        printf("#");
    }

}
