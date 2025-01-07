// // NOTE: function basics
#include <stdio.h>
// #define MAXLINE 1000

int mygetline(char line[], int max);
int mystrindex(char source[], char searchfor[]);

char pattern[] = "ould";

// int main(void) {
//   char line[MAXLINE];
//   int found = 0;
//
//   while (mygetline(line, MAXLINE) > 0)
//     if (mystrindex(line, pattern) >= 0) {
//       printf("%s", line);
//       found++;
//     }
//   return found;
// }

int mygetline(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int mystrindex(char s[], char t[]) {
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}

// NOTE: returning non integers
#include <ctype.h>

#define MAXLINE 100

int main(void) {
  double sum, atof(char[]);
  char line[MAXLINE];
  int mygetline(char line[], int max);

  sum = 0;
  while (mygetline(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));

  return 0;
}

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10 * val + (s[i] = '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}
