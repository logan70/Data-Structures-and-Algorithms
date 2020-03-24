// 4.4-linkstack.h - 链栈结构定义及操作原型
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#define MAXSIZE 20
typedef int ElemType; // 数据元素类型根据实际情况而定，这里假设为int
typedef struct stacknode {
  ElemType data;
  struct stacknode * next;
} StackNode;
typedef struct linkstack {
  StackNode * top; // 栈顶元素指针
  int count; // 栈内元素个数
} LinkStack;

/**
 * 操作：初始化顺序栈
 * 前提条件：顺序栈S已存在
 * 后置条件：顺序栈S的栈顶指针初始化为-1
 */
void InitStack(LinkStack * S);

/**
 * 操作：销毁顺序栈
 * 前提条件：顺序栈S已存在
 * 后置条件：将栈清空并将栈指针释放
 */
void DestoryStack(LinkStack * S);

/**
 * 操作：将栈清空
 * 前提条件：顺序栈S已存在
 * 后置条件：将栈清空并将栈顶指针重置为-1
 */
void ClearStack(LinkStack * S);

/**
 * 操作：获取顺序栈长度
 * 前提条件：顺序栈S已被初始化
 * 后置条件：返回顺序栈长度
 */
int StackLength(LinkStack * S);

/**
 * 操作：检查顺序栈是否已满
 * 前提条件：顺序栈S已被初始化
 * 后置条件：顺序栈已满返回true，否则返回false
 */
bool StackFull(LinkStack * S);

/**
 * 操作：检查顺序栈是否为空
 * 前提条件：顺序栈S已被初始化
 * 后置条件：顺序栈为空返回true，否则返回false
 */
bool StackEmpty(LinkStack * S);

/**
 * 操作：获得栈顶元素
 * 前提条件：顺序栈S已被初始化
 * 后置条件：用e返回栈顶数据元素的值
 */
bool GetTop(LinkStack * S, ElemType * e);

/**
 * 操作：元素入栈
 * 前提条件：顺序栈S已被初始化
 * 后置条件：若栈存在，插入新元素e到栈中并成为栈顶元素
 */
bool Push(LinkStack * S, ElemType e);

/**
 * 操作：元素出栈
 * 前提条件：顺序栈S已被初始化
 * 后置条件：若栈存在且非空，删除栈中的栈顶元素，并用e返回其值。
 */
bool Pop(LinkStack * S, ElemType * e);

#endif