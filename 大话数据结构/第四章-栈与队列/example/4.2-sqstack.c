#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "4.1-sqstack.h"

void InitStack(SqStack * S)
{
  S->top = -1;
}

void DestoryStack(SqStack * S)
{
  ClearStack(S);
  free(S);
}

void ClearStack(SqStack * S)
{
  S->top = -1;
}

int StackLength(SqStack * S)
{
  return S->top + 1;
}

bool StackFull(SqStack * S)
{
  return S->top + 1 == MAXSIZE;
}

bool StackEmpty(SqStack * S)
{
  return S->top == -1;
}

bool GetTop(SqStack * S, ElemType * e)
{
  if (StackEmpty(S))
    return false;
  *e = S->data[S->top];
  return true;
}

bool Push(SqStack * S, ElemType e)
{
  if (StackFull(S))
    return false;
  S->data[++S->top] = e;
  return true;
}

bool Pop(SqStack * S, ElemType * e)
{
  if (StackEmpty(S))
    return false;
  *e = S->data[S->top--];
  return true;
}
