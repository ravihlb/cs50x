#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char substitute(char input, char *key);
void print_usage();

const int ASCII_TABLE_UPPER_A_INDEX = 65;
const int ASCII_TABLE_LOWER_A_INDEX = 97;

int main(int argc, char *argv[])
{

    if (argc < 2 || argc > 2)
    {
        print_usage();
        return 1;
    }

    char *key = argv[1];

    if (strlen(key) != 26)
    {
        print_usage();
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        const char currChar = key[i];

        for (int j = 0; j < strlen(key); j++)
        {
            if (j == i)
                continue;
            if (key[j] == currChar)
            {
                print_usage();
                return 1;
            }
        }

        if (!isalpha(currChar))
        {
            print_usage();
            return 1;
        }
    }

    char *plaintext = get_string("plaintext: ");
    int plaintext_str_len = strlen(plaintext);

    char ciphertext[plaintext_str_len];
    ciphertext[plaintext_str_len] = '\0';

    for (int i = 0; i < plaintext_str_len; i++)
    {
        // get char from input
        char currChar = plaintext[i];

        if (!isalpha(currChar))
        {
            ciphertext[i] = currChar;
            continue;
        }

        // map it onto the key
        ciphertext[i] = substitute(currChar, key);
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

void print_usage()
{
    printf("Usage: ./substitution key\n");
}

char substitute(char input, char *key)
{
    // lookup the equivalent alphabetical index of input char relative to ASCII hex values
    // return character on index got from previous step from the key string
    int alphabetical_idx;
    bool lower = false;

    if (isupper(input))
    {
        alphabetical_idx = (int) input - ASCII_TABLE_UPPER_A_INDEX;
    }
    else
    {
        lower = true;
        alphabetical_idx = (int) input - ASCII_TABLE_LOWER_A_INDEX;
    }

    if (lower)
    {
        return tolower(key[alphabetical_idx]);
    }

    return toupper(key[alphabetical_idx]);
}
