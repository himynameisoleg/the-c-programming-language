// NOTE:
// #include <stdio.h>
//
// int main() {
//   float fahr, celsius;
//   float lower, upper, step;
//
//   lower = 0;
//   upper = 300;
//   step = 20;
//
//   fahr = lower;
//
//   while (fahr <= upper) {
//     celsius = (5.0 / 9.0) * (fahr - 32.0);
//     printf("%3.0f %6.1f\n", fahr, celsius);
//     fahr = fahr + step;
//   }
// }

// NOTE: variation with `for`
// #include <stdio.h>
//
// #define LOWER 0
// #define UPPER 300
// #define STEP 20
//
// int main(void) {
//   int fahr;
//
//   for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
//     printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
// }

// NOTE: copy input to output
// #include <stdio.h>
//
// int main(void) {
//   int c;
//
//   printf("EOF is: %d\n", EOF);
//
//   while ((c = getchar()) != EOF) {
//     printf("expression was: %b\n", (getchar() != EOF));
//     putchar(c);
//   }
// }

// NOTE: character counting
// #include <stdio.h>
//
// int main(void) {
//   // long nc;
//   //
//   // nc = 0;
//   // while (getchar() != EOF)
//   //   ++nc;
//   // printf("%ld\n", nc);
//
//   double nc;
//   for (nc = 0; getchar() != EOF; ++nc)
//     ;
//   printf("%.0f\n", nc);
// }

// NOTE: line counting
// #include <stdio.h>
//
// int main(void) {
//   int c, nl, tab, blank;
//
//   nl = 0;
//   tab = 0;
//   blank = 0;
//   while ((c = getchar()) != EOF) {
//     if (c == '\n')
//       ++nl;
//     if (c == '\t')
//       ++tab;
//     if (c == ' ')
//       ++blank;
//   }
//   printf("New lines: %d\n", nl);
//   printf("Tabs: %d\n", tab);
//   printf("Blank: %d\n", blank);
// }

// NOTE: word counting
// #include <stdio.h>
//
// #define IN 1
// #define OUT 0
//
// int main(void) {
//   int c, nl, nw, nc, state;
//
//   state = OUT;
//   nl = nw = nc = 0;
//   while ((c = getchar()) != EOF) {
//     ++nc;
//     if (c == '\n')
//       ++nl;
//     if (c == ' ' || c == '\n' || c == '\t')
//       state = OUT;
//     else if (state == OUT) {
//       state = IN;
//       ++nw;
//     }
//   }
//
//   printf("%d %d %d\n", nl, nw, nc);
// }

// NOTE: Arrays
// #include <stdio.h>
//
// int main(void) {
//   int c, i, nwhite, nother;
//   int ndigit[10];
//
//   nwhite = nother = 0;
//   for (i = 0; i < 10; ++i)
//     ndigit[i] = 0;
//
//   while ((c = getchar()) != EOF)
//     if (c >= '0' && c <= '9')
//       ++ndigit[c - '0'];
//     else if (c == ' ' || c == '\n' || c == '\t')
//       ++nwhite;
//     else
//       ++nother;
//
//   printf("digits=");
//   for (i = 0; i < 10; ++i)
//     printf(" %d", ndigit[i]);
//   printf(", white spce = %d, other = %d\n", nwhite, nother);
// }

// NOTE: functions
// #include <stdio.h>
//
// int power(int m, int n);
//
// int main(void) {
//   int i;
//
//   for (i = 0; i < 10; ++i)
//     printf("%d %d %d\n", i, power(2, i), power(-3, i));
//   return 0;
// }
//
// int power(int base, int n) {
//   int i, p;
//
//   p = 1;
//   for (i = 1; i <= n; ++i)
//     p = p * base;
//   return p;
// }

// NOTE: Arguments
// int power(int base, int n) {
//   int p;
//
//   for (p = 0; n > 0; --n)
//     p = p * base;
//   return p;
// }

// NOTE: Character Arrays
// #include <stdio.h>
// #define MAXLINE 1000
//
// int mygetline(char line[], int maxline);
// void copy(char to[], char from[]);
//
// int main(void) {
//   int len;
//   int max;
//   char line[MAXLINE];
//   char longest[MAXLINE];
//
//   max = 0;
//   while ((len = mygetline(line, MAXLINE)) > 0)
//     if (len > max) {
//       max = len;
//       copy(longest, line);
//     }
//   if (max > 0)
//     printf("%s", longest);
//   return 0;
// }
//
// int mygetline(char s[], int lim) {
//   int c, i;
//
//   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//     s[i] = c;
//   if (c == '\n') {
//     s[i] = c;
//     ++i;
//   }
//
//   s[i] = '\0';
//   return i;
// }
//
// void copy(char to[], char from[]) {
//   int i;
//
//   i = 0;
//   while ((to[i] = from[i]) != '\0')
//     ++i;
// }

// NOTE: External Variable and Scope

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int mygetline(void);
void copy(void);

int main(void) {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = mygetline()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int mygetline(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
