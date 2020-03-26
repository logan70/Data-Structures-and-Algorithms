#include <stdio.h>
#include <stdlib.h>
#include "6.1-bitree.h"
#include "linkqueue.h"

void CreateBiTree(BiTree * T)
{
  TElemType ch = getchar();
  if (ch == '#' || ch == '\n')
    *T = NULL;
  else
  {
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    if (! *T)
    {
      fprintf(stderr, "Tree node generating error!\n");
      exit(EXIT_FAILURE);
    }
    (*T)->data = ch; // 生成根结点
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
  }
}

void PreOrderTraverse(const BiTree T, void (* pfun)(TElemType e))
{
  if (T == NULL)
    return;
  (*pfun)(T->data);            // 1. 访问结点数据
  PreOrderTraverse(T->lchild, pfun); // 2. 前序遍历左子树
  PreOrderTraverse(T->rchild, pfun); // 3. 前序遍历右子树
}

void InOrderTraverse(const BiTree T, void (* pfun)(TElemType e))
{
  if (T == NULL)
    return;
  InOrderTraverse(T->lchild, pfun); // 1. 中序遍历左子树
  (*pfun)(T->data);           // 2. 访问结点数据
  InOrderTraverse(T->rchild, pfun); // 3. 中序遍历右子树
}

void PostOrderTraverse(const BiTree T, void (* pfun)(TElemType e))
{
  if (T == NULL)
    return;
  PostOrderTraverse(T->lchild, pfun); // 1. 后续遍历左子树
  PostOrderTraverse(T->rchild, pfun); // 2. 后续遍历右子树
  (*pfun)(T->data);             // 3. 访问结点数据
}

void BFSTraverse(const BiTree T, void (* pfun)(TElemType e))
{
  LinkQueue * queue = (LinkQueue *)malloc(sizeof(LinkQueue));
  BiTNode * tmp = (BiTNode *)malloc(sizeof(BiTNode));
  InitQueue(queue);
  EnQueue(queue, *T);
  while (DeQueue(queue, tmp))
  {
    (*pfun)(tmp->data);
    if (tmp->lchild)
      EnQueue(queue, *tmp->lchild);
    if (tmp->rchild)
      EnQueue(queue, *tmp->rchild);
  }
  DestoryQueue(queue);
  free(tmp);
}
