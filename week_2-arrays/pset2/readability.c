#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    // average letters
    float L = letters / words * 100;
    // average sentences
    float S = sentences / words * 100;
    // calculating index by the Coleman-Liau formula
    float index = (0.0588 * L - 0.296 * S - 15.8);

    // printing grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));

    }
}


int count_letters(string text)
{
    // tracking letters
    int let_counter = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // turning every single character to lowercase
        char ch = tolower(text[i]);
        // check if the character is a letter between 'a' through 'z' inclusive
        if (islower(ch))
        {
            let_counter += 1;
        }
    }
    return let_counter;
}


int count_words(string text)
{
    // the reason word_counter starts from 1 is
    // because of sentence will not end with a space it does not count the last word
    int word_counter = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word_counter += 1;
        }
    }
    return word_counter;
}


int count_sentences(string text)
{
    int sen_counter = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sen_counter += 1;
        }
    }
    return sen_counter;
}
