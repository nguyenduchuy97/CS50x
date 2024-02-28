#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
void print_sum(int sum);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int sum = calculate_quarters(cents);

    print_sum(sum);

}

    // Calculate how many quarters you should give customer
int calculate_quarters(int cents)
{
    int quarters = 0;
    int cent = cents;

        while (cents != 0)
    {
        if (cents > 24)
        {
                while (cents > 24)
                {
    // Subtract the value of those quarters from cents
                    quarters ++;
                    cents -= 25;
                }
        }
        else if (cents > 9)
        {
            while (cents > 9)
            {
    // Subtract the value of those dimes from cents
                cents -= 10;
                quarters ++;
            };
        }
        else if (cents > 4)
        {
            while (cents > 4)
            {
    // Subtract the value of those nickels from remaining cents
                cents -= 5;
                quarters ++;
            }
        }
        else
        {
            while (cents > 0)
            {
    // Subtract the value of those pennies from remaining cents
                cents -= 1;
                quarters ++;
            }
        }
    }

    return quarters;
}
/*
    // Calculate how many dimes you should give customer
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents > 9) //(cents > 9 && cents < 25)
    {
    // Subtract the value of those dimes from cents
        cents -= 10;
        dimes ++;
    }
    return dimes;
}

    // Calculate how many nickels you should give customer
int calculate_nickels(int cents)
{
    // Subtract the value of those nickels from remaining cents
    int nickels = 0;
    while (cents > 4) //(cents > 4 && cents < 10)
    {
        cents -= 5;
        nickels ++;
    }
    return nickels;
}

    // Calculate how many pennies you should give customer
int calculate_pennies(int cents)
{
    // Subtract the value of those pennies from remaining cents
    int pennies = 0;
    while (cents > 0) //(cents > 0 && cents < 5)
    {
        cents -= 1;
        pennies ++;
    }
    return pennies;
}

    // Sum the number of quarters, dimes, nickels, and pennies used
*/
void print_sum(int sum)
{
    // Print that sum
    printf("%i\n", sum);

}
