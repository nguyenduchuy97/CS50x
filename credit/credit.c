#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_digits(long int card);
int main()
{
    char card[20];
    printf("Enter your card number: ");
    scanf("Number: %s", card);


// Length of

}


// Start from the second-to-last digit of the credit card number.
// Double every other digit, moving from right to left.
// If doubling a digit results in a two-digit number, add the individual digits of that product together.
// Sum all the obtained digits from the doubling process along with the digits that were not doubled.
// If the total sum ends in 0 (i.e., it is divisible by 10), then the credit card number is considered valid.
