#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26

int scrabble(char *input);

typedef struct
{
    char letter;
    int value;
} Letter;

const Letter LETTER_VALUES[ALPHABET_LENGTH] = {
    {'a', 1}, {'b', 3}, {'c', 3}, {'d', 2}, {'e', 1}, {'f', 4}, {'g', 2}, {'h', 4},  {'i', 1},
    {'j', 8}, {'k', 5}, {'l', 1}, {'m', 3}, {'n', 1}, {'o', 1}, {'p', 3}, {'q', 10}, {'r', 1},
    {'s', 1}, {'t', 1}, {'u', 1}, {'v', 4}, {'w', 4}, {'x', 8}, {'y', 4}, {'z', 10},
};

int main(void)
{

    char *player_1_input = get_string("Player 1: ");
    char *player_2_input = get_string("Player 2: ");

    // calculate the value of each player's response
    int p1_result = scrabble(player_1_input);
    int p2_result = scrabble(player_2_input);

    int winner = 0;

    // compare them
    if (p1_result > p2_result)
    {
        winner = 1;
    }
    else if (p1_result < p2_result)
    {
        winner = 2;
    }

    if (winner == 0)
    {
        printf("Tie!\n");
        return 0;
    }

    printf("Player %i wins!\n", winner);

    return 0;
}

int scrabble(char *input)
{
    // setup a dictionary for lookup
    // we need to lookup based on character
    // ASCII characters carry numeric value, maybe we could look into that

    // I'll get an array of characters, essentially.
    // I'll iterate for each character of that array, using it as the key to compare
    // with items from the values array, in its own loop
    int score = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        char currChar = input[i];

        if (!isalpha(currChar))
        {
            continue;
        }

        // I need to store both char key and value for each char
        // This is time for structs!
        // did it: LETTER_VALUES!

        for (int j = 0; j < ALPHABET_LENGTH; j++)
        {
            if (tolower(currChar) != LETTER_VALUES[j].letter)
            {
                continue;
            }

            score += LETTER_VALUES[j].value;
            break;
        }
    }

    return score;
}
