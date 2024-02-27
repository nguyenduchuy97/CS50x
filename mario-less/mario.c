#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);
int main(void)
{

int num;
    do
    {
        num = get_int("Height: ");
    }
    while(num < 1);
    for(int i=0;i<num;i++)
    {
        print_row(num-1);
        printf("#");
    }
    printf("\n");
}

void print_row(int bricks)
{
    for(int a=bricks; 0<a; a--)
    {
        printf(" ");
    }
}
