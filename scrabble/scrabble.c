#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string player);

int main(void)
{
    // Prompt the user for two words
    string pl_1 = get_string("Player 1: ");
    string pl_2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(pl_1);
    int score2 = compute_score(pl_2);

    // Print the winner
    if (score1 - score2 > 0)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 - score2 < 0)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute and return score for word
int compute_score(string player)
{
    string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0;
    int len = strlen(player);
    char up[len];

    for (int i = 0; i < len; i++)
    {
        up[i] = toupper(player[i]);

        for (int n = 0; n < 26; n++)
        {
            if ((up[i] - al[n]) == 0)
            {
                sum += points[n];
            }
            else
            {
                sum += 0;
            }
        }
    }

    return sum;
}
