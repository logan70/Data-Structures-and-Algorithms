# 第四章-栈与队列

## 栈的定义

**栈（stack）**是限定仅在表尾进行插入和删除操作的线性表。栈是后进先出（Last In First Out）的线性表，简称LIFO结构。

栈的插入操作，叫作进栈，也称压栈、入栈。

栈的删除操作，叫作出栈，也有的叫作弹栈。

## 栈的抽象数据类型

```c
ADT 栈(stack)
Data
  同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation
  InitStack(*S): 初始化操作，建立一个空栈S。
  DestroyStack(*S): 若栈存在，则销毁它。
  ClearStack(*S): 将栈清空。
  StackEmpty(*S): 若栈为空，返回true，否则返回false。
  GetTop(*S, *e): 若栈存在且非空，用e返回S的栈顶元素。
  Push(*S, e): 若栈存在，插入新元素e到栈中并成为栈顶元素。
  Pop(*S, *e): 若栈存在且非空，删除栈中的栈顶元素，并用e返回其值。
  StackLength(*S): 返回栈S的元素个数。
endADT
```

## 栈的顺序存储结构及实现

栈是线性表的特例，栈的顺序存储其实也是线性表顺序存储的简化，简称为**顺序栈**。

顺序栈的普通情况、空栈和栈满情况示意图如下。

![顺序栈的普通情况、空栈和栈满情况](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/1-stack-status.png?raw=true)

顺序栈的入栈操作如下图所示：

![入栈操作](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/2-stack-push.png?raw=true)

顺序栈结构及相关操作的定义详见[示例程序sqstack.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.1-sqstack.h)。

顺序栈相关操作的代码实现详见[示例程序sqstack.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.2-sqstack.c)。

顺序栈的测试程序代码详见[示例程序sqstack.test.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.3-sqstack.test.c)。

## 栈的链式存储结构及实现

栈的链式存储结构，简称为**链栈**。

链栈的示意图如下：

![链栈](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/3-linked-stack.png?raw=true)

链栈的入栈操作如下图所示：

![链栈的入栈操作](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/4-linked-stack-push.png?raw=true)

链栈的出栈操作如下图所示：

![链栈的出栈操作](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/5-linked-stack-pop.png?raw=true)

链栈结构及相关操作的定义详见[示例程序linkstack.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.4-linkstack.h)。

链栈相关操作的代码实现详见[示例程序linkstack.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.5-linkstack.c)。

链栈的测试程序代码详见[示例程序linkstack.test.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.6-linkstack.test.c)。

## 栈的应用-递归

### 斐波那契数列（Fibonacci）

斐波那契递归函数的代码实现详见[fibonacci-recursion.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.7-fibonacci-recursion.c)

### 递归定义

一个直接调用自己或通过一系列的调用语句间接地调用自己的函数，称作 **递归函数**。

> 每个递归定义必须至少有一个条件，满足时递归不再进行，即不再引用自身而是返回值退出。

递归过程退回的顺序是它前行顺序的逆序，符合栈数据结构，因此，编译器使用栈实现递归。

## 栈的应用-四则运算表达式求值

### 后缀（逆波兰）表示法定义

**逆波兰（Reverse Polish Notation, RPN）** ：不需要括号的后缀表达法。示例如下：

- 中缀表达式：`9 + (3 - 1) * 3 + 10 / 2`；
- 后缀表达式：`9 3 1 - 3 * + 10 2 / +`。

### 后缀表达式计算结果

从左到右遍历表达式的每个数字和符号，遇到数字就进栈，遇到是符号，就将处于栈顶两个数字出栈，进行运算，运算结果进栈，一直到最终获得结果。

### 中缀表达式转后缀表达式

从左到右遍历中缀表达式的的每个数字和符号，若是数字就输出，即成为后缀表达式的一部分；若是符号，则判断其与栈顶符号的优先级，是右括号或优先级低于栈顶符号（乘除优先加减），则栈顶元素依次出栈并输出，并将当前符号进栈，一直到最终输出后缀表达式为止。

例如中缀表达式`9+(3-1)*3+10/2`，其转换步骤如下：

1. 初始化一空栈，用来对符号进出栈使用。
2. 第一个字符是数字`9`，输出`9`，后面是符号`+`，进栈。
3. 第三个字符是`(`,依然是符号，因其只是左括号，还未配对，故进栈。
4. 第四个字符是数字`3`，输出，总表达式为`9 3`,接着是`-`进栈。
5. 接下来是数字`1`，输出，总表达式为`9 3 1`，后面是符号`)`，此时，我们需要去匹配此前的`(`，所以栈顶依次出栈，并输出，直到`(`出栈为止。此时左括号上方只有`-`，因此输出`-`，总的输出表达式为`9 3 1 -`
6. 紧接着是符号`*`，因为此时的栈顶符号为`+`号，优先级低于`*`，因此不输出，进栈。接着是数字`3`，输出，总的表达式为`9 3 1 - 3` 。
7. 之后是符号`+`，此时当前栈顶元素比这个`+`的优先级高，因此栈中元素出栈并输出（没有比`+`号更低的优先级，所以全部出栈），总输出表达式为 `9 3 1 - 3 * +`.然后将当前这个符号`+`进栈。也就是说，第二部栈底的`+`是指中缀表达式中开头的`9`后面那个`+`，而现在的`+`是指`9+(3-1)*3+`中的最后一个`+`。
8. 紧接着数字`10`，输出，总表达式变为`9 3 1-3 * + 10`。
9. 最后一个数字`2`,输出，总的表达式为`9 3 1-3*+ 10 2`
10. 因已经到最后，所以将栈中符号全部出栈并输出。最终输出的后缀表达式结果为`9 3 1-3*+ 10 2/+`

## 队列的定义

**队列（queue）** ：只允许在一端进行插入操作，而在另一端进行删除操作的线性表。

队列是一种先进先出（First In First Out，FIFO）的线性表。允许插入的一端称为队尾，允许删除的一端称为队头，如下图所示。

![队列](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/6-queue.png?raw=true)

## 队列的抽象数据类型

```
ADT 队列（Queue）
Data
  同线性表。元素具有相同类型，相邻元素具有前驱和后继关系。
Operation
  InitQueue(*Q): 初始化操作，建立一个空队列Q
  DestoryQueue(*Q): 若队列Q存在，则销毁它。
  ClearQueue(*Q): 将队列Q清空。
  QueueEmpty(*Q): 若队列Q为空，返回true，否则返回false。
  GetHead(*Q, *e): 若队列Q存在且非空，用e返回队列Q的队头元素。
  EnQueue(*Q, e): 若队列Q存在，插入新元素e到队列Q中并成为队尾元素。
  DeQueue(*Q, *e): 删除队列Q中队头元素，并用e返回其值。
  QueueLength(*Q): 返回队列Q的元素个数。
endADT
```

## 循环队列

队列顺序存储，入列操作是在队尾追加元素，时间复杂度为`O(1)`，但是出列操作，队列中所有元素都要向前移动，时间复杂度为`O(n)`。

如果使用头、尾指针标记，出列后不移动元素，还会存在“假溢出”的现象（入列时数组溢出但是队头仍有空闲位置）。

所以解决办法就是使用循环队列，**循环队列**是头尾相接的顺序存储结构。

为防止空队列和满队列时头尾指针都相同，空队列时头尾指针相同，满队列时保留一个元素空间，如下图所示。

![循环队列](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/images/7-circular-queue.png?raw=true)

- 队列满的条件是：`(rear + 1) % QueueSize == front`；
- 队列长度计算公式为：`(rear - front + QueueSize) % QueueSize`。

循环队列结构及相关操作的定义详见[示例程序circularqueue.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.8-circularqueue.h)。

循环队列相关操作的代码实现详见[示例程序circularqueue.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.9-circularqueue.c)。

循环队列的测试程序代码详见[示例程序circularqueue.test.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.10-circularqueue.test.c)。

## 队列的链式存储结构及实现

队列的链式存储结构，其实就是线性表的单链表，只不过只能尾进头出而异，我们把它简称为链队列。

链队列结构及相关操作的定义详见[示例程序linkqueue.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.11-linkqueue.h)。

链队列相关操作的代码实现详见[示例程序linkqueue.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.12-linkqueue.c)。

链队列的测试程序代码详见[示例程序linkqueue.test.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%9B%9B%E7%AB%A0-%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/example/4.13-linkqueue.test.c)。
