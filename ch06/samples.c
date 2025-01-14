#include <stdint.h>
#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int, int);

struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

int main(int argc, char *argv[]) {

  struct rect screen;
  struct point middle;

  screen.pt1 = makepoint(0, 0);
  screen.pt2 = makepoint(300, 100);

  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                     (screen.pt1.y + screen.pt2.y) / 2);

  printf("%d, %d\n", middle.x, middle.y);
  return 0;
}
