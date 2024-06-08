#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int numbers[] = { 20, 500, 10, 5, 100, 1, 50 };
    const int length = 7;
    const int target = get_int("Number: ");

    for (int i = 0; i < length; i++) {
        if (numbers[i] == target) {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not fonud\n");
    return 1;
}
