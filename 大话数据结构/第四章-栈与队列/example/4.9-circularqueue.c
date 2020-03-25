#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "4.8-circularqueue.h"

void InitQueue(SqQueue * Q)
{
  Q->front = 0;
  Q->rear = 0;
}

void DestoryQueue(SqQueue * Q)
{
  ClearQueue(Q);
  free(Q);
}

void ClearQueue(SqQueue * Q)
{
  Q->front = 0;
  Q->rear = 0;
}

int QueueLength(const SqQueue * Q)
{
  return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

bool QueueFull(const SqQueue * Q)
{
  return (Q->rear + 1) % MAXSIZE == Q->front;
}

bool QueueEmpty(const SqQueue * Q)
{
  return Q->front == Q->rear;
}

bool GetHead(const SqQueue * Q, ElemType * e)
{
  if (QueueEmpty(Q))
    return false;
  *e = Q->data[Q->front];
  return true;
}

bool EnQueue(SqQueue * Q, ElemType e)
{
  if (QueueFull(Q))
    return false;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return true;
}

bool DeQueue(SqQueue * Q, ElemType * e)
{
  if (QueueEmpty(Q))
    return false;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return true;
}

