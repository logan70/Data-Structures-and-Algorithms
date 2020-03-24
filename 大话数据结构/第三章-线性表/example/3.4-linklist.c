#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "3.3-linklist.h"

void CreateListHead(LinkList * plist, int n)
{
  Node * pt;
  int i;
  srand((unsigned int)time(0)); // 初始化随机数种子
  *plist = (Node *)malloc(sizeof(Node)); // 建立头结点
  (*plist)->next = NULL;
  for (i = 0; i < n; i++)
  {
    pt = (Node *)malloc(sizeof(Node));
    pt->elem = rand() % 100 + 1;
    pt->next = (*plist)->next;
    (*plist)->next = pt; // 插入到表头
  }
}

void CreateListTail(LinkList * plist, int n)
{
  Node * pt, * r;
  int i;
  srand((unsigned int)time(0)); // 初始化随机数种子
  *plist = (Node *)malloc(sizeof(Node)); // 建立头结点
  (*plist)->next = NULL;
  r = (*plist);
  for (i = 0; i < n; i++)
  {
    // 生成新结点
    pt = (Node *)malloc(sizeof(Node));
    pt->elem = rand() % 100 + 1;
    pt->next = NULL;
    r->next = pt; // 将尾节点的next指针指向pt
    r = pt; // 更新尾结点指向新插入的结点pt
  }
}

void InitializeLinkList(LinkList * plist)
{
  *plist = (Node *)malloc(sizeof(Node));
  (*plist)->next = NULL;
}

bool LinkListIsEmpty(const LinkList * plist)
{
  return (*plist)->next == NULL;
}

unsigned int LinkListItemCount(const LinkList * plist)
{
  unsigned int count = 0;
  // 跳过头结点
  Node * tmp = (*plist)->next;
  while (tmp != NULL)
  {
    count++;
    tmp = tmp->next;
  }
  return count;
}

bool GetElem(LinkList * plist, int i, ElemType * elem)
{
  int j = 1;
  Node * pt = (*plist)->next;
  while (pt && j < i)
  {
    pt = pt->next;
    j++;
  }
  if (pt == NULL || j > i) // i超出范围未找到结点或者小于1
  {
    fprintf(stderr, "Invalid index!\n");
    return false;
  }
  *elem = pt->elem;
  return true;
}

bool ListInsert(LinkList * plist, int i, ElemType elem)
{
  int j = 0;
  Node * prev = *plist;
  Node * s;
  // 寻找插入位置的前驱元素
  while (prev && j < i - 1)
  {
    prev = prev->next;
    j++;
  }
  // 如果插入位置过大，前驱元素为NULL
  // 如果插入位置小于等于0，则j>i-1
  if (j > i - 1 || prev == NULL)
  {
    fprintf(stderr, "Invalid insert position!\n");
    return false;
  }
  s = (Node *)malloc(sizeof(Node));
  s->elem = elem;
  s->next = prev->next;
  prev->next = s;
  return true;
}

bool ListDelete(LinkList * plist, int i, ElemType * elem)
{
  int j = 0;
  Node * prev = *plist;
  Node * tmp;
  // 搜索删除位置的前驱元素
  while (prev->next != NULL && j < i - 1)
  {
    prev = prev->next;
    j++;
  }
  // 如果删除位置无内容，则prev->next为NULL
  // 如果删除位置小于等于0，则j>i-1
  if (j > i - 1 || prev->next == NULL)
  {
    fprintf(stderr, "Invalid delete position!\n");
    return false;
  }
  tmp = prev->next;
  *elem = tmp->elem;
  prev->next = tmp->next;
  free(tmp);
  return true;
}

void ClearList(LinkList * plist)
{
  Node * p, * q;
  p = (*plist)->next;
  while (p)
  {
    q = p->next;
    free(p);
    p = q;
  }
  (*plist)->next = NULL; // 头结点指针域为空
}

void Traverse(const LinkList * plist, void(*pfun)(ElemType elem))
{
  Node * pt = (*plist)->next;
  while (pt)
  {
    (*pfun)(pt->elem);
    pt = pt->next;
  }
}