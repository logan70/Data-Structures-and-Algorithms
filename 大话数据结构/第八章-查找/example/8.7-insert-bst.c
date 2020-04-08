#include <stdbool.h>
#include <stdlib.h>
#include "8.5-bst.h"

bool InsertBST(BiTree * T, int key)
{
  BiTree p, s;
  if (!SearchBST(*T, key, NULL, &p)) // 查找不成功
  {
    s = (BiTree)malloc(sizeof(BiTNode));
    s->data = key;
    s->lchild = s->rchild = NULL;
    if (!p)
    {
      *T = s; // 插入s为新的根结点
      return true;
    }
    else if (key < p->data && p->lchild == NULL)
    {
      p->lchild = s; // 插入s为左孩子
      return true;
    }
    else if (key > p->data && p->rchild == NULL)
    {
      p->rchild = s; // 插入s为右孩子
      return true;
    }
    else
      return false;
  }
  else
    return false;
}