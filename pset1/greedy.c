#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // declare variable dollars and ask the user for input
    float dollars;
    
    do
    {
        printf("How much change is owed?\n");
        dollars = GetFloat();
    }
    while (dollars < 0);
    
    // convert the dollars into cents
    int cents = round(dollars * 100);
    
    int quarter = 0, dime = 0, nickel = 0, penny = 0, result = 0;
    
    // calculate the number of quarters
    while (cents >= 25) 
    {
        cents -= 25;
        quarter++;
    }

    // calculate the number of dimes
    while (cents >= 10) 
    {
        cents -= 10;
        dime++;
    }

    // calculate the number of nickels
    while (cents >= 5) 
    {
        cents -= 5;
        nickel++; 
    }

    // calculate the number of pennies
    while (cents >= 1) 
    {
        cents -= 1;
        penny++;
    }
    
    // add the number of coins to get the final result
    result = quarter + dime + nickel + penny;

    // print the result
    printf("%i\n", result);
}
