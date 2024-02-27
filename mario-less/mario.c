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
    while(num <= 0);
    for(int i=0;i<num;i++)
    {
        printf(" ");
    }
}

void print_row(int bricks)
{
    for(int i=0; i<n;i++)
    {
        printf("#");
    }

}
