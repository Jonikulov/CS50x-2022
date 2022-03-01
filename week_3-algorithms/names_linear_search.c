// Linear Search Algorithm
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Javohir", "Jasurbek", "Oybek"};

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], "John") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
