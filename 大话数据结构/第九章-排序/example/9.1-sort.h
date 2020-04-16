#include <stdio.h>
#define MAXSIZE 10 // 要排序的数组元素个数
typedef struct
{
  int r[MAXSIZE + 1]; // 用于存储要排序数组，r[0]用作哨兵或临时变量
  int length; // 用于记录顺序表的长度
} SqList;

/**
 * 对顺序表L作交换排序（冒泡排序初级版）
 */
void BubbleSort0(SqList * L);

/**
 * 对顺序表L作冒泡排序
 */
void BubbleSort(SqList * L);

/**
 * 对顺序表L作冒泡排序，并使用标志位进行优化
 */
void BubbleSort2(SqList * L);

/**
 * 对顺序表L作简单选择排序
 */
void SelectSort(SqList * L);

/**
 * 堆顺序表L进行堆排序
 */
void HeapSort(SqList * L);

/**
 * 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义
 * 本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
 */
void Heapify(SqList * L, int s, int m);


// 交换L中数组r的下标为i和j的数
void swap(SqList * L, int i, int j)
{
  int temp = L->r[i];
  L->r[i] = L->r[j];
  L->r[j] = temp;
}

void printArr(SqList * L)
{
  for (int i = 0; i < L->length; i++)
    printf("%d ", L->r[i]);
  putchar('\n');
}
