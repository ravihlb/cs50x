#include <stdio.h>

int main(void)
{
    int scores[1024];

    // every value that's not 0 is garbage left by other programs
    for (int i = 0; i < 1024; i++) {
        printf("%i\n", scores[i]);
    }
}
