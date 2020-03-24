// sqlist.c - 线性表的顺序存储结构
#ifndef _SQLIST_H_
#define _SQLIST_H_

#define MAXSIZE 20
typedef int ElemType; // 数据元素类型根据实际情况而定，这里假设为int
typedef struct sqlist {
  ElemType data[MAXSIZE]; // 数组存储数据元素，最大个数为MAXSIZE
  int length; // 线性表当前长度，任意时刻都小于等于数组长度MAXSIZE
} SqList;

/**
 * 操作：初始化顺序线性表
 * 前提条件：顺序线性表L已存在
 * 后置条件：顺序线性表L的长度初始化为0
 */
void InitList(SqList * L);

/**
 * 操作：获取顺序线性表长度
 * 前提条件：顺序线性表L已被初始化
 * 后置条件：返回顺序线性表长度
 */
int ListLength(SqList * L);

/**
 * 操作：检查顺序线性表是否已满
 * 前提条件：顺序线性表L已被初始化
 * 后置条件：顺序线性表已满返回true，否则返回false
 */
bool ListIsFull(SqList * L);

/**
 * 操作：检查顺序线性表是否为空
 * 前提条件：顺序线性表L已被初始化
 * 后置条件：顺序线性表为空返回true，否则返回false
 */
bool ListIsEmpty(SqList * L);

/**
 * 操作：获得元素
 * 前提条件：顺序线性表L已被初始化，0<=i<=ListLength(L) - 1
 * 后置条件：用e返回L中第i-1个数据元素的值
 */
bool GetElem(SqList * L, int i, ElemType * e);

/**
 * 操作：插入元素
 * 前提条件：顺序线性表L已被初始化，0<=i<=ListLength(L) - 1
 * 后置条件：在L中第i个位置插入新的数据元素e，L的长度加1
 */
bool ListInsert(SqList * L, int i, ElemType e);

/**
 * 操作：删除元素
 * 前提条件：顺序线性表L已被初始化，0<=i<=ListLength(L) - 1
 * 后置条件：删除在L中第i个位置的数据元素e，L的长度减1
 */
bool ListDelete(SqList * L, int i, ElemType * e);

#endif