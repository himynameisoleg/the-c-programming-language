// NOTE: Pointers and Arrays

// int main(void) {
//   int x = 1, y = 2, z[10];
//   int *ip;
//   ip = &x;
//   y = *ip;
//   *ip = 0;
//   ip = &z[0];
// }

// NOTE: pointers in function headers
// void swap(int *px, int *py) {
//   int temp;
//
//   temp = *px;
//   *px = *py;
//   *py = temp;
// }
//
// #include <ctype.h>
// #include <stdio.h>
//
// int getch(void);
// void ungetch(int);
//
// int getint(int *pn) {
//   int c, sign;
//
//   while (isspace(c = getch()))
//     ;
//   if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
//     ungetch(c);
//     return 0;
//   }
//
//   sign = (c == '-') ? -1 : 1;
//   if (c == '+' || c == '-')
//     c = getch();
//   for (*pn = 0; isdigit(c); c = getch())
//     *pn = 10 * *pn + (c - '0');
//   *pn *= sign;
//   if (c != EOF)
//     ungetch(c);
//   return c;
// }
//
// int main(void) {
//   int i = 5;
//   getint(&i);
// }

// NOTE: Address Arithmetic

// #define ALLOCSIZE 10000
//
// static char allocbuf[ALLOCSIZE];
// static char *allocp = allocbuf;
//
// char *alloc(int n) {
//   if (allocbuf + ALLOCSIZE - allocp >= n) {
//     allocp += n;
//     return allocp - n;
//   } else
//     return 0;
// }
//
// void afree(char *p) {
//   if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
//     allocp = p;
// }

// NOTE: Pointer Arrays

char *month_name(int n) {
  static char *name[] = {"Illegal month", "January",   "February", "March",
                         "April",         "May",       "June",     "July",
                         "August",        "September", "October",  "November",
                         "December"};
  return (n < 1 || n > 12) ? name[0] : name[n];
}
