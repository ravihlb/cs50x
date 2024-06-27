#include <stdio.h>

int main(void)
{
    int n = 50;
    // p's type is "pointer to integer"
    int* p = &n;

    printf("Variable's pointer holds: %p\n", p);
    printf("Stored value in variable is: %i\n", *p);

    // strings are lies.
    // strings are just pointers to chars
    // C allocates the char array onto memory and just needs the first address to find the whole string.
    typedef char* string;
    string s = "HI!";

    printf("%s\n", s);
}
