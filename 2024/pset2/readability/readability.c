// Coleman-Liau readability index
// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text,
// and S is the average number of sentences per 100 words in the text.

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

    float grade;

    // get input string
    char *input = get_string("Text: ");
    while (!input || strcmp(input, "") == 0 || strcmp(input, "\n") == 0)
    {
        input = get_string("Text: ");
    }

    // iterate over entire string, while keeping count of:
    //  1: letters
    //      - ignore anything that !isalpha()
    //  2: sentences
    //      - whenever I find a period, increment
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int spaces = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        char currChar = input[i];

        if (isalpha(currChar))
        {
            letters++;
            continue;
        }

        // this means we're starting with a special character, likely punctuation.
        if (i == 0 && !(isalpha(currChar)))
        {
            continue;
        }

        if (currChar == ' ')
        {
            spaces++;
            continue;
        }

        if ((currChar == '.' && input[i + 1] != '.') || (currChar == '!' && input[i + 1] != '!') ||
            (currChar == '?' && input[i + 1] != '?'))
        {
            sentences++;
            continue;
        }

        // if we're at the end, there are no more characters and we haven't incremented word
        // or sentences, set them to 1
        if (i == strlen(input) - 1)
        {
            if (words == 0)
            {
                words = 1;
            }

            if (sentences == 0)
            {
                sentences = 1;
            }
        }
    }

    words = spaces + 1;

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    grade = 0.0588 * L - 0.296 * S - 15.8;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    if (grade > 15)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %i\n", (int) round(grade));
    return 0;
}
