#include <stdio.h>
#include <stdbool.h>
#include "8.9-avl.h"

void R_Rotate(BiTree * P)
{
  BiTree L;
  L = (*P)->lchild; // L指向P的左子树根结点
  (*P)->lchild = L->rchild; // L的右子树挂接为P的左子树
  L->rchild = (*P); // P挂接为L的右子树
  *P = L; // P指向新的根结点
}

void L_Rotate(BiTree * P)
{
  BiTree R;
  R = (*P)->rchild;
  (*P)->rchild = R->lchild;
  R->lchild = (*P);
  *P = R;
}

void LeftBalance(BiTree * T)
{
  BiTree L, Lr;
  L = (*T)->lchild; // L指向T的左子树根结点
  switch(L->bf)
  {
    // 检查T的左子树的平衡度，并作相应平衡处理
    case LH: // 新节点插入在T的左孩子的左子树上，要作单右旋处理
      (*T)->bf = L->bf = EH;
      R_Rotate(T);
      break;
    case RH: // 新节点插入在T的左孩子的右子树上，要作双旋处理
      Lr = L->rchild; // Lr指向T的左孩子的右子树根
      switch(Lr->bf) // 修改T及其左孩子的平衡因子
      {
        case LH:
          (*T)->bf = RH;
          L->bf = EH;
          break;
        case EH:
          (*T)->bf = L->bf = EH;
          break;
        case RH:
          (*T)->bf = EH;
          L->bf = LH;
          break;
      }
      Lr->bf = EH;
      L_Rotate(&(*T)->lchild); // 对T的左子树作左旋平衡处理
      R_Rotate(T); // 对T作右旋平衡处理
  }
}

void RightBalance(BiTree * T)
{
  BiTree R, Rl;
  R = (*T)->rchild; // L指向T的右子树根结点
  switch(R->bf)
  {
    // 检查T的右子树的平衡度，并作相应平衡处理
    case RH: // 新节点插入在T的右孩子的右子树上，要作单右旋处理
      (*T)->bf = R->bf = EH;
      L_Rotate(T);
      break;
    case LH: // 新节点插入在T的右孩子的左子树上，要作双旋处理
      Rl = R->lchild; // Lr指向T的右孩子的右子树根
      switch(Rl->bf) // 修改T及其右孩子的平衡因子
      {
        case RH:
          (*T)->bf = LH;
          R->bf = EH;
          break;
        case EH:
          (*T)->bf = R->bf = EH;
          break;
        case LH:
          (*T)->bf = EH;
          R->bf = RH;
          break;
      }
      Rl->bf = EH;
      R_Rotate(&(*T)->rchild); // 对T的右子树作右旋平衡处理
      L_Rotate(T); // 对T作左旋平衡处理
  }
}

bool InsertAVL(BiTree * T, int e, bool * taller)
{
  if (!*T) // 插入新结点，树长高，置taller为true
  {
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = e;
    (*T)->lchild = (*T)->rchild = NULL;
    (*T)->bf = EH;
    *taller = true;
  }
  else
  {
    if (e == (*T)->data)
    { // 树中已存在和e有相同关键字的结点则不再插入
      *taller = false;
      return false;
    }
    if (e < (*T)->data)
    { // 应继续在T的左子树中搜索插入位置
      if (!InsertAVL(&(*T)->lchild, e, taller)) // 未插入
        return false;
      if (taller) // 已插入T的左子树中且左子树长高
      {
        switch((*T)->bf) // 检查T的平衡度
        {
          case LH: // 原本左子树比右子树高，需要作平衡处理
            LeftBalance(T);
            *taller = false;
            break;
          case EH: // 原本左右子树等高，现在左子树增高
            (*T)->bf = LH;
            *taller = true;
            break;
          case RH: // 原本右子树比左子树高，现在左右子树等高
            (*T)->bf = EH;
            *taller = false;
            break;
        }
      }
    }
    else
    { // 应继续在T的右子树中进行搜索
      if (!InsertAVL(&(*T)->rchild, e, taller)) // 未插入
        return false;
      if (*taller) // 已插入右子树且右子树长高
      {
        switch((*T)->bf) // 检查T的平衡度
        {
          case LH: // 原本左子树比右子树高，现在左右子树等高
            (*T)->bf = EH;
            *taller = false;
            break;
          case EH: // 原本左右子树等高，先因右子树增高而树增高
            (*T)->bf = RH;
            *taller = true;
            break;
          case RH: // 原本右子树比左子树高，需要作右平衡处理
            RightBalance(T);
            *taller = false;
            break;
        }
      }
    }
  }
}