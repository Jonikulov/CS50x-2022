// Selection Sort Algorithm
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int arr[] = {4, 9, 1, 5, 8, 2, 6, 3, 7};

    for (int i = 0; i < 9; i++)
    {
        int min_ele_idx = i;
        for (int j = i; j < 9; j++)
        {
            if (arr[j] < arr[min_ele_idx])
            {
                min_ele_idx = j;
            }
        }
        // swapping elements
        int temp = arr[i];
        arr[i] = arr[min_ele_idx];
        arr[min_ele_idx] = temp;
    }

    for (int k = 0; k < 9; k++)
    {
        printf("%i ", arr[k]);
    }
    printf("\n");
}
