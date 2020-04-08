#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "8.5-bst.h"

bool Delete(BiTree * p)
{
  BiTree q, s;
  if ((*p)->rchild == NULL) // 右子树为空，重接左子树
  {
    q = *p;
    *p = (*p)->lchild;
    free(q);
  }
  else if ((*p)->lchild == NULL) // 左子树为空，重接右子树
  {
    q = *p;
    *p = (*p)->rchild;
    free(q);
  }
  else // 左右子树均不为空
  {
    q = *p; s = (*p)->lchild;
    // 寻找待删除结点的直接前驱结点
    while (s->rchild)
    {
      q = s;
      s = s->rchild;
    }
    // 将前驱结点数据复制到待删除结点
    (*p)->data = s->data;
    if (q != *p) // 如果直接前驱不是其左子节点，则将前驱结点左子树重接至其父节点右子树
      q->rchild = s->lchild;
    else // 直接前驱是待删除结点的左子节点，则重接其左子树至待删除结点的左子树
      q->lchild = s->lchild;
    free(s); // 删除前驱结点
  }
  return true;
}
