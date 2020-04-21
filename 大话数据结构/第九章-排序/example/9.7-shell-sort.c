#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "9.1-sort.h"

int main(void)
{
  SqList * L = (SqList *)malloc(sizeof(SqList));
  memcpy(L->r, (int []){8, 6, 4, 3, 5, 9, 1, 7, 2}, sizeof(int) * 9);
  L->length = 9;
  puts("Before ShellSort:");
  printArr(L);
  ShellSort(L);
  puts("After ShellSort:");
  printArr(L);
  free(L);
  return 0;
}

void ShellSort(SqList * L)
{
  int i, j, temp, gap = 1;
  while (gap < L->length / 3)
    gap = gap * 3 + 1;
  while (gap > 0)
  {
    for (i = gap; i < L->length; i++)
    {
      temp = L->r[i];
      j = i - gap;
      while (j >= 0 && L->r[j] > temp)
      {
        L->r[j + gap] = L->r[j];
        j -= gap;
      }
      L->r[j + gap] = temp;
    }
    gap = gap / 3;
  }
}