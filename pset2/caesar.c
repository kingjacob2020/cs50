#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int i, k, n, pn, j;
string key, plaintext;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //telling the user how to use the caesar if used wrong
        printf("Usage= ./caesar key\n");
        return 1;
    }
    else
    {
        key = argv[1];
        //provide error if non digit inputted
        for (i = 0, n = strlen(key); i < n; i++)
        {
            if (!isdigit(key[i]))
            {
                printf("Usage= ./caesar key\n");
                return 1;
            }
        }
    }
    //convert to integer
    k = atoi(argv[1]);
    //promt for input
    plaintext =  get_string("plaintext: ");
    printf("ciphertext: ");

    for (i = 0, pn = strlen(plaintext); i < pn; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + k) % 26 + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%C", (plaintext[i] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
