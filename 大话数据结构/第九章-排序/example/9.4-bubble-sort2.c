#include <stdbool.h>
#include "9.1-sort.h"

void BubbleSort2(SqList * L)
{
  int i, j;
  bool changed = true;
  for (i = 0; i < L->length - 1 && changed; i++)
  {
    changed = false; // 将标志位置为false
    for (j = L->length - 2; j >= i; j--) // j从后往前循环
      if (L->r[j] > L->r[j + 1]) // 若前者大于后者
      {
        swap(L, j, j + 1); // 则交换
        changed = true; // 如果有数据交换，将标志位置为true
      }
  }
}
