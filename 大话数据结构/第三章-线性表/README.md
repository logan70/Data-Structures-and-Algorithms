# 第三章-线性表

**线性表（List）** ：零个或多个数据元素的有限序列。

## 线性表的抽象数据类型

```
ADT 线性表（List）
Data
  线性表的数据对象集合为（a1, a2, ..., an），每个元素的类型均为DataType。其中，出第一个元素a1外，每一个元素有且只有一个直接前驱元素，除了最后一个元素an外，每一个元素有且只有一个直接后继元素。数据元素之间的关系是一对一的关系。
Operation
  InitList(*L): 初始化操作，建立一个空的线性表L。
  ListEmpty(L): 若线性表为空，返回true，否则返回false。
  ClearList(*L): 将线性表清空。
  GetElem(L, i, *e): 将线性表L中的第i个位置元素值返回给e。
  LocateElem(L, e): 在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中的序号表示成功；否则，返回-1表示失败。
  ListInsert(*L, i, e): 在线性表L中的第i个位置插入新元素e。
  ListDelete(*L, i, *e): 删除线性表中第i个位置元素，并用e返回其值
  ListLength(L): 返回线性表L的元素个数
endADT
```

## 线性表的顺序存储结构

线性表的顺序存储结构，指的是用一段地址连续的存储单元依次存储线性表的数据元素。

可以用C语言的一维数组来实现线性表的顺序存储结构，详情见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.2-sqlist.h)。

> 在线性表的顺序存储结构中，可以算出任意位置的地址，所以存取操作的时间复杂度为`O(1)`，我们把具有这一特点的存储结构称为**随机存取结构**。

## 顺序存储结构的插入与删除

### 获得元素操作

> 时间复杂度为`O(1)`

对于线性表的顺序存储结构，获得元素，把数组第`i-1`下标的值返回即可，详见[示例程序sqlist.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.3-sqlist.c)中的 `GetElem()`函数。

### 插入操作

> 时间复杂度为`O(n)`

插入操作的思路如下：

- 如果插入位置不合理，抛出异常；
- 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量；
- 从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置；
- 将要插入的元素填入位置i处；
- 表长加1.

实现代码详见[示例程序sqlist.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.3-sqlist.c)中的 `ListInsert()`函数。

### 删除操作

> 时间复杂度为`O(n)`

删除操作的思路如下：

- 如果删除位置不合理，抛出异常；
- 取出删除元素；
- 从删除元素位置开始遍历到最后一个元素位置，分别将他们都向前移动一个位置；
- 表长减1。

实现代码详见[示例程序sqlist.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.3-sqlist.c)中的 `ListDelete()`函数。

**线性表顺序存储结构的优缺点**

- 优点1：无须为表中元素之间的逻辑关系而增加额外的存储空间
- 优点2：可以快速地存取表中任一位置的元素
- 缺点1：插入和删除操作需要移动大量元素
- 缺点2：当线性表长度变化较大时，难以确定存储空间的容量
- 缺点3：造成存储空间的“碎片”

## 线性表的链式存储结构

### 线性表链式存储结构定义

为了表示没个数据元素ai与其直接后继数据元素ai+1之间的逻辑关系，对数据元素ai来说，除了存储本身的信息之外，还需存储一个指示其直接后继的信息（即直接后继的存储位置）。我们把存储数据元素信息的域称为数据域，把存储直接后继位置的域称为指针域。指针域中存储的信息称作指针或链。这两部分信息组成数据元素ai的存储映像，称为节点（Node）。

n个节点（ai的存储映像）链结成一个链表，即为线性表（a1,a2,...,an）的链式存储结构，因为此链表的每个节点中只包含一个指针域，所以叫做单链表。

## 单链表的读取

获得链表第i个索引数据的算法思路：

1. 声明一个结点pt指向链表第一个结点，初始化j从0开始；
2. 当j<=i时，遍历链表，让pt的指针向后移动，不断指向下一节点，j累加1；
3. 若找到链表末尾，则说明第i个元素不存在；
4. 否则查找成功，返回结点p的数据。

实现代码算法详见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.5-linklist.c)中的 `GetElem()`函数。

## 单链表的插入与删除

**单链表第i个数据插入结点的算法思路：**

1. 声明一个结点prev指向链表头结点，初始化j从0开始；
2. 当j<i-1时，遍历链表，让pt的指针向后移动，不断指向下一节点，j累加1；
3. 若找到链表末尾prev为空，则说明前驱元素不存在；
4. 若j>i-1，即i为小于等于0的值，插入位置非法；
5. 否则查找成功，在系统中生成一个空节点s；
6. 将数据元素elem赋值给s->elem；
7. 单链表插入标准语句 `s->next = prev->next; prev->next = s;`；
8. 返回成功。

实现代码算法详见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.5-linklist.c)中的 `ListInsert()`函数。

**单链表第i个数据删除结点的算法思路：**

1. 声明一个结点pt指向链表头结点，初始化j从0开始；
2. 当j<i-1时，遍历链表，让pt的指针向后移动，不断指向下一节点，j累加1；
3. 若找到链表末尾pt为空，则说明前驱元素不存在；
4. 若j>i-1，即i为小于等于0的值，删除位置非法；
5. 否则查找成功，将要删除的节点数据p->next赋值给tmp，
6. 将数据tmp->elem赋值给*elem；
7. 单链表的删除标准语句`pt->next = tmp->next;`
8. 释放tmp节点；
9. 返回成功。

实现代码算法详见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.5-linklist.c)中的 `ListDelete()`函数。

## 单链表的整表创建

**单链表整表创建的算法思路（头插法）：**

1. 声明一结点p和计数器变量i；
2. 初始化一空链表L；
3. 让L的头结点的指针指向NULL，即建立一个带头结点的单链表；
4. 循环：
   1. 生成一新结点赋值给p；
   2. 随机生成一数字赋值给p的数据域p->elem；
   3. 将p插入到头结点与前一新结点之间。

实现代码算法详见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.5-linklist.c)中的 `CreateListHead()`函数。

**单链表整表创建的算法思路（尾插法）：**

1. 声明两结点p、r和计数器变量i；
2. 初始化一空链表L；
3. 让L的头结点的指针指向NULL，即建立一个带头结点的单链表；
4. 让r指向L的头结点，r用来标记链表的尾节点。
5. 循环：
   1. 生成一新结点赋值给p；
   2. 随机生成一数字赋值给p的数据域p->elem；
   3. 将p插入到尾结点r之后；
   4. 更新尾结点r的指向为p。

实现代码算法详见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.5-linklist.c)中的 `CreateListTail()`函数。

## 单链表的整表删除

**单链表整表删除的算法思路：**

1. 声明一节点p和q；
2. 将第一个结点赋值给p；
3. 循环
   1. 将下一结点赋值给q；
   2. 释放p；
   3. 将q赋值给p。

实现代码算法详见[示例程序sqlist.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/example/3.5-linklist.c)中的 `ClearList()`函数。

## 单链表结构与顺序存储结构对比

- 若线性表需要频繁查找，很少进行插入和删除操作时，宜采用顺序存储结构。若需要频繁插入和删除时，宜采用单链表结构。
- 当线性表中的元素个数变化较大或者根本不知道有多大时，最好用单链表结构，这样可以不需要考虑存储空间大小问题。而如果事先知道线性表的大致长度，用顺序存储结构效率会高很多。

## 静态链表

用数组描述的链表叫做**静态链表**。

数组元素由两个数据域组成，data和cur。数据域data，用来存放数据元素；游标cur相当于单链表中的next指针，存放该元素的后继在数组中的下标。

另外会对数组第一个和最后一个元素作为特殊元素处理，不存数据。数组第一个元素的cur存放备用链表的第一个结点的下标；数组最后一个元素的cur则存放第一个有数值的元素的下标，相当于单链表中的头结点作用。

静态链表是为了给没有指针的高级语言设计的一种实现单链表能力的方法。

## 循环链表

**循环链表（circylar linked list）** ：将单链表中终端结点的指针端由空指针改为指向头结点，就使整个单链表形成一个环，这种头尾相接的单链表称为单循环链表。

通常，使用指向终端结点的尾指针来表示循环链表，这样查找开始结点和终端结点都很方便，如下图所示。

![循环链表](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/images/1-circylar-linked-list.png?raw=true)

例如合并两个循环链表，尾指针作用就体现出来了，只需要如下操作即可：

![合并两个循环链表](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/images/2-combine-two-circylar-linked-list.png?raw=true)

```c
p = rearA->next; // 保存A表的头结点
rearA->next = rearB->next->next; // B表第一个有值结点与A表尾结点相连
rearB->next = p; // 原A表头结点与B表尾结点相连
```

## 双向链表

**双向链表（double linked list）** 是在单链表的每个节点中，再设置一个指向其前驱结点的指针域。

双向链表的**插入操作**如下所示：

![双向链表的插入操作](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/images/3-double-linked-list-insert.png?raw=true)

```c
s->prior = p; // 把p赋值给s的前驱
s->next = p->next; // 把p->next赋值给s的后继
p->next->prior = s; // 把s赋值给p->next的前驱
p->next = s; // 把s赋值给p的后继
```

双向链表的**删除操作**如下所示：

![双向链表的删除操作](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/images/5-double-linked-list-delete.png?raw=true)

```c
p->prior->next = p->next; // 把p->next赋值给p->prior的后继
p->next->prior = p->prior; // 把p->prior赋值给p->next的前驱
free(p); // 释放p结点
```

双链表也可以是循环链表，非空的循环的带头结点的双向链表如下图所示：

![非空的循环的带头结点的双向链表](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%89%E7%AB%A0-%E7%BA%BF%E6%80%A7%E8%A1%A8/images/4-double-circular-linked-list-insert.png?raw=true)
