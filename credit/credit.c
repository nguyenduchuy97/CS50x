#include <cs50.h>
#include <stdio.h>

int main()
{
    long long int card = get_long("Number: ");
    printf("%lld\n", card);
    for (int i = 0; i)
    {

    }
}

// Start from the second-to-last digit of the credit card number.
// Double every other digit, moving from right to left.
// If doubling a digit results in a two-digit number, add the individual digits of that product together.
// Sum all the obtained digits from the doubling process along with the digits that were not doubled.
// If the total sum ends in 0 (i.e., it is divisible by 10), then the credit card number is considered valid.
