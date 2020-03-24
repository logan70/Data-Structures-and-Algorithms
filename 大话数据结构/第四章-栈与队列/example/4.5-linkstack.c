#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "4.4-linkstack.h"

void InitStack(LinkStack * S)
{
  S->top = NULL;
  S->count = 0;
}

void DestoryStack(LinkStack * S)
{
  ClearStack(S);
  free(S);
}

void ClearStack(LinkStack * S)
{
  StackNode * tmp;
  while (!StackEmpty(S))
  {
    tmp = S->top;
    S->top = S->top->next;
    free(tmp);
    S->count--;
  }
}

int StackLength(LinkStack * S)
{
  return S->count;
}

bool StackFull(LinkStack * S)
{
  return S->count == MAXSIZE;
}

bool StackEmpty(LinkStack * S)
{
  return S->count == 0;
}

bool GetTop(LinkStack * S, ElemType * e)
{
  if (StackEmpty(S))
    return false;
  *e = S->top->data;
  return true;
}

bool Push(LinkStack * S, ElemType e)
{
  StackNode * new;
  if (StackFull(S))
    return false;
  new = (StackNode *)malloc(sizeof(StackNode));
  new->data = e;
  new->next = S->top;
  S->top = new;
  S->count++;
  return true;
}

bool Pop(LinkStack * S, ElemType * e)
{
  StackNode * tmp;
  if (StackEmpty(S))
    return false;
  tmp = S->top;
  *e = tmp->data;
  S->top = S->top->next;
  free(tmp);
  S->count--;
  return true;
}
