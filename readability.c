#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(int n, string s);
int count_words(int n, string s);
int count_sentences(int n, string s);\
void grade(float f);

int main(void)
{
    // Prompt user
    string text = get_string("Text: ");

    // Count letters from the text
    int length = strlen(text);
    int letters = count_letters(length, text);

    // Count words from the text
    int words = count_words(length, text);

    // Count sentences from the text
    int sentences = count_sentences(length, text);

    // L is the average number of letters per 100 words
    float L = letters * 100 / words;

    // S is the average number of sentences per 100 words
    float S = sentences * 100 / words;

    // Getting Coleman-Liau index
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print out the level of the text
    grade(index);

    return 0;

}

int count_letters(int n, string s)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
        {
            count++;
        }
    }

    return count;
}

int count_words(int n, string s)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 32)
        {
            count++;
        }
    }

    count++;

    return count;
}

int count_sentences(int n, string s)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count++;
        }
    }

    return count;
}

// Get grade from Coleman_Liau index
void grade(float f)
{
    if (f < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (f >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        for (int i = 0; i < 14; i++)
        {
            if (f >= i + 1 && f < i + 2)
            {
                printf("Grade %i\n", i + 1);
            }
        }
    }
}
