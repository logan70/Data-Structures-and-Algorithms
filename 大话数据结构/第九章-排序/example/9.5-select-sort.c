#include "9.1-sort.h"

void SelectSort(SqList * L)
{
  int i, j, min;
  for (i = 0; i < L->length - 1; i ++)
  {
    min = i;
    for (j = i + 1; j < L->length - 1; j++)
      if (L->r[min] > L->r[j])
        min = j;
    if (min != i)
      swap(L, i, min);
  }
}
