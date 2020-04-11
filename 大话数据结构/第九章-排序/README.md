# 第九章-排序

## 排序的基本概念与分类

### 排序的稳定性

排序关键字相等的两条记录，如果在排序后先后序列不变，则称所用的排序方法是稳定的；反之则称所用的排序方法是不稳定的。

### 内排序与外排序

根据在排序过程中待排序的记录是否全部放置在内存中，排序分为：**内排序**和**外排序**。

**内排序** ：在排序整个过程中，待排序的所有记录全部被放置在内存中。

**外排序** ：由于排序的记录个数太多，不能同时放置在内存，整个排序过程需要在内外村之间多次交换数据才能进行。

### 排序用到的结构与函数

排序用到的结构与函数详见 [示例程序 sort.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.1-sort.h)

## 冒泡排序

**冒泡排序（Bubble Sort）** 是一种交换排序，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，知道没有反序的记录位置。

最简单交换排序代码实现详见 [示例代码 bubble-sort0.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.2-bubble-sort0.c) ，这个排序算法并不是标准冒泡排序算法，因为它不满足“两两比较相邻记录”的冒泡排序思想。

标准的冒泡排序代码实现详见 [示例程序 bubble-sort1.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.3-bubble-sort1.c)。

冒泡排序第一轮执行结果如下图所示：

![冒泡排序](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/images/1-bubble-sort.png?raw=true)

### 冒泡排序优化

在一轮子循环中，如果未发生任何交换，则说明此序列已经有序，不需要继续后面的循环，借用一个标记变量来实现改进，优化后的代码详见 [示例程序 bubble-sort3.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.4-bubble-sort2.c)

### 冒泡排序复杂度分析

**时间复杂度** ：冒泡排序时间复杂度为`O(n^2)`，最好情况`O(n)`，即序列本来就是有序的。

**空间复杂度** ：`O(1)`。

**稳定性** ：稳定。