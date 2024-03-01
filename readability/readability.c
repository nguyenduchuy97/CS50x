#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int Coleman_Liau(double L, double S);

int main(void)
{
	int sentences = 0;
	int letters = 0;
	int words = 0;
	double L;
	double S;

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
		else if ((len - 1 == i))
		{
			words += 1;
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
		else
		{
			printf("Something went wrong!\n");
		}

		// L is the average number of letters per 100 words in the text
		L = ((double) letters / (double) words) * 100.00;

		// S is the average number of sentences per 100 words in the text.
		S = ((double) sentences / (double) words ) * 100.00;
	}

    printf("\nLetters: %i, Words: %i, Sentences: %i, L: %f, S: %f\n", letters, words, sentences, L, S);
// Print the Grade X
	int X = Coleman_Liau(L,S);
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
int Coleman_Liau(double L, double S)
{
	int sum;
	double index = (0.0588 * L) - (0.296 * S) - 15.8;
	printf("Index: %f\n", index);
	sum = (int) round(index);
	printf("Sum: %i\n", sum);
	return sum;
}
