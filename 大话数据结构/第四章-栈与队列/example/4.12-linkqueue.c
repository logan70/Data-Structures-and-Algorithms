#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "4.11-linkqueue.h"

void InitQueue(LinkQueue * Q)
{
  QNode * front = (QNode *)malloc(sizeof(QNode));
  Q->front = front;
  Q->rear = Q->front;
  Q->length = 0;
}

void DestoryQueue(LinkQueue * Q)
{
  ClearQueue(Q);
  free(Q);
}

void ClearQueue(LinkQueue * Q)
{
  int i;
  while (!QueueEmpty(Q))
  DeQueue(Q, &i);
}

int QueueLength(const LinkQueue * Q)
{
  return Q->length;
}

bool QueueEmpty(const LinkQueue * Q)
{
  return Q->front == Q->rear;
}

bool GetHead(const LinkQueue * Q, ElemType * e)
{
  if (QueueEmpty(Q))
    return false;
  *e = Q->front->next->data;
  return true;
}

bool EnQueue(LinkQueue * Q, ElemType e)
{
  QNode * new = (QNode *)malloc(sizeof(QNode));
  if (!new)
    return false;
  new->data = e;
  new->next = NULL;
  Q->rear->next = new;
  Q->rear = new;
  Q->length++;
  return true;
}

bool DeQueue(LinkQueue * Q, ElemType * e)
{
  QNode * tmp;
  if (QueueEmpty(Q))
    return false;
  tmp = Q->front->next;
  *e = tmp->data;
  Q->front->next = tmp->next;
  if (Q->rear == tmp) // 若为空，则将尾指针指向头指针
    Q->rear = Q->front;
  free(tmp);
  Q->length--;
  return true;
}
