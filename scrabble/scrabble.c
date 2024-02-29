#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char alpha[26] = {};
    int point[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    string pl_1 = get_string("Player 1: ");
    string pl_2 = get_string("Player 2: ");
    int len_pl1 = strlen(pl_1);
    int len_pl2 = strlen(pl_2);

    for (int i = 0; i < len_pl1; i++)
    {
        toupper(pl_1[i]);
    }
        for (int i = 0; i < len_pl2; i++)
    {
        toupper(pl_2[i]);
    }


}
