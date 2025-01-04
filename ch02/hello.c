#include <float.h>
#include <limits.h>
#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
  // printf("%d\n", CHAR_MIN);
  // printf("%d\n", CHAR_MAX);
  //
  // printf("%d\n", SHRT_MIN);
  // printf("%d\n", SHRT_MAX);
  //
  // printf("%d\n", INT_MAX);
  // printf("%d\n", INT_MIN);
  //
  // printf("%ld\n", LONG_MAX);
  // printf("%ld\n", LONG_MAX);

  printf("%d", bitcount(7));

  return 0;
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
