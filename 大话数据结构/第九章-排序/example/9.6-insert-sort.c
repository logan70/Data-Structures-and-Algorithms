#include "9.1-sort.h"

void InsertSort(SqList * L)
{
  int i, j, cur;
  for (i = 1; i < L->length; i++)
  {
    cur = L->r[i]; // 保存比较值
    for (j = i - 1; L->r[j] > cur; j--)
      L->r[j + 1] = L->r[j]; // 寻找插入位置
    L->r[j + 1] = cur; // 插入到正确位置
  }
}
