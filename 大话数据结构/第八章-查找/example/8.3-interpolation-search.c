#include <stdio.h>

// 插值查找
int Interpolation_Search(int * a, int n, int key)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (a[low] != a[high] && key >= a[low] && key <= a[high])
  {
    mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
    if (key < a[mid])
      high = mid - 1;
    else if (key > a[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}