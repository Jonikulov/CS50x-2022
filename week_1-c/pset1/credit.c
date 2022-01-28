#include <cs50.h>
#include <stdio.h>
// #include <stdbool.h>

long checksum(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 1);

    // checksum
    long isValid = checksum(number);
    printf("%li\n", isValid);

    // AMEX -> 15 digits, starts with 34/37
    // MASTERCARD -> 16 digits, starts with 51/52/53/54/55
    // VISA -> 13/16 digits, starts with 4
    // INVALID

}

long checksum(long number)
{
    // assigning variables
    long remainder;
    long divider = 100;
    int num1;
    int sum0 = 0;

    while (true)
    {
        remainder = number % divider;
        num1 = remainder / (divider/10);
        divider *= 100;

        sum0 += num1 * 2;

        // //
        printf("num: %i\n", num1);
        // //

        if ((number / divider) < 0.01)
        {
            break;
        }
    }

    return sum0;
}

// 4003600000000014