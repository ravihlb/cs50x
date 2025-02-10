#include <stdlib.h>

int main(void)
{
  // x is effectively an array here
  // so... array syntax is lies?
  int *x = malloc(3 * sizeof(int));

  x[1] = 72;
  x[2] = 73;
  x[3] = 33;
  x[4] = 0;

  free(x);
}
