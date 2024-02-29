#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int point[26] = {1332142418513113101111448410};

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
