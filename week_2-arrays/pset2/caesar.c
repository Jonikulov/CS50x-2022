#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // checking if argc equals to 2 and argv[1] is int
    if (argc != 2  || !(only_digits(argv[1])))
    {
        printf("Usage: ./ceaser key\n");
        return 1;
    }

    // converting argv[1] from a string to an int
    int key = atoi(argv[1]);
    // getting plaintext
    string text = get_string("plaintext:  ");
    printf("ciphertext: ");
    // printing ciphertext
    for (int j = 0, len = strlen(text); j < len; j++)
    {
        printf("%c", rotate(text[j], key));
    }
    printf("\n");

    return 0;
}

// checking if every character in argv[1] is a digit
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    }
    return true;
}

// rotating character to 'key' positions if it's a letter
char rotate(char c, int k)
{
    if (isupper(c))
    {
        return 65 + (c - 65 + k) % 26;
    }
    else if (islower(c))
    {
        return 97 + (c - 97 + k) % 26;
    }
    return c;
}
