#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_digits(long int card);
int main()
{
    long int number = get_long("Number: ");
    if (number < 0)
    {
        printf("Invalid input %li\n", number);
    }
    int len = 0;
    for (int i = 10; (number % i != number); i*10)
    {
        len++;
    }
    printf("%i\n", len);
}


// Start from the second-to-last digit of the credit card number.
// Double every other digit, moving from right to left.
// If doubling a digit results in a two-digit number, add the individual digits of that product together.
// Sum all the obtained digits from the doubling process along with the digits that were not doubled.
// If the total sum ends in 0 (i.e., it is divisible by 10), then the credit card number is considered valid.
