// 循环队列测试程序
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "4.8-circularqueue.h"

int main(void)
{
  int i;
  bool ok;
  SqQueue * queue = (SqQueue *)malloc(sizeof(SqQueue));
  InitQueue(queue);
  if (QueueEmpty(queue))
  {
    printf("Now queue is empty.\n");
  }
  for (i = 0; i < MAXSIZE; i++)
  {
    ok = EnQueue(queue, i);
    if (!ok)
      fprintf(stderr, "Queue is full, cannot push %d to the queue.\n", i);
    else
      printf("Successfully push %d to the top of queue\n", i);
  }
  if (QueueFull(queue))
  {
    printf("Now queue is full, queueLength is %d.\n", QueueLength(queue));
  }
  if (GetHead(queue, &i))
    printf("Head element is %d\n", i);
  if (DeQueue(queue, &i))
    printf("Now dequeue head element %d.\n", i);
  if (GetHead(queue, &i))
    printf("Now head element is %d, queue length is %d\n",
    i, QueueLength(queue));
  ClearQueue(queue);
  printf("After clear queue, length is %d.\n", QueueLength(queue));
  DestoryQueue(queue);
  printf("Bye!\n");
  return 0;
}
