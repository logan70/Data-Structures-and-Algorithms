# 第八章-查找

## 查找概论

**查找表（Search Table）** ：由同一类型的数据元素（或记录）构成的集合。

**关键字（Key）** ：数据元素中某个数据项的值。

**关键码** ：标识数据记录的某个数据项（字段）。

**主关键字（Primary Key）** ：可以唯一地标识一个记录的关键字。

**次关键字（Secondary Key）** ：可以识别多个数据元素（或记录）的关键字。

关键概念示例如下图所示：

![关键概念](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/images/1-concepts.png?raw=true)

**查找（Searching）** ：就是根据给定的某个值，在查找表中确定一个其关键字等于给定值的数据元素（或记录）。

**静态查找表（Static Search Table）** ：只作查找操作的查找表。主要操作有：

1. 查询某个“特定的”数据元素是否在查找表中。
2. 检索某个“特定的”数据元素和各种属性。

**动态查找表（Dynamic Search Table）** ：在查找过程中同时插入查找表中不存在的数据元素，或者从查找表中删除已经存在的某个数据元素。主要操作有：

1. 查找时插入数据元素。
2. 查找时删除数据元素。

## 顺序表查找

**顺序查找（Sequential Search）** 又叫线性查找，是最基本的查找技术。

顺序查找的代码实现详见 [示例程序 sequential-search.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.1-sequential-search.c)。顺序查找的时间复杂度为`O(n)`。

## 有序表查找

### 二分查找

**二分查找（Binary Search）** ：前提是线性表中的记录必须是关键码有序（通常从小到大有序），线性表必须采用顺序存储。基本思想是：在有序表中，取中间记录作为比较对象，若给定值与中间记录的关键字相等，则查找成功；若给定值小于中间记录的关键字，则在中间记录的左半区继续查找；若给定值大于中间记录的关键字，则在中间记录的右半区继续查找。不断重复直至查找成功，或查找区域无记录，查找失败为止。

二分查找的代码实现详见 [示例程序 binary-search.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.2-binary-search.c)。二分查找的时间复杂度为`O(logn)`。

### 插值查找

**插值查找（Interpolation Search）** 是根据要查找的关键字key与查找表中最大最小记录的关键字比较后的查找方法，其核心就在于插值的计算公式`(key - a[low]) / (a[high] - a[low])`。

插值查找只需更改二分查找中`mid`值的计算即可，代码实现详见 [示例程序 interpolation-search.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.3-interpolation-search.c)
