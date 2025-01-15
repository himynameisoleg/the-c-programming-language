// #include <stdint.h>
// #include <stdio.h>
//
// struct point {
//   int x;
//   int y;
// };
//
// struct rect {
//   struct point pt1;
//   struct point pt2;
// };
//
// struct point makepoint(int, int);
//
// struct point makepoint(int x, int y) {
//   struct point temp;
//
//   temp.x = x;
//   temp.y = y;
//   return temp;
// }
//
// int main(int argc, char *argv[]) {
//
//   struct rect screen;
//   struct point middle;
//
//   screen.pt1 = makepoint(0, 0);
//   screen.pt2 = makepoint(300, 100);
//
//   middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
//                      (screen.pt1.y + screen.pt2.y) / 2);
//
//   printf("%d, %d\n", middle.x, middle.y);
//   return 0;
// }

// NOTE: Array of Structs

#define NKEYS 100

char *keyword[NKEYS];
int keycount[NKEYS];

char *word;
int count;

struct key {
  char *word;
  int count;
} keytab[NKEYS];

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void) {
  int n;
  char word[MAXWORD];
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((n = binsearch(word, keytab, NKEYS)) >= 0)
        keytab[n].count++;
  for (n = 0; n < NKEYS; n++)
    if (keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  return 0;
}

int binsearch(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;
  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
