#include <stdio.h>
#include <stdbool.h>
#include "3.1-sqlist.h"

void InitList(SqList * L)
{
  L->length = 0;
}

bool ListIsFull(SqList * L)
{
  return L->length == MAXSIZE;
}

bool ListIsEmpty(SqList * L)
{
  return L->length == 0;
}

int ListLength(SqList * L)
{
  return L->length;
}

bool GetElem(SqList * L, int i, ElemType * e)
{
  if (ListIsEmpty(L))
  {
    fprintf(stderr, "List is empty!\n");
    return false;
  }
  if (i < 0 || i > ListLength(L) - 1)
  {
    fprintf(stderr, "Invalid index!\n");
    return false;
  }
  *e = L->data[i];
  return true;
}

bool ListInsert(SqList * L, int i, ElemType e)
{
  int k;
  if (ListIsFull(L))
  {
    fprintf(stderr, "List is full!\n");
    return false;
  }
  if (i < 0 || i > ListLength(L) - 1)
  {
    fprintf(stderr, "Invalid index!\n");
    return false;
  }
  for (k = ListLength(L) - 1; k > i; k--)
    L->data[k + 1] = L->data[k];
  L->data[i] = e;
  L->length++;
  return true;
}

bool ListDelete(SqList * L, int i, ElemType * e)
{
  int k;
  if (ListIsEmpty(L))
  {
    fprintf(stderr, "List is empty!\n");
    return false;
  }
  if (i < 0 || i > ListLength(L) - 1)
  {
    fprintf(stderr, "Invalid index!\n");
    return false;
  }
  *e = L->data[i];
  for (k = i; k < ListLength(L) - 1; k++)
    L->data[k] = L->data[k + 1];
  L->length--;
  return true;
}
