#include <stdint.h>
#include <stdio.h>

struct point {
  int x;
  int y;
};

int main(int argc, char *argv[]) {
  struct point pt = {20, 10};
  printf("%d, %d\n", pt.x, pt.y);
  return 0;
}
