#include <stdbool.h>
#ifndef _THREADED_BI_TREE_H_
#define _THREADED_BI_TREE_H_

typedef char ThrTElemType;
typedef enum { Link, Thread } PointerTag;
typedef struct biThrNode
{
  ThrTElemType data;
  struct biThrNode * lchild, * rchild;
  PointerTag LTag, RTag;
} BiThrNode, * BiThrTree;

void CreateBiThrTree(BiThrTree * T);
void InThreading(BiThrTree T);
void InOrderTraverse(BiThrTree T, void (* pfun)(ThrTElemType e));
void InOrderTraverse_Thr(BiThrTree T, void (* pfun)(ThrTElemType e));

#endif