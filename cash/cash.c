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
    // Calculate how many dimes you should give customer
            while (cents > 9)
            {
    // Subtract the value of those dimes from cents
                cents -= 10;
                quarters ++;
            };
        }
        else if (cents > 4)
        {
    // Calculate how many nickels you should give customer
            while (cents > 4)
            {
    // Subtract the value of those nickels from remaining cents
                cents -= 5;
                quarters ++;
            }
        }
        else
        {
    // Calculate how many pennies you should give customer
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

    // Sum the number of quarters, dimes, nickels, and pennies used

void print_sum(int sum)
{
    // Print that sum
    printf("%i\n", sum);

}
