#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);
int main(void)
{

    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num < 1);
    for (int i = 0; i < num; i++)
    {
        print_row(num - i, i + 1);
    }
}

void print_row(int spaces, int bricks)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
    printf("\n");
}
