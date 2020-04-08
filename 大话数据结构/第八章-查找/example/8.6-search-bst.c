#include <stdbool.h>
#include "8.5-bst.h"

bool SearchBST(BiTree T, int key, BiTree f, BiTree * p)
{
  if (!T) // 查找不成功
  {
    *p = f;
    return false;
  }
  else if (key == T->data) // 查找成功
  {
    *p = T;
    return true;
  }
  else if (key < T->data)
  {
    return SearchBST(T->lchild, key, T, p); // 在左子树递归查找
  }
  else
  {
    return SearchBST(T->rchild, key, T, p); // 在右子树递归查找
  }
}
