#include <cs50.h>
#include <stdio.h>

bool check_valid(long int card);
string id_issuer(long int card);

int main()
{
    long int number = get_long("Number: ");
    if (check_valid())
    {
        indentify_issuer()
    }
}

bool check_valid(long int card)
{
    int lenth = 0;
    int sum = 0;
    bool double_step = false;
    long int c_card = card;

    // Count the number of digit.
    while (c_card > 0)
    {
        lenth++;
        c_card /= 10;
    }
    //  If the number of digit odd (count the last) or even (won't count the last), because we count from right to left.
    doulbe_step = lenth % 2 == 0;
    while (card > 0)
    {
        // Start from the second-to-last digit of the credit card number.
        int digit = card % 10;

        if (double_step)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }
        sum += digit;
    }

    return result;
}

string id_issuer(long int card)
{
    string issuer;

    return issuer;
}
/*
AMEX:
number digits:	15
start with: 34 - 37

MASTERCARD
number digits:	16
start with: 51 - 55

VISA
number digits:	13 - 16
start with: 4

INVALID
*/


// Start from the second-to-last digit of the credit card number.
// Double every other digit, moving from right to left.
// If doubling a digit results in a two-digit number, add the individual digits of that product together.
// Sum all the obtained digits from the doubling process along with the digits that were not doubled.
// If the total sum ends in 0 (i.e., it is divisible by 10), then the credit card number is considered valid.
