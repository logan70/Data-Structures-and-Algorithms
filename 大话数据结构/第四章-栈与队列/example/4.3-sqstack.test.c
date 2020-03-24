// 顺序栈测试程序
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "4.1-sqstack.h"

int main(void)
{
  int i;
  bool ok;
  SqStack * stack = (SqStack *)malloc(sizeof(SqStack));
  InitStack(stack);
  if (StackEmpty(stack))
  {
    printf("Now stack is empty.\n");
  }
  for (i = 0; i < MAXSIZE + 5; i++)
  {
    ok = Push(stack, i);
    if (!ok)
      fprintf(stderr, "Stack is full, cannot push %d to the stack.\n", i);
    else
      printf("Successfully push %d to the top of stack\n", i);
  }
  if (StackFull(stack))
  {
    printf("Now stack is full, stackLength is %d.\n", StackLength(stack));
  }
  if (GetTop(stack, &i))
    printf("Top element is %d\n", i);
  if (Pop(stack, &i))
    printf("Now delete %d from top of stack.\n", i);
  if (GetTop(stack, &i))
    printf("Now top element is %d, stack length is %d\n",
    i, StackLength(stack));
  ClearStack(stack);
  printf("After clear stack, length is %d.\n", StackLength(stack));
  DestoryStack(stack);
  printf("Bye!\n");
  return 0;
}
