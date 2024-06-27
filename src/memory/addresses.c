#include <stdio.h>

int main(void)
{
    int n = 50;
    // p's type is "pointer to integer"
    int* p = &n;

    printf("Variable's pointer holds: %p\n", p);
    printf("Stored value in variable is: %i\n", *p);
}
