#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int Lettercount = 0;
    int Wordcount = 1;
    int Sentencecount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') | (text[i] >= 'A' && text[i] <= 'Z'))
        {
            Lettercount++;
        }
        else if (text[i] == ' ')
        {
            Wordcount++;
        }
        else if (text[i] ==  '.' | text[i] == '!' | text[i] == '?')
        {
            Sentencecount++;t grade = 0.0588 * (100 * (float) Lettercount / (float) Wordcount) - 0.296 * (100 * (float) Sentencecount / (float) Wordcount) - 15.8;
    if (grade < 16 && grade >= 0)
        }
    }
    floa
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
