// Bubble Sort Algorithm
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int arr[] = {4, 9, 1, 5, 8, 2, 6, 3, 7};

    for (int i = 0; i <= 9 - 1; i++)
    {
        // indicator for checking if there is any swaps
        bool swap_flag = false;

        for (int k = 0; k <= 9 - 2; k++)
        {
            // swap elements
            if (arr[k] > arr[k+1])
            {
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
                // set swap true
                swap_flag = true;
            }
        }
        // stop if no swaps
        if (swap_flag == false)
        {
            break;
        }
    }

    for (int k = 0; k < 9; k++)
    {
        printf("%i ", arr[k]);
    }
    printf("\n");
}
