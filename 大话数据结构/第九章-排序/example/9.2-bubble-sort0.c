#include "9.1-sort.h"

void BubbleSort0(SqList * L)
{
  int i, j;
  for (i = 0; i < L->length; i++)
    for (j = i + 1; j < L->length; j++)
      if (L->r[i] > L->r[j])
        swap(L, i, j); // 若反序，则交换记录
}
