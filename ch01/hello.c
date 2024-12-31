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

// variation with `for`
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
