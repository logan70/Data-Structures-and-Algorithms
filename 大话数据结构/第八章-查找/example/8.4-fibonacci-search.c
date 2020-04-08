#include <stdio.h>
// 斐波那契查找
int Fibonacci_Search(int * a, int n, int key)
{
  // 1. 构建斐波那契数组，过程省略
  int F[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
  int * filledArr;
  int low, high, mid, i, k, lastEle;
  low = 0; // 定义最低下标为首位
  high = n - 1; // 定义最高下标为记录末位
  lastEle = a[high]; // 记录末位
  // 寻找大于等于查找数组项数的最小斐波那契项
  k = 0;
  while (n > F[k])
    k++;
  // 2. 创建填充数组并填充
  filledArr = (int *)malloc(F[k] * sizeof(int));
  for ( i = 0; i < F[k]; i++)
  {
    filledArr[i] = i < n ? a[i] : lastEle;
  }
  // 3. 进行排序
  while (low <= high)
  {
    mid = low + F[k - 1] - 1;
    if (key < filledArr[mid])
    {
      high = mid - 1;
      k = k - 1;
    }
    else if (key > filledArr[mid])
    {
      low = mid + 1;
      k = k - 2;
    }
    else
    {
      if (mid < n)
        return mid;
      else
        return n - 1; // 查询到的是补全数值，返回n-1
    }
  }
  return -1;
}