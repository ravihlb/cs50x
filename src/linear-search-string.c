#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    const string strings[] = { "battleship", "boot", "cannon", "iron", "thimble", "top hat" };
    const string target = get_string("String: ");

    for (int i = 0; i < 6; i++) {
        if (strcmp(target, strings[i]) == 0) {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not fonud\n");
    return 1;
}
