#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool checksum(long card_number, int length);
void printInvalid();

int const CARD_NUMBER_LENGTH_MAX = 16;
int const CARD_NUMBER_LENGTH_MIN = 13;

int main(void)
{
    long card_number = get_long("Number: ");

    char card_number_str[CARD_NUMBER_LENGTH_MAX];
    sprintf(card_number_str, "%ld", card_number);

    int length = strlen(card_number_str);

    // invalid length
    if (length > CARD_NUMBER_LENGTH_MAX || length < CARD_NUMBER_LENGTH_MIN)
    {
        printInvalid();
        return 0;
    }

    if (!checksum(card_number, length))
    {
        printInvalid();
        return 0;
    }

    long first_two_digits = card_number;
    while (first_two_digits > 99)
    {
        first_two_digits /= 10;
    }

    if ((first_two_digits / 10) == 4)
    {
        if (length != 13 && length != 16)
        {
            printInvalid();
            return 0;
        }

        printf("VISA\n");
        return 0;
    }

    if (first_two_digits == 34 || first_two_digits == 37)
    {
        if (length != 15)
        {
            printInvalid();
            return 0;
        }

        printf("AMEX\n");
        return 0;
    }

    if (first_two_digits >= 51 && first_two_digits <= 55)
    {
        if (length != 16)
        {
            printInvalid();
            return 0;
        }

        printf("MASTERCARD\n");
        return 0;
    }

    printInvalid();
    return 0;
}

bool checksum(long card_number, int length)
{
    // iterate the entire thing backwards
    // starting from the second-to-last position, double every other digit

    int sum = 0;
    long local_card_number = card_number;
    int j = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int digit = local_card_number % 10;

        // this means number is at odd index from end to start
        // which translates to even index, when going from start to finish
        if (j % 2 != 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                sum += digit % 10;
                digit /= 10;
            }
        }

        sum += digit;
        j++;
        local_card_number /= 10;
    }

    if (sum % 10 != 0)
    {
        return false;
    }

    return true;
}

void printInvalid()
{
    printf("INVALID\n");
}
