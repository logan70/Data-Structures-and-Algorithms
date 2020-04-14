#include "9.1-sort.h"

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
      while (j >= 0 && L->r[j] < temp)
      {
        L->r[j + gap] = L->r[j];
        j -= gap;
      }
      L->r[j + gap] = temp;
    }
    gap = gap / 3;
  }
}