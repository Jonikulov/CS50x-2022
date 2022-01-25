#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        // spaces before left pyramid
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }

        // printing hashes
        for (int k = 1; k <= (i * 2); k++)
        {
            printf("#");
            // if half of k is equal to i
            if (k == i)
            {
                // separating spaces in the center of the pyramids
                printf("  ");
            }
        }

        // print new line and space
        printf("\n");
    }
}