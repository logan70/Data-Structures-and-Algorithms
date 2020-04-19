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
  puts("Before SelectSort:");
  printArr(L);
  SelectSort(L);
  puts("After SelectSort:");
  printArr(L);
  free(L);
  return 0;
}

void SelectSort(SqList * L)
{
  int i, j, min;
  for (i = 0; i < L->length - 1; i ++)
  {
    min = i;
    for (j = i + 1; j < L->length; j++)
      if (L->r[j] < L->r[min])
        min = j;
    if (min != i)
      swap(L, i, min);
  }
}
