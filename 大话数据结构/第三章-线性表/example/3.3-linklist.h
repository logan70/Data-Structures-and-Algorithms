#include <stdbool.h>
// 线性表的单链表存储结构
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef int ElemType;
typedef struct node
{
  ElemType elem;
  struct node * next;
} Node;
typedef Node * LinkList;
// 函数原型
/**
 * 操作：初始化一个链表
 * 前提条件：plist指向一个链表
 * 后置条件：链表初始化微空
 */
void InitializeLinkList(LinkList * plist);

/**
 * 操作：创建单链表(头插法)
 * 前提条件：plist指向一个链表，n为要插入的结点数
 * 后置条件：随机产生n个元素的值，建立带头结点的单链表plist
 */
void CreateListHead(LinkList * plist, int n);

/**
 * 操作：创建单链表(尾插法)
 * 前提条件：plist指向一个链表，n为要插入的结点数
 * 后置条件：随机产生n个元素的值，建立带头结点的单链表plist
 */
void CreateListTail(LinkList * plist, int n);

/**
 * 操作：确定链表是否为空定义，plist指向一个已初始化的链表
 * 后置条件：如果链表为空，该函数返回true，否则返回false
 */
bool LinkListIsEmpty(const LinkList * plist);

/**
 * 操作：确定链表中的项数，plist指向一个已初始化的链表
 * 后置条件：该函数返回链表中的项数
 */
unsigned int LinkListItemCount(const LinkList * plist);

/**
 * 操作：在链表中搜索第i项
 * 前提条件：plist指向一个已初始化的链表
 * 后置条件：用e返回链表中第i个数据元素的值，搜索成功返回true，否则返回false
 */
bool GetElem(LinkList * plist, int i, ElemType * elem);

/**
 * 操作：在链表的第i个位置添加项
 * 前提条件：elem是一个待添加至列表的项，plist指向一个已初始化的链表
 * 后置条件：如果可以，该函数在链表第i个位置添加一个项，且返回true；否则返回false
 */
bool ListInsert(LinkList * plist, int i, ElemType elem);

/**
 * 操作：删除链表的第i个位置添加项
 * 前提条件：plist指向一个已初始化的链表
 * 后置条件：如果可以，该函数将链表第i个位置的数据写入elem，删除该项，且返回true；否则返回false
 */
bool ListDelete(LinkList * plist, int i, ElemType * elem);

/**
 * 操作：把函数作用于链表中的每一项
 * 前置条件：plist指向一个已初始化的链表；
 *         pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值
 * 后置条件：pfun指向的函数作用于链表中的每一项一次
 */
void Traverse(const LinkList * plist, void(*pfun)(ElemType elem));

/**
 * 操作：释放已分配的内存（如果有的话）
 * 前置条件：plist指向一个已初始化的链表
 * 后置条件：释放了为链表分配的所有内存，链表设置为空
 */
void ClearList(LinkList * plist);
#endif