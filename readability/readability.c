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

	// Prompt the user for some text
	string input = get_string("Text: ");
	int len = strlen(input);
	if (len > 0)
	{
		words = 1;
	}
    printf("Length: %i\n", len);

	// Count the number of letters, words, and sentences in the text
	for (int i = 0; i < len; i++)
	{
		// Count the words
		if (isspace(input[i]) && i + 1 < len && isalnum(input[i + 1]))
        {
            words++;
        }
		// Count the letters
		else if (isalnum(input[i]))
		{
			letters++;
		}
		// Count the sentences
		else if (len - 1 == i || input[i] == '.' || input[i] == '!' || input[i] == '?')
		{
			sentences++;
		}

		// L is the average number of letters per 100 words in the text
		L = ((double) letters / (double) words) * 100.00;

		// S is the average number of sentences per 100 words in the text.
		S = ((double) sentences / (double) words ) * 100.00;
	}

	// Compute the Coleman-Liau index
	int X = Coleman_Liau(L,S);

	// Print the Grade X
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
	sum = (int) round(index);
	return sum;
}
