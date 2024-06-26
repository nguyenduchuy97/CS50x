#include <cs50.h>
#include <stdio.h>

bool check_sum(long int card);
string id_issuer(long int card);

int main()
{
    long int number = get_long("Number: ");

    if (check_sum(number))
    {
        string issuer = id_issuer(number);
        printf("%s\n", issuer);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_sum(long int card)
{
    int length = 0;
    int sum = 0;
    bool double_step = false;
    long int temp_card = card;
    long int first_2_d = card;

    // Take the first 2 digits.
    while (first_2_d > 99)
    {
        first_2_d /= 10;
    }
    // Count the number of digit(length of digit).
    while (temp_card > 0)
    {
        length++;
        temp_card /= 10;
    }

    while (card > 0)
    {
        // Start from the second-to-last digit of the credit card number.
        long int digit = card % 10;
        if (double_step)
        {
            // Double every other digit, moving from right to left.
            digit *= 2;
            // If doubling a digit results in a two-digit number, add the individual digits of that product together.
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }
        // Sum all the obtained digits from the doubling process along with the digits that were not doubled.
        sum += digit;
        // Move to the next digit.
        card /= 10;
        // Change to true of false so it will times 2 at the digit we want.
        double_step = !double_step;
    }
    // Check if the last digit of the algorithm's result equal 0 and the number of digit between 13 to 16.
    // If the total sum ends in 0 (i.e., it is divisible by 10), then the credit card number is considered valid.
    if ((sum % 10 == 0) && (length >= 13 && length <= 16))
    {
        return true;
    }
    // American Express
    else if ((length == 15 && first_2_d == 34) || (length == 15 && first_2_d == 37))
    {
        return true;
    }
    // MasterCard
    else if ((length == 16) && (first_2_d >= 51 && first_2_d <= 55))
    {
        return true;
    }
    // VISA
    else if ((length == 13 || length == 16) && (first_2_d >= 40 && first_2_d <= 49) && (sum % 10 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }

    // return (sum % 10 == 0) && (length >= 13 && length <= 16);
}

string id_issuer(long int card)
{
    int length = 0;
    long int temp_card = card;

    while (temp_card > 0)
    {
        length++;
        temp_card /= 10;
    }

    long int first_2_d = card;
    while (first_2_d > 99)
    {
        first_2_d /= 10;
    }

    if ((length == 15 && first_2_d == 34) || (length == 15 && first_2_d == 37))
    {
        return "AMEX";
    }

    else if ((length == 16) && (first_2_d >= 51 && first_2_d <= 55))
    {
        return "MASTERCARD";
    }

    else if ((length == 13 || length == 16) && (first_2_d >= 40 && first_2_d <= 49))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
