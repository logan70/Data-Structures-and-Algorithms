#include <stdbool.h>
// 二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
  int data;
  struct BiTNode * lchild, * rchild;
} BiTNode, * BiTree;

/**
 * 二叉排序树【查找操作】
 * 递归查找二叉排序树T中是否存在key
 * 指针f指向T的父节点，其初始调用值为NULL
 * 若查找成功，则指针p指向该数据元素结点，并返回true
 * 否则指针p指向查找路径上访问的最后一个结点，并返回false
 */
bool SearchBST(BiTree T, int key, BiTree f, BiTree * p);

/**
 * 二叉排序树【插入操作】
 * 当二叉排序树T中不存在关键字等于key的数据元素时
 * 插入key并返回true，否则返回false
 */
bool InsertBST(BiTree * T, int key);

/**
 * 二叉排序树【删除操作】
 * 从二叉排序树中删除结点p，并重接它的左或右子树
 */
bool Delete(BiTree * p);