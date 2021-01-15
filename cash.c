#include <math.h>

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float dollars;

    do
    {
        // Prompt user
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);

    // Count the number of coins
    int count = 0;

    // If remaining change is over 25cents
    if (cents >= 25)
    {
        count += cents / 25;
        cents %= 25;
    }

    // If remaining change is over 10cents
    if (cents >= 10)
    {
        count += cents / 10;
        cents %= 10;
    }

    // If remaining change is over 5cents
    if (cents >= 5)
    {
        count += cents / 5;
        cents %= 5;
    }

    // If change is less than 5cents just add up the change to the count variable
    count += cents;

    printf("%i\n", count);
}