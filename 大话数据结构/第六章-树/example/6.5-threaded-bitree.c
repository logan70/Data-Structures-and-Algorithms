#include <stdio.h>
#include <stdlib.h>
#include "6.4-threaded-bitree.h"

BiThrNode * pre = NULL; // 全局变量，指向刚刚访问过的结点，用于二叉树线索化

void CreateBiThrTree(BiThrTree * T)
{
  ThrTElemType ch = getchar();
  if (ch == '#' || ch == '\n')
    *T = NULL;
  else
  {
    *T = (BiThrNode *)malloc(sizeof(BiThrNode));
    if (! *T)
    {
      fprintf(stderr, "Tree node generating error!\n");
      exit(EXIT_FAILURE);
    }
    (*T)->data = ch; // 生成根结点
    (*T)->LTag = Link;
    (*T)->RTag = Link;
    CreateBiThrTree(&(*T)->lchild);
    CreateBiThrTree(&(*T)->rchild);
  }
}

void InThreading(BiThrTree T)
{
  if (T == NULL)
    return;
  InThreading(T->lchild); // 1. 中序线索化左子树
  // 没有左孩子，则为前驱线索，指向刚访问过的元素
  if (!T->lchild)
  {
    T->LTag = Thread;
    T->lchild = pre;
  }
  // 前驱没有右孩子，则将前驱的后继线索指向当前节点
  if (pre && !pre->rchild)
  {
    pre->RTag = Thread;
    pre->rchild = T;
  }
  pre = T; // 进入下次迭代前更新前驱元素
  InThreading(T->rchild); // 3. 中序线索化右子树
}

void InOrderTraverse(const BiThrTree T, void (* pfun)(ThrTElemType e))
{
  if (T == NULL)
    return;
  InOrderTraverse(T->lchild, pfun); // 1. 中序遍历左子树
  (*pfun)(T->data);           // 2. 访问结点数据
  InOrderTraverse(T->rchild, pfun); // 3. 中序遍历右子树
}

void InOrderTraverse_Thr(const BiThrTree T, void (* pfun)(ThrTElemType e))
{
  BiThrNode * p = T;
  while (p != NULL)
  {
    while (p->LTag == Link)
      p = p->lchild;
    (*pfun)(p->data);
    while (p->RTag == Thread && p->rchild != NULL)
    {
      p = p->rchild;
      (*pfun)(p->data);
    }
    p = p->rchild;
  }
}