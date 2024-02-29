#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int compute_score(string player);

int main(void)
{
    string pl_1 = get_string("Player 1: ");
    string pl_2 = get_string("Player 2: ");

    int score1 = compute_score(pl_1);
    int score2 = compute_score(pl_2);
    printf("1: %i", score1);
    printf("2: %i", score2);

}

int compute_score(string player)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //{"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int sum = 0;
    int len = strlen(player);
    char up[len];
    int n = 0;

    for (int i = 0; i < len; i++)
    {
        up[i] = toupper(player[i]);
        while (n < 26)
        {
            if ((up[i] - points[n] < 25) || (up[i] - points[n] > -1))
            {
                if ((up[i] - points[n] == 0))
                {
                    printf("Point: %i", points[n]);
                    sum += points[n];

                }
                else
                {
                    printf("%c\n",alpha[n]);
                    sum += 0;
                    n++;
                }

            }
        }

    }

    return sum;
}

