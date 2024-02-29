#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int compute_score(string player);

int main(void)
{
    const int N = 26;
    char alpha[N] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
    int points[N] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    string pl_1 = get_string("Player 1: ");
    string pl_2 = get_string("Player 2: ");

    int score1 = compute_score(pl_1);
    int score2 = compute_score(pl_2);

}

int compute_score(string player)
{
    const int N = 26;
    char alpha[N] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int points[N] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    string cap_letters;
    int len = strlen(player);

    for (int i = 0; i < len; i++)
    {
        cap_letters = toupper(pl_1[i]);
        printf("%s", cap_letters);
}
