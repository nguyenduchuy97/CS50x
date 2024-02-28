#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int calculate_sum(int quarter, int dimes, int nickels, int pennies);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);
    int dimes = calculate_dimes(cents);
    int nickels = calculate_nickels(cents);
    int pennies = calculate_pennies(cents);

    calculate_sum(quarters, dimes, nickels, pennies);
}

    // Calculate how many quarters you should give customer
int calculate_quarters(int cents)
{
    int quarters = 0;

    while (cents > 24)
    {
    // Subtract the value of those quarters from cents
        cents -= 25;
        quarters ++;
    }
    return quarters;
}

    // Calculate how many dimes you should give customer
int calculate_dimes(int cents)
{
    int dimes = 0;

    while (cents > 24)
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
    int nickels = 0;

    // Subtract the value of those nickels from remaining cents
    while (cents > 5)
    {
        cents -= 5;
        nickels ++;
    }
    return nickels;
}

    // Calculate how many pennies you should give customer
int calculate_penies(int cents)
{
    int pennies = 0;

    // Subtract the value of those pennies from remaining cents
    while (cents > 1)
    {
        cents -= 1;
        pennies ++;
    }
    return pennies;
}

    // Sum the number of quarters, dimes, nickels, and pennies used
int calculate_sum(int quarters, int dimes, int nickels, int pennies)
{
    // Print that sum
    int sum = quarters + dimes + nickels + pennies;
    printf("%i\n", sum);
}
