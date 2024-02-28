#include <cs50.h>
#include <stdio.h>

bool check_valid(long int card);
string id_issuer(long int card);

int main()
{
    long int number = get_long("Number: ");

    string issuer = indentify_issuer(number);
    printf("%s\n", issuer);
 }

bool check_valid(long int card)
{
    int lenth = 0;
    int sum = 0;
    bool double_step = false;
    long int temp_card = card;

    // Count the number of digit.
    while (temp_card > 0)
    {
        lenth++;
        temp_card /= 10;
    }
    //  If the number of digit odd (count the last) or even (won't count the last), because we count from right to left.
    double_step = lenth % 2 == 0;
    while (card > 0)
    {
        // Start from the second-to-last digit of the credit card number.
        int digit = card % 10;
        // Count the last position if number of digits is odd.
        if (double_step)
        {
            digit *= 2;
            // Count digit if it has 2 digits
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }
        // Count the last position if number of digits is even.
        sum += digit;
        // Change to true of false so it will jump 2 step at a time.
        double_step = !double_step;
    }
    // Check if the last digit of the algorithm's result equal 0 and the number of digit between 13 to 16.
    return (sum % 2 == 0) && (length >= 13 && length <= 16);
}

string id_issuer(long int card)
{
    // Divide 12 digit to get at least more than 1 digit.
    int last_d = card / 100000000000;
    /*
AMEX:
number digits:	15
start with: 34 - 37
    */
    if (last_d )
    {}

    return ;
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
