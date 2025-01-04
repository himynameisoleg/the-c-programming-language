#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {

  int nums[6] = {1, 2, 3, 4, 5, 6};
  int res = binsearch(4, nums, 6);
  printf("%d\n", res);

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    // printf("%d\n", mid);

    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}
