#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int n = get_int("Height: ");

    for (int i = n; i > 0; i--) {

        for (int k = i; k > 0; k--) {
            printf(" ");
        }

        for (int j = i; j <= n; j++) {
            printf("#");
        }

        printf(" ");
        printf(" ");

        for (int j = i; j <= n; j++) {
            printf("#");
        }

        printf("\n");
    }
}
