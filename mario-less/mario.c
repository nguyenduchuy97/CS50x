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
    while(num < 1);
    for(int i=0;i<num;i++)
    {
        print_row();
    }
}

void print_row(int spaces, int bricks)
{
    for(int a=0; a< spaces; a++)
    {
        printf(' ');
    }
    for(int i=0; i< bricks;i++)
    {
        printf("#");
    }
    printf("\n");
}
