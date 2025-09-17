#include "cs50.h"
#include "stdio.h"

void print_row(int n);

int main()
{
    int height = 0;
    while (height <= 0)
    {
        height = get_int("Height: ");
    }

    for (int row = 1; row <= height; row++)
    {
        int spaces = 0;

        while (spaces < height - row)
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
