#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage();
char rotate(char src, int key);

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        print_usage();
        return 1;
    }

    if (!isdigit(argv[1][0]) || argv[1][0] < 1)
    {
        print_usage();
        return 1;
    }

    // iterate over argv[1] to check each character of the arg string
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        char currChar = argv[1][i];

        // reject any alphabetical char
        if (isalpha(currChar) && !(currChar == 'n' && argv[1][i - 1] == '\\'))
        {
            print_usage();
            return 1;
        }
    }

    int key = atoi(argv[1]);
    char *plaintext = get_string("plaintext: ");
    int plaintext_str_len = strlen(plaintext);

    char ciphertext[plaintext_str_len];
    ciphertext[plaintext_str_len] = '\0';

    char rotated[plaintext_str_len];
    rotated[plaintext_str_len] = '\0';

    for (int i = 0; i < plaintext_str_len; i++)
    {
        char currChar = plaintext[i];

        if (currChar == 'n' && plaintext[i - 1] == '\\')
        {
            continue;
        }

        rotated[i] = rotate(currChar, key);
    }

    strcpy(ciphertext, rotated);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

char rotate(char src, int key)
{
    // ensuring that src is within the ASCII alphabet hexadecimal range
    if (!isalpha(src))
    {
        return src;
    }

    if (key > 26)
    {
        key %= 26;
    }

    int dst = (int) src + key;

    // wraps around the alphabet
    if ((isupper(src) && dst > 'Z') || (islower(src) && dst > 'z'))
    {
        dst -= 26;
    }

    return (char) dst;
}

void print_usage()
{
    printf("Usage: ./caesar key\n");
}
