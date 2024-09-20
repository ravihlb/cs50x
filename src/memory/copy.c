#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");
    if (s == NULL) {
        // OOM panic
        return 1;
    }

    char* t = malloc(sizeof(s));
    if (t == NULL) {
        // OOM panic
        return 1;
    }

    // To copy values pointers point to, assign new pointers to existing pointers
    strcpy(t, s);

    if (strlen(t) > 0) {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
    return 0;
}
