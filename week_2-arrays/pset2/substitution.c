#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_letters(string s);
bool is_repeated(string t);
char rotate(char c, string keys);

int main(int argc, string argv[])
{
    // check if argument count
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // get key
    string key = argv[1];
    // check key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    // check if key contains only letters
    if (only_letters(key) == False)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    // check if key containing each letter exactly once
    if (is_repeated(key))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    // get plaintext
    string text = get_string("plaintext:  ");
    // print ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c", rotate(text[i], key));
    }
    printf("\n");

    return 0;
}


// check for non-alphabetic characters
bool only_letters(string s)
{
    for (int j = 0; j < 26; j++)
    {
        if (!isalpha(s[j]))
        {
            return false;
        }
    }
    return true;
}


// check for repeated characters
bool is_repeated(string chars)
{
    char temp_arr[26];

    for (int k = 0; k < 26; k++)
    {
        // check each character in 'temp_arr' before adding
        for (int l = 0, ln = strlen(temp_arr); l < ln; l++)
        {
            // if character in 'chars' is already in 'temp_arr'
            // return true -> characters repeated
            if (temp_arr[l] == chars[k])
            {
                return true;
            }
        }
        // add each character in 'chars' to 'temp_arr'
        temp_arr[k] = chars[k];
    }
    return false;
}


// rotating letter to position that is in key
char rotate(char c, string keys)
{
    if (isupper(c))
    {
        return toupper(keys[c - 65]);
    }
    else if (islower(c))
    {
        return tolower(keys[c - 97]);
    }
    return c;
}
