#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        printf("score1: %i, score2: %i\n", score1, score2);
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
        printf("score: %i\n", score1);
    }
    else
    {
        printf("Player 2 wins!\n");
        printf("score1: %i, score2: %i\n", score1, score2);
    }
}

// Compute and return score for string
int compute_score(string word)
{
    int total_points = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char letter = tolower(word[i]);
        // checking if non-letter character
        if (letter >= 'a' && letter <= 'z')
        {
            // in ASCII chart a = 97, but we need a = 0, b = 1 ...
            int letter_index = (int) letter - 97;
            int point = POINTS[letter_index];
            total_points += point;
        }
    }

    return total_points;
}
