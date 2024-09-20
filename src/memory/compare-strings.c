#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");
    char* t = get_string("t: ");

    if (strcmp(s, t) == 0) {
        printf("Same\n");
    } else {
        printf("Different\n");
    }

    printf("\nStrings are:\n");
    printf("%s\n", s);
    printf("%s\n", t);

    printf("\nPointers are:\n");
    printf("%p\n", s);
    printf("%p\n", t);
}
