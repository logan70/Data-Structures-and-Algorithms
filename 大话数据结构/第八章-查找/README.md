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

### 斐波那契查找

裴波那契数列是一串按照F(0)=1，F(1)=1, F(n)=F(n-1)+F(n-2)（n>=2，n∈N*）这一条件递增的一串数字：`1、1、2、3、5、8、13、21 ... ...`，两个相邻项的比值会逐渐逼近0.618 —— 黄金分割比值。

斐波那契查找就是一个长度为f(n)的数组，它能被分成f(n-1)和f(n-2)这两半，递归查找。

二分查找， 插值查找和裴波那契查找的基础其实都是：对数组进行分割， 只是各自的标准不同： 二分是从数组的一半分， 插值是按预测的位置分， 而裴波那契是按它数列的数值分。

算法思想如下：

1. 创建裴波那契数组
2. 以1中的裴波那契数组的大于待查找数组的最小值为长度创建填充数组，将原待排序数组元素拷贝到填充数组中来， 如果有剩余的未赋值元素， 用原待查找数组的最后一个元素值填充
3. 针对填充数组进行关键字查找， 查找成功后记得判断该元素是否来源于后来填充的那部分元素，若为填充的元素，则返回最后一个元素下标即可

斐波那契数组、待查找数组、填充数组三者的关系如下图所示：

![斐波那契查找](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/images/2-fibonacci-search.jpg?raw=true)

斐波那契查找代码实现详见 [示例程序 fibonacci-search.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.4-fibonacci-search.c)


## 二叉排序树

**二叉排序树（Binary Sort Tree）** ：又称为二叉查找树。它或是一棵空树，或者是具有下列性质的树：

- 若它的左子树不空，则左子树上所有结点的值均小于它的根结构的值；
- 若它的右子树不空，则右子树上所有结点的值均大于它的根结构的值；
- 它的左、右子树也分别为二叉排序树。

### 二叉排序树查找操作

二叉排序树的查找操作代码实现详见 [示例程序 search-bst.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.6-search-bst.c)

### 二叉排序树插入操作

二叉排序树的插入操作代码实现详见 [示例程序 insert-bst.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.7-insert-bst.c)

### 二叉排序树删除操作

删除操作比较复杂，有以下几种情况：

1. 待删除结点为叶子结点，直接删除即可；
2. 待删除结点仅有左子树，则删除后重接左子树；
3. 待删除结点仅有右子树，则删除后重接右子树；
4. 待删除结点左右子树都有，则寻找其直接前驱节点，数据拷贝至待删除结点，然后删除其前驱节点，这里还分两种情况（前提：前驱结点无右子树）：
   1. 前驱节点即为待删除结点左子节点，重接其左子树至待删除结点即可；
   2. 前驱结点非待删除结点左子节点，重接其左子树至其父节点的右子树即可。

二叉排序树的删除操作代码实现详见 [示例程序 delete-bst.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AB%E7%AB%A0-%E6%9F%A5%E6%89%BE/example/8.8-delete-bst.c)

