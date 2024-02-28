#include <cs50.h>
#include <stdio.h>

bool check_valid(long int card);
string id_issuer(long int card);

int main()
{
    long int number = get_long("Number: ");

    if (check_valid(number))
    {
        string issuer = id_issuer(number);
        printf("%s\n", issuer);
    }
    else
    {
        printf("INVALID\n");
    }
 }

bool check_valid(long int card)
{
    int length = 0;
    int sum = 0;
    bool double_step = false;
    long int temp_card = card;

    // Count the number of digit.
    while (temp_card > 0)
    {
        length++;
        temp_card /= 10;
    }

    //  If the number of digit odd (count the last) or even (won't count the last), because we count from right to left.
    double_step = length % 2 == 0;

    while (card > 0)
    {
        // Start from the second-to-last digit of the credit card number.
        int digit = card % 10;
        // Double every other digit, moving from right to left.
        if (double_step)
        {
            digit *= 2;
            // If doubling a digit results in a two-digit number, add the individual digits of that product together.
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }
        // Sum all the obtained digits from the doubling process along with the digits that were not doubled.
        sum += digit;
        // Move to the next 2 digit.
        card /= 10;
        // Change to true of false so it will jump 2 step at a time.
        double_step = !double_step;
    }
    // Check if the last digit of the algorithm's result equal 0 and the number of digit between 13 to 16.
    // If the total sum ends in 0 (i.e., it is divisible by 10), then the credit card number is considered valid.
    return (sum % 2 == 0) && (length >= 13 && length <= 16);
}

string id_issuer(long int card)
{
    // Divide 12 digit to get at least more than 1 digit.
    int last_d = card / 100000000000;

    if ((last_d == 34 || last_d == 37) || (last_d >= 3400 && last_d <= 3799))
    {
        return "AMEX";
    }

    else if ((last_d >= 51 && last_d <= 55) || (last_d >= 5100 && last_d <= 5599))
    {
        return "MASTERCARD";
    }

    else if ((last_d >= 40 && last_d <= 49) || (last_d >= 40000 && last_d <= 49999))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }

}

