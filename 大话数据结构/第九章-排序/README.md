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

## 简单选择排序

**简单选择排序法（Simple Selection Sort）** 就是通过`n - i`次关键字间的比较，从`n - i + 1`个记录中选出关键字最小的记录，并和第(0 <= i < n)个记录交换之。

简单选择排序算法的代码实现详见 [示例程序 select-sort.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.5-select-sort.c)

### 简单选择排序复杂度分析

**时间复杂度** ：简单选择排序时间复杂度为`O(n^2)`。

**空间复杂度** ：`O(1)`。

**稳定性** ：先序同关键字元素可能被交换至后续同关键字元素之后，不稳定。

## 直接插入排序

**直接插入排序（Straight Insertion Sort）** 的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表。

插入排序的代码实现详见 [示例程序 insert-sort.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.6-insert-sort.c)

插入排序的过程如下图所示：

![插入排序](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/images/2-insert-sort.gif?raw=true)

### 直接插入排序复杂度分析

**时间复杂度** ：直接插入排序时间复杂度为`O(n^2)`，最好情况`O(n)`。

**空间复杂度** ：`O(1)`。

**稳定性** ：稳定。

## 希尔排序

**希尔排序（Shell Sort）** 将相距某个“增量”的记录组成一个子序列，子序列内分别进行直接插入排序，使得整个序列基本有序，然后不断缩小增量，重复进行插入排序，直至增量为1。

希尔排序的代码实现详见 [示例程序 shell-sort.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.7-shell-sort.c)

希尔排序的过程如下图所示：

![希尔排序](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/images/3-shell-sort.gif?raw=true)

### 希尔排序复杂度分析

**时间复杂度** ：希尔排序时间复杂度为`O(n^(1.3—2))`。

**空间复杂度** ：`O(1)`。

**稳定性** ：跳跃式移动，不稳定。

## 堆排序

**堆（Heap）** 是具有下列性质的完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。

**堆排序（Heap Sort）** 就是利用堆（假设利用大顶堆）进行排序的方法。它的基本思想是：将待排序的序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根结点。将它移走（其实就是将其与堆数组的末尾元素交换，此时末尾元素就是最大值），然后将剩余n-1个序列重新构造成一个堆，这样就会得到n个元素中的次大值。如此反复执行，便能得到一个有序序列了。

堆排序的代码实现详见 [示例程序 heap-sort.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B9%9D%E7%AB%A0-%E6%8E%92%E5%BA%8F/example/9.8-heap-sort.c)

### 堆排序复杂度分析

**时间复杂度** ：堆排序时间复杂度为`O(nlogn)`，堆排序对原始记录的排序状态并不敏感，因此最好、最坏和平均时间复杂度都是`O(nlogn)`。

**空间复杂度** ：`O(1)`。

**稳定性** ：记录的比较与交换是跳跃式进行，不稳定。

