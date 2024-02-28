#include <cs50.h>
#include <stdio.h>

int coins = 0;
int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
}
    // Calculate how many quarters you should give customer
int calculate_quarters(int amount)
{
    if (amount > 24)
    {
        amount -= 25;
        coins += 1;
    }
}
    // Subtract the value of those quarters from cents

    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents

    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents

    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents

    // Sum the number of quarters, dimes, nickels, and pennies used
    // Print that sum

