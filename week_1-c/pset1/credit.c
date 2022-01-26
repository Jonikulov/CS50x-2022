#include <cs50.h>
#include <stdio.h>

int checksum(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number<1);

    // checksum
    int result = checksum(number);
    printf("sum0: %i\n", result);
    // printf()
    // AMEX -> 15 digits, starts with 34/37
    // MASTERCARD -> 16 digits, starts with 51/52/53/54/55
    // VISA -> 13/16 digits, starts with 4
    // INVALID

}

int checksum(long number)
{
    long remainder;
    long divider = 100;
    int num;
    int sum0 = 0;
    float division;
    while (true)
    {
        remainder = number%divider;
        num = remainder/(divider/10);

        sum0 = sum0 + num*2;
        printf("num: %i\n", num);

        division = number/divider;
        printf("%li/%li = %f\n", number, divider, division);

        divider = divider * 100;
        if (number/divider < 0.1)
        {
            break;
        }
    }

    return sum0;
}

// 58331002910654
// 4003600000000014