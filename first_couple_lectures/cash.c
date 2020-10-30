#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar;
    do
    {
        dollar = get_float("Change owed: ");
    }
    while (dollar < 0);

    int cents = round(dollar * 100);
    int coins = 0;
    //the types of coins available
    int denominations[] = {25, 10, 5, 1};
    int size = sizeof(denominations) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }


    printf("You  will need %i coins\n", coins);
}
