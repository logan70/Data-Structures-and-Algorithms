#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "9.1-sort.h"

int main(void)
{
  SqList * L = (SqList *)malloc(sizeof(SqList));
  memcpy(L->r, (int []){8, 6, 4, 3, 5, 9, 1, 7, 2}, sizeof(int) * 9);
  L->length = 9;
  puts("Before MergingSort:");
  printArr(L);
  MergingSort(L);
  puts("After MergingSort:");
  printArr(L);
  free(L);
  return 0;
}

void MergingSort(SqList * L)
{
  MSort(L->r, L->r, 1, L->length);
}

void MSort(int SR[], int TR1[], int s, int t)
{
  int m;
  int TR2[MAXSIZE + 1];
  if (s == t)
    TR1[s] = SR[s];
  else
  {
    m = (s + t) / 2; // 将SR[s..t]平分为SR[s..m]和SR[m+1..t]
    MSort(SR, TR2, s, m); // 递归将SR[s..m]归并为有序的TR2[s..m]
    MSort(SR, TR2, m + 1, t); // 递归将SR[m+1..t]归并为有序的TR2[m+1..t]
    Merge(TR2, TR1, s, m, t); // 将TR2[s..m]和TR2[m+1..t] 归并到TR1[s..t]
  }
}

void Merge(int SR[], int TR[], int i, int m, int n)
{
  int j, k, l;
  for (j = m + 1, k = i; i <= m && j <= n; k++) // 将SR中记录有小到大归并如TR
  {
    if (SR[i] < SR[j])
      TR[k] = SR[i++];
    else
      TR[k] = SR[j++];
  }
  if (i <= m)
  {
    for (l = 0; l < m - i; l++)
      TR[k + l] = SR[i + 1]; // 将剩余的SR[i..m]复制到TR
  }
  if (j <= n)
  {
    for (l = 0; l < n - j; l++)
      TR[k + 1] = SR[j + 1]; // 将剩余的SR[j..n]复制到TR
  }
}
