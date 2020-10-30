#include <stdio.h>
#include <cs50.h>

void HalfPyramid(int size);

int main(void)
{
    //input to get the size
    int size;
    //propmt to insert a size between 1 and 8 inclusice
    do
    {
        size = get_int("Please input a size between 1 and 8 inclusive:\n");
    }
    while (size < 1 || size > 8);
    HalfPyramid(size);
}
void HalfPyramid(int size)
{
    //loop to add new line
    for (int i = 0; i < size; i++)
    {
        //loop to add spaces
        for (int k = size - i; k > 1; k--)
        {
            printf(" ");
        }
        //loop to add the hashtags
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
