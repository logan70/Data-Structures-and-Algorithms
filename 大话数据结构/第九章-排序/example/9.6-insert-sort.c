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
  puts("Before InsertSort:");
  printArr(L);
  InsertSort(L);
  puts("After InsertSort:");
  printArr(L);
  free(L);
  return 0;
}

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
