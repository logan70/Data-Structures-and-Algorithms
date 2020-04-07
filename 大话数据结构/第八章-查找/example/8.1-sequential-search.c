#include <stdio.h>

// 顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字
int Sequential_Search(int * a, int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (a[i] == key)
      return i;
    return -1;
  }
}
