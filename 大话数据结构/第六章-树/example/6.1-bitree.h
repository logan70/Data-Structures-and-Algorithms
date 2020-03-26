#include <stdbool.h>
#ifndef _BI_TREE_H_
#define _BI_TREE_H_

typedef char TElemType;
typedef struct biTNode
{
  TElemType data;
  struct biTNode * lchild, * rchild;
} BiTNode, * BiTree;

void CreateBiTree(BiTree * T);
void PreOrderTraverse(BiTree T, void (* pfun)(TElemType e));
void InOrderTraverse(BiTree T, void (* pfun)(TElemType e));
void PostOrderTraverse(BiTree T, void (* pfun)(TElemType e));
void BFSTraverse(BiTree T, void (* pfun)(TElemType e));

#endif