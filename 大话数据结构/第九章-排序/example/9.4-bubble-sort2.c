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
  puts("Before BubbleSort2:");
  printArr(L);
  BubbleSort2(L);
  puts("After BubbleSort2:");
  printArr(L);
  free(L);
  return 0;
}

void BubbleSort2(SqList * L)
{
  int i, j;
  bool changed = true;
  for (i = 0; i < L->length - 1 && changed; i++)
  {
    changed = false; // 将标志位置为false
    for (j = 0; j < L->length - 1 - i; j++) // j从后往前循环
      if (L->r[j] > L->r[j + 1]) // 若前者大于后者
      {
        swap(L, j, j + 1); // 则交换
        changed = true; // 如果有数据交换，将标志位置为true
      }
  }
}
