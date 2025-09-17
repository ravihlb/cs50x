#include "cs50.h"
#include "stdio.h"

void print_row(int n);

int main()
{
    int HEIGHT = 0;
    while (HEIGHT <= 0)
    {
        HEIGHT = get_int("Height: ");
    }

    for (int row = 1; row <= HEIGHT; row++)
    {
        int spaces = 0;

        while (spaces < HEIGHT - row)
        {
            spaces++;
            printf(" ");
        }

        print_row(row);
        printf("  ");
        print_row(row);
        printf("\n");
    }
}

void print_row(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("#");
    }
}
