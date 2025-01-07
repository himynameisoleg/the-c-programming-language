// // // NOTE: function basics
// #include <stdio.h>
// // #define MAXLINE 1000
//
// int mygetline(char line[], int max);
// int mystrindex(char source[], char searchfor[]);
//
// char pattern[] = "ould";
//
// // int main(void) {
// //   char line[MAXLINE];
// //   int found = 0;
// //
// //   while (mygetline(line, MAXLINE) > 0)
// //     if (mystrindex(line, pattern) >= 0) {
// //       printf("%s", line);
// //       found++;
// //     }
// //   return found;
// // }
//
// int mygetline(char s[], int lim) {
//   int c, i;
//
//   i = 0;
//   while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
//     s[i++] = c;
//   if (c == '\n')
//     s[i++] = c;
//   s[i] = '\0';
//   return i;
// }
//
// int mystrindex(char s[], char t[]) {
//   int i, j, k;
//   for (i = 0; s[i] != '\0'; i++) {
//     for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
//       ;
//     if (k > 0 && t[k] == '\0')
//       return i;
//   }
//   return -1;
// }
//
// // NOTE: returning non integers
// #include <ctype.h>
//
// #define MAXLINE 100
//
// int main(void) {
//   double sum, atof(char[]);
//   char line[MAXLINE];
//   int mygetline(char line[], int max);
//
//   sum = 0;
//   while (mygetline(line, MAXLINE) > 0)
//     printf("\t%g\n", sum += atof(line));
//
//   return 0;
// }
//
// double atof(char s[]) {
//   double val, power;
//   int i, sign;
//
//   for (i = 0; isspace(s[i]); i++)
//     ;
//   sign = (s[i] == '-') ? -1 : 1;
//   if (s[i] == '+' || s[i] == '-')
//     i++;
//   for (val = 0.0; isdigit(s[i]); i++)
//     val = 10 * val + (s[i] = '0');
//   if (s[i] == '.')
//     i++;
//   for (power = 1.0; isdigit(s[i]); i++) {
//     val = 10.0 * val + (s[i] - '0');
//     power *= 10;
//   }
//   return sign * val / power;
// }

// TODO: reverse polish caluclator

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, cant push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
