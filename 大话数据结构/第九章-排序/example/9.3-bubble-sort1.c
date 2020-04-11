#include "9.1-sort.h"

void BubbleSort(SqList * L)
{
  int i, j;
  for (i = 0; i < L->length - 1; i++)
  {
    for (j = L->length - 2; j >= i; j--) // j从后往前循环
      if (L->r[j] > L->r[j + 1]) // 若前者大于后者
        swap(L, j, j + 1); // 则交换
  }
}
