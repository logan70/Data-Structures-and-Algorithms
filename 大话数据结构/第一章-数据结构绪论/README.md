# 第一章-数据结构绪论

## 基本概念和术语

**数据结构** ：是一门研究非数值计算的程序设计问题中的操作对象，以及她们之间的关系和操作等相关问题的学科。

**数据** ：是描述客观事物的符号，是计算机中可以操作的对象，是能被计算机识别，并输入给计算机处理的符号集合。

**数据元素** ：是组成数据的，有一定意义的基本单位，在计算机中通常作为整体处理。也被称为记录。

**数据项** ：一个数据元素可以由若干个数据项组成，数据项是数据不可分割的最小单位。

**数据对象** ：是性质相同的数据元素的集合，是数据的子集。

**数据结构** ：是相互之间存在一种或多种特定关系的数据元素的集合。

## 逻辑结构与物理结构

### 逻辑结构

**逻辑结构** ：是指数据对象中数据元素之间的相互关系。

> 逻辑结构是针对具体问题的，是为了解决某个问题，在对问题理解的基础上，选择一个合适的数据结构表示数据元素之间的逻辑关系。

逻辑结构分为以下四种：

1. 集合结构：集合结构中的数据元素除了同属于一个集合外，他们之间没有其他关系，如下图所示。

![集合结构](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%80%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%BB%AA%E8%AE%BA/images/1-collection.png?raw=true)

2. 线性结构：线性结构中的数据元素之间是一对一的关系，如下图所示。

![线性结构](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%80%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%BB%AA%E8%AE%BA/images/2-linear.png?raw=true)

3. 树形结构：树形结构中的数据元素之间存在一种一对多的层次关系，如下图所示。

![树形结构](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%80%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%BB%AA%E8%AE%BA/images/3-tree.png?raw=true)

4. 图形结构：图形结构的数据元素是多对多的关系，如下图所示。

![图形结构](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%80%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%BB%AA%E8%AE%BA/images/4-graph.png?raw=true)

### 物理结构

**物理结构** ：是指数据的逻辑结构在计算机中的存储形式。

数据元素的存储结构形式有两种：

1. 顺序存储结构：是把数据元素存放在地址连续的存储单元里，其数据间的逻辑关系和物理关系是一致的，如下图所示。

![顺序存储结构](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%80%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%BB%AA%E8%AE%BA/images/5-sequent.png?raw=true)

2. 链式存储结构：是把数据元素存放在任意的存储单元里，这组存储单元可以是连续的，也可以是不连续的，如下图所示。

![链式存储结构](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%B8%80%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%BB%AA%E8%AE%BA/images/6-chain.png?raw=true)

## 抽象数据类型

### 数据类型

**数据类型** ：是指一组性质相同的值的集合及定义在此集合上的一些操作的总称。

### 抽象数据类型

**抽象数据类型（Abstract Data Type, ADT）** ：是指一个数学模型及定义在该模型上的一组操作。

> 抽象数据类型体现了程序设计中问题分解、抽象和信息隐藏的特性。

描述抽象数据类型的标准格式如下：

```
ADT 抽象数据类型名
Data
  数据元素之间逻辑关系的定义
Operation
  操作1
    初始条件
    操作结果描述
  操作2
    ...
  操作n
    ...
endADT
```

