// Linear Search Algorithm
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 9, 1, 5, 8, 2, 6, 3, 7};

    for (int i = 0; i < 9; i++)
    {
        if (numbers[i] == 6)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
