// 斐波那契的递归函数
#include <stdio.h>
int Fibonacci(int i);

int main(void)
{
  const int times = 40;
  for (int i = 0; i < times; i++)
    printf("%d ", Fibonacci(i));
  putchar('\n');
  return 0;
}

int Fibonacci(int i)
{
  if (i < 2)
    return i == 0 ? 0 : 1;
  return Fibonacci(i - 1) +  Fibonacci(i - 2);
}
