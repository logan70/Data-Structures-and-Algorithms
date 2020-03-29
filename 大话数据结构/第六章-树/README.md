# 第六章-树

## 树的定义

**树（Tree）** 是`n(n >= 0)`个结点的有限集。`n = 0`时称为空树。在任意一棵非空树中：

1. 有且仅有一个特定的称为根（Root）的结点；
2. 当`n > 1`时，其余结点可分为`m(m > 0)`个互不相交的有限集`T1、T2、...、Tm`，其中每一个集合本身又是一棵树，并且成为根的子树（SubTree）。

### 结点分类

结点拥有的子树数称为结点的度（Degree）。度为0的结点称为叶结点（Leaf）或终端结点；度不为0的结点称为非终端结点或分支结点。除根结点之外，分支结点也称为内部结点。树的度是树内各结点的度的最大值。

### 结点间关系

1. 结点的子树的根称为该结点的子结点（Child）；
2. 该结点称为子结点的父结点（Parent）；
3. 拥有同一父结点的不同子结点为兄弟结点（Sibling）；
4. 结点的祖先结点是从根结点到该结点所经分支上的所有结点；
5. 以某结点为根的子树中的任一结点都称为该结点的后代。

### 树的其他相关概念

1. 结点的层次（Level）从根开始定义，根为第一层，根的子结点为第二层；
2. 树中结点的最大层次称为树的深度（Depth）或高度；
3. 如果树中结点的各子树看成从左至右有次序的，称为有序树，否则称为无序树；
4. 森林（Forest）是`m(m >= 0)`棵互不相交的树的集合。

## 树的抽象数据类型

```
ADT 树（Tree）
Data
  树是由一个根结点和若干棵子树构成。树中结点具有相同的数据类型及层次关系。
Operation
  InitTree(*T): 构造空树T。
  DestroyTree(*T): 销毁树T。
  CreateTree(*T, definition): 按definition中给出树的定义来构造树。
  ClearTree(*T): 若树T存在，则将树T清为空树。
  TreeEmpty(T): 若T为空树，返回true，否则返回false。
  TreeDepth(T): 返回T的深度。
  Root(T): 返回T的根结点。
  Value(T, cur_e): cur_e是树T中一个结点，返回此结点的值。
  Assign(T, cur_e, value): 给树T的结点cur_e赋值给value。
  Parent(T, cur_e): 若cur_e是树T的非根结点，则返回它的双亲，否则返回空。
  LeftChild(T, cur_e): 若cur_e是树T的非叶结点，则返回它的最左孩子，否则返回空。
  RightSibling(T, cur_e): 若cur_e有右兄弟，则返回它的右兄弟，否则返回空。
  InsertChild(*T, *p, i, c): 其中p指向树T的某个结点，i为所指结点p的度加上1，非空树c与T不相交，操作结果为插入c为树T中p所指结点的第i棵子树。
  DeleteChild(*T, *p, i): 其中p指向树T的某个结点，i为所指结点p的度，操作结果为删除T中p所指结点的第i棵子树。
endADT
```

## 二叉树的定义

**二叉树（Binary Tree）** 是一种“树”数据结构，树上的每个结点最多有两个孩子，分别为左孩子和右孩子。

### 特殊二叉树

- **斜树** ：所有的结点都只有左子树的二叉树叫左斜树。所有结点都只有右子树的二叉树叫右斜树。这两者统称为斜树。
  > 线性表结构可以理解为是树的一种极其特殊的表现形式。 
- **满二叉树** ：在一棵二叉树中，如果所有分支结点都存在左子树和右子树，并且所有叶子都在同一层上，这样的二叉树称为满二叉树。

![满二叉树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/1-binary-tree-1.png?raw=true)

- **完全二叉树** ：对一棵具有n个节点的二叉树按层序编号，如果编号为i(1 <= i <= n)的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同，则这棵二叉树称为完全二叉树。

![完全二叉树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/2-binary-tree-2.png?raw=true)

**完全二叉树的特点**：

1. 叶子结点只能出现在最下两层；
2. 最下层叶子一定集中在左部连续位置；
3. 倒数第二层，若有叶子结点，一定都在右部连续位置；
4. 如果结点度为1，则该节点只有左孩子；
5. 同样结点数的二叉树，完全二叉树的深度最小。

## 二叉树的性质

1. 在二叉树的第i层上至多有`2^(i - 1)`个结点（i >= 1）；
2. 深度为k的二叉树至多有`2^k - 1`个结点（k >= 1）；
3. 对任何一棵二叉树T，如果其终端节点数为n0，度为2的结点数为n2，则`n0 = n2 + 1`；
4. 具有n个结点的完全二叉树的深度为`floor(log2n) + 1`；
5. 如果对一棵有n个结点的完全二叉树（其深度为`floor(log2n) + 1`）的结点按层序编号，对任一结点i`(1 <= i <= n)`有：
   1. 如果i = 1， 则结点i是二叉树的根，无父节点，如果`i > 1`，则其父节点是结点`floor(i / 2)`；
   2. 如果`2i > n`，则结点i无左孩子（结点i为叶子结点）；否则其左孩子是结点`2i`；
   3. 如果`2i + 1 > n`，则结点i无右孩子；否则其右孩子是结点`2i + 1`。

## 二叉树的存储结构

### 顺序存储结构

顺序存储结构通过分配`2^k - 1`个存储单元来存储深度为k的二叉树，但是可能会造成存储空间浪费，例如下图中的右斜树(`^`表示结点不存在)：

![二叉树的顺序存储](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/3-binary-tree-3.png?raw=true)

顺序存储结构一般只用于完全二叉树，这样造成的存储空间的浪费比较少。

### 二叉链表

二叉链表结点定义代码如下：

```c
typedef struct BiTNode
{
  ElementType data; // 结点数据
  struct BiTNode * lchild, * rchild; // 左右孩子指针
} BiTNode, *BiTree;
```

## 遍历二叉树

**二叉树的遍历（traversing binary tree）** 是指从根结点出发，按照某种次序依次访问二叉树中所有结点，使得每个结点被访问一次且仅被访问一次。

一般来讲我们有两种遍历方式：**深度优先遍历(DFS)** 和 **广度优先遍历(BFS)**。

深度优先遍历(DFS)可分为 **前序遍历**、**中序遍历**、**后序遍历** 三种。

### 前序遍历

规则：二叉树为空，则空操作返回，否则先访问根结点，然后前序遍历左子树，再前序遍历右子树，如下图所示，遍历顺序为 `ABDGHCEIF`：

![前序遍历](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/4-pre-order.png?raw=true)

前序遍历算法的代码实现详见 [示例程序bitree.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.2-bitree.c) 中的`PreOrderTraverse()`函数。

### 中序遍历

规则：二叉树为空，则空操作返回，否则从根结点开始（不是先访问根结点），中序遍历左子树，访问根结点，再中序遍历右子树。如下图所示，遍历顺序为 `GDHBAEICF`：

![中序遍历](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/5-in-order.png?raw=true)

中序遍历算法的代码实现详见 [示例程序bitree.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.2-bitree.c) 中的`InOrderTraverse()`函数。

### 后序遍历

规则：二叉树为空，则空操作返回，先后续遍历左子树，再后续遍历右子树，最后访问根结点。如下图所示，遍历顺序为 `GHDBIEFCA`：

![后遍历](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/6-post-order.png?raw=true)

后遍历算法的代码实现详见 [示例程序bitree.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.2-bitree.c) 中的`PostOrderTraverse()`函数。

### 层序遍历

规则：若树为空，则空操作返回，否则从树的第一层开始访问，从上而下逐层遍历，在同一层中，按从左到右的顺序对结点逐个访问，如下图所示，遍历顺序为 `ABCDEFGHI`：

![层序遍历](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/7-bfs.png?raw=true)

层序遍历要借助先进先出(FIFO)的队列(queue)结构完成操作。

层序遍历算法的代码实现详见 [示例程序bitree.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.2-bitree.c) 中的`BFSTraverse()`函数。

## 二叉树的建立

其实建立二叉树，也是利用了递归的原理。只是在原来访问处理数据的地方改成了生成结点、给结点赋值的操作。

例如 [示例程序bitree.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.2-bitree.c) 中的`CreateBiTree()`函数就是用前序遍历的方式实现了二叉树的建立。当然，也可以使用中序遍历或后序遍历的方式实现。

[示例程序bitree.test.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.3-bitree.test.c) 演示了如何建立二叉树并遍历二叉树。

例如，可以输入`"ABDH#K###E##CFI###G#J##"`，构建下图所示二叉树：

![建立二叉树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/8-create-binary-tree.png?raw=true)

程序输出如下：

```
Please enter chars as tree node(pre-order, # represent empty): ABDH#K###E##CFI###G#J##

Pre-Order traversing: 
ABDHKECFIGJ

In-Order traversing: 
HKDBEAIFCGJ

Post-Order traversing: 
KHDEBIFJGCA

BFS-Order traversing: 
ABCDEFGHIJK
```

## 线索二叉树

将二叉树中原本为空的**左孩子指针**改为指向该结点在中序序列中的前驱，原本为空的**右孩子指针**改为指向该节点在中序序列中的后继。这种指向前驱和后继的指针称为线索，加上线索的二叉链表称为线索链表，相应的二叉树称为**线索二叉树（Threaded Binary Tree）** ，如下图所示。

![线索二叉树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/9-threaded-binary-tree.png?raw=true)

线索二叉树结构定义及操作函数原型详见[示例程序threaded-bitree.h](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.4-threaded-bitree.h)。

线索二叉树操作函数实现代码详见[示例程序threaded-bitree.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.5-threaded-bitree.c)。

[示例程序threaded-bitree.test.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/example/6.6-threaded-bitree.test.c) 演示了如何建立线索二叉树并遍历。

> 需要注意的是，如果二叉树线索化，则不能使用普通的遍历方法进行遍历，因为原本为空的孩子指针被赋值，会导致递归出口条件不满足，造成死循环

## 树、森林与二叉树的转换

### 树转换为二叉树

数转换为二叉树的步骤如下：

1. 加线。在所有兄弟结点之间加一条连线。
2. 去线。对树中每个节点，只保留它与第一个孩子结点的连线，删除它与其他孩子结点之间的连线。
3. 层次调整。以树的根结点为轴心，将整棵树顺时针旋转一定角度，使之结构层次分明，如下图所示。

![树转换为二叉树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/10-tree-to-binary-tree.png?raw=true)

### 森林转换为二叉树

1. 把每个树转换为二叉树。
2. 第一棵二叉树不动，从第二棵开始，依次把后一棵二叉树的根结点作为前一棵二叉树的根结点的右孩子，用线连接起来，如下图所示：

![森林转换为二叉树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/11-forest-to-binary-tree.png?raw=true)

### 二叉树转换为树

1. 加线，若结点的左孩子存在，则将结点与左孩子的右孩子，左孩子的右孩子的右孩子。。。用线连接起来。
2. 去线，将结点与右孩子，右孩子的右孩子。。。之间连线去除。
3. 层次调整，如下图所示：

![二叉树转换为树](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/12-binary-tree-to-tree.png?raw=true)

### 二叉树转换为森林

1. 从根结点开始，若右孩子存在，则把与右孩子结点的连线删除，再看分离后的二叉树，一直分离到所有右孩子连线都删除。
2. 将每棵分离后的二叉树转换为树即可，如下图所示：

![二叉树转换为森林](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/13-binary-tree-to-forest.png?raw=true)

### 树与森林的遍历

树的遍历分为两种方式：

1. 先根遍历：先访问根结点，然后依次先根遍历每棵子树；
2. 后根遍历：依次后根遍历每棵子树，然后再访问根结点。

森林遍历分为两种方式：

1. 前序遍历：依次先根遍历森林中的每棵树；
2. 后序遍历：依次后根遍历森林中的每棵树。

## 赫夫曼树

从树中一个结点到另一个节点之间的分支构成两个节点之间的路径，路径上的分支数目称作路径长度。

树的路径长度就是从树根到每一节点的路径长度之和。

![赫夫曼树1](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E5%85%AD%E7%AB%A0-%E6%A0%91/images/14-huffman-1.png?raw=true)

上图中二叉树a的树路径长度就为`1+1+2+2+3+3+4+4=20`，二叉树b的路径长度为`1+2+3+3+2+1+2+2=16`。

节点的带权路径长度为从该节点到树根之间的路径长度与节点上权的乘积。树的带权路径长度为树中所有叶子结点的带权路径长度之和。假设有n个权值`{w1,w2,...,wn}`，构造一棵有n个叶子结点的二叉树，每个叶子结点带权wk，每个叶子的路径长度为lk，则其中**带权路径长度WPL最小的二叉树称作赫夫曼树** 。

之前图中二叉树a的`WPL = 5x1 + 15x2 + 40x3 + 30x4 + 10x4 = 315`。

二叉树b的`WPL = 5x3 + 15x3 + 40x2 + 30x2 + 10x2 = 220`。

构造赫夫曼树的赫夫曼算法描述：

1. 对给定的n个权值{W1,W2,W3,...,Wi,...,Wn}构成n棵二叉树的初始集合F= {T1,T2,T3,...,Ti,...,Tn}，其中每棵二叉树Ti中只有一个权值为Wi的根结点，它的左右子树均为空。
2. 在F中选取两棵根结点权值最小的树作为新构造的二叉树的左右子树，新二叉树的根结点的权值为其左右子树的根结点的权值之和。
3. 从F中删除这两棵树，并把这棵新的二叉树同样以升序排列加入到集合F中。
4. 重复二和三两步，直到集合F中只有一棵二叉树为止。

### 赫夫曼编码

一般地，设需要编码的字符集为`{d1,d2,..,dn}`，各个字符在电文中出现的次数或频率集合为`{w1,w2,...,wn}`，以`d1,d2,...,dn`作为叶子结点，以`w1,w2,...,wn` 作为相应叶子结点的权值来构造一棵赫夫曼树。规定赫夫曼树的左分支为0，右分支代表1，则从根结点到叶子结点所经过的路径分支组成的0和1的序列便为该结点对应字符的编码，这就为赫夫曼编码。
