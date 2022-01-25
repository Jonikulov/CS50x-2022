#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // asking the height
        height = get_int("Height: ");
    }
    // if height is not right then prompt the user
    while (height <= 0 || height > 8);

    // iterating by given height
    for (int i = 1; i <= height; i++)
    {
        // printing spaces
        for (int k = height; k > i; k--)
        {
            printf(" ");
        }
        // printing hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n"); // adding new line
    }
}
