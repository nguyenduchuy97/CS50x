#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

float Coleman_Liau(float L, float S);

int main(void)
{
	int sentences = 0;
	int letters = 0;
	int words = 0;
	float L;
	float S;

// User input
	string input = get_string("Text: ");
	int len = strlen(input);
    printf("Length: %i\n", len);

// Find words, leters, sentences.
	for (int i = 0; i < len; i++)
	{
		if (isspace(input[i]))
		{
			words += 1;
		}
        else if (ispunct(input[len]))
			{
                printf("Plus last word\n");
				words += 1;
                sentences += 1;
			}
		// Find letters
		else if (isalnum(input[i]))
		{
			letters += 1;
		}
		// Find sentences
		else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
		{
			sentences += 1;
		}
		else if ( words % 100 == 0)
		{
			// L is the average number of letters per 100 words in the text
			L = (float) letters / 100.00;

			// S is the average number of sentences per 100 words in the text.
			S = (float) sentences / 100.00;
		}
		else
		{
			printf("Something went wrong!\n");
		}
	}
    printf("\nLetters: %i, Words: %i, Sentences: %i, L: %f, S: %f\n", letters, words, sentences, L, S);
// Print the Grade X
	int X = (int) round(Coleman_Liau(L,S));
    printf("\nX: %i\n", X);
	if (X < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (X > 15)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade %i\n", X);
	}

}

// Coleman-Liau's algorithm.
float Coleman_Liau(float L, float S)
{
	float index = 0.0588 * L - 0.296 * S - 15.8;
	return index;
}
