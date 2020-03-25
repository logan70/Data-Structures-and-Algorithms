// 4.11-linkqueue.h - 链队列结构定义及操作原型
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#define MAXSIZE 20
typedef int ElemType; // 数据元素类型根据实际情况而定，这里假设为int
typedef struct qnode {
  ElemType data;
  struct qnode * next;
} QNode;
typedef struct linkqueue {
  QNode * front; // 队头元素指针
  QNode * rear; // 队尾元素指针
  int length; // 队列长度
} LinkQueue;

/**
 * 操作：初始化循环队列
 * 前提条件：循环队列Q已存在
 * 后置条件：循环队列Q的头尾指针均初始化为0
 */
void InitQueue(LinkQueue * Q);

/**
 * 操作：销毁循环队列
 * 前提条件：循环队列Q已存在
 * 后置条件：将队列清空并将队列指针释放
 */
void DestoryQueue(LinkQueue * Q);

/**
 * 操作：将队列清空
 * 前提条件：循环队列Q已存在
 * 后置条件：将队列清空并将队列头尾指针初始化为0
 */
void ClearQueue(LinkQueue * Q);

/**
 * 操作：获取循环队列长度
 * 前提条件：循环队列Q已被初始化
 * 后置条件：返回循环队列长度
 */
int QueueLength(const LinkQueue * Q);

/**
 * 操作：检查循环队列是否为空
 * 前提条件：循环队列Q已被初始化
 * 后置条件：循环队列为空返回true，否则返回false
 */
bool QueueEmpty(const LinkQueue * Q);

/**
 * 操作：获得队头元素
 * 前提条件：循环队列Q已被初始化
 * 后置条件：队列不为空，用e返回循环队列Q队头元素，并返回true；否则返回false；
 */
bool GetHead(const LinkQueue * Q, ElemType * e);

/**
 * 操作：入列元素
 * 前提条件：循环队列Q已被初始化
 * 后置条件：若队列未满，则插入元素e作为新的队尾元素，返回true；否则返回false
 */
bool EnQueue(LinkQueue * Q, ElemType e);

/**
 * 操作：出列元素
 * 前提条件：循环队列Q已被初始化
 * 后置条件：若队列不为空，则删除Q中队头元素，用e返回其值，返回true，否则返回false
 */
bool DeQueue(LinkQueue * Q, ElemType * e);

#endif