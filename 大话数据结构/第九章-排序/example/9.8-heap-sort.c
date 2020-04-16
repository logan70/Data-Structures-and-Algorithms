#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "9.1-sort.h"

int main(void)
{
  SqList * L = (SqList *)malloc(sizeof(SqList));
  memcpy(L->r, (int []){8, 6, 4, 3, 5, 9, 1, 7, 2}, sizeof(int) * 9);
  L->length = 9;
  puts("Before HeapSort:");
  printArr(L);
  HeapSort(L);
  puts("After HeapSort:");
  printArr(L);
  free(L);
  return 0;
}

void HeapSort(SqList * L)
{
  int i;
  for (i = (L->length - 1) / 2; i >= 0; i--) // 原序列构建大顶堆
    Heapify(L, i, L->length);
  
  for (i = L->length - 1; i > 0; i--)
  {
    swap(L, 0, i); // 将堆顶记录和当前未排序子序列的最后一个记录交换
    Heapify(L, 0, i); // 将L->r[0...i - 1]重新调整为大顶堆
  }
}

/**
 * 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义
 * 本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
 */
void Heapify(SqList * L, int s, int m)
{
  int temp, j;
  temp = L->r[s];
  for (j = 2 * s + 1; j < m; j = 2 * j + 1)
  {
    if (j < m - 1 && L->r[j] < L->r[j + 1])
      ++j;
    if (temp >= L->r[j])
      break;
    L->r[s] = L->r[j];
    s = j;
  }
  L->r[s] = temp;
}