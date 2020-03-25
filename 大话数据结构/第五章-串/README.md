# 第五章-串

## 串的定义

**串（string）** 是由零个或多个字符组成的有限序列，又叫**字符串**。串中的字符数目n称为串的长度。零个字符的串称为空串（null string），长度为零，可以直接用双引号`""`表示。

## 串的比较

串的比较是通过比较组成串的字符之间的编码来进行的，例如常用英文字符使用的是标准的ASCII编码，例如：

- "hap" < "happy"
- "happen" < "happy"

## 串的抽象数据类型

```
ADT 串（string）
Data
  串中元素仅由一个字符组成，相邻元素具有前驱和后继关系。
Operation
  StrAssign(T, *chars): 生成一个其值等于字符串常量chars的串T。
  StrCopy(T, S): 串S存在，由串S复制得串T。
  ClearString(S): 串S存在，将串清空。
  StringEmpty(S): 若串S为空，返回true，否则返回false。
  StrLength(S): 返回串S的元素个数，即串的长度。
  StrCompare(S, T): 若S>T，返回值>0，若S=T，返回0，若S<T，返回值0.
  Concat(T, S1, S2): 用T返回由S1和S2连接而成的新串
  SubString(Sub, S, pos, len): 串S存在，0<=pos<=StrLength(S)-1，且
                              0<=len<=StrLength(S) - pos，
                              用Sub返回串S的第pos个字符起长度为len的子串。
  Index(S, T, pos): 串S、T存在，T是非空串，0<=pos<=StrLength(S)-1。
                    若主串S中存在和串T值相同的子串，则返回它在主串S中第
                    pos个字符之后第一次出现的位置，否则返回0.
  Replace(S, T, V): 串S、T、V存在，T是非空串，用V替换主串S中出现的所有
                    与T相等的不重叠的子串。
  StrInsert(S, pos, T): 串S和T存在，0<=pos<=Strlength(S)。
                        在串S的第pos个字符之前插入串T。
  StrDelete(S, pos, len): 串S存在， 0<=pos<=Strlength(S)-len。
                          从串S中删除第pos个字符起长度为len的子串。
endADT
```

## 串的存储结构

### 串的顺序存储结构

串的顺序存储结构是用一组地址连续的存储单元来存储串中的字符序列的。一般使用定长数组来定义。

### 串的链式存储结构

串的链式存储结构，如果每个结点的数据域是一个字符，会存在很大的空间浪费。因此可以考虑一个结点存放多个字符，未被占的位置可以用#或其他非串值字符补全。

串的链式存储结构在连接串与串操作时有一定方便，总的来说不如顺序存储灵活，性能也不如顺序存储结构好。

## BF算法（朴素的模式匹配算法）

暴风(Brute Force)算法是普通的模式匹配算法，BF算法的思想就是将目标串S的第一个字符与模式串T的第一个字符进行匹配，若相等，则继续比较S的第二个字符和T的第二个字符；若不相等，则比较S的第二个字符和T的第一个字符，依次比较下去，直到得出最后的匹配结果。BF算法是一种蛮力算法。

BF算法的代码实现参考[示例程序bf.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/example/5.1-bf.c)

## KMP模式匹配算法

字符串的**前缀** ：`"Harry`"的前缀集合为 `{"H", "Ha", "Har", "Harr"}`。

字符串的**后缀** ：`"Potter"`的后缀集合为 `{"otter", "tter", "ter", "er", "r"}`。

KMP算法的核心，是一个被称为部分匹配表(Partial Match Table)的数组。

PMT中的值是字符串的前缀集合与后缀集合的交集中最长元素的长度。

![PMT](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/2-pmt1.jpg?raw=true)

- 在主字符串`"ababababca"`中查找模式字符串`"abababca"`，如果在`j`处字符不匹配，则前`j`位都是相同的，也就是`"ababab"`；
- 要跳过BF算法中绝不可能的情况，其实就是寻找到`"ababab"`的前缀集合与后缀集合的交集中最长元素的过程；
- 具体的做法是，保持`i`指针不动，然后将j指针指向模式字符串的`PMT[j −1]`位即可，如下图所示：

![KMP模式匹配算法](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/1-kmp1.jpg?raw=true)

如果是在 `j` 位 失配，那么影响 `j` 指针回溯的位置的其实是第 `j − 1` 位的 PMT 值，所以为了编程的方便， 我们不直接使用PMT数组，而是将PMT数组向后偏移一位。我们把新得到的这个数组称为next数组。

> 第0位的值设为-1，这只是为了编程的方便，并没有其它的意义。

![PMT](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/3-pmt2.jpg?raw=true)

KMP的主体算法代码实现详见 [示例程序kmp.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/example/5.2-kmp.c) 中的`KMP`函数。

接着来说`next`数组的获取，求`next`数组的过程完全可以看成字符串匹配的过程，即以模式字符串为主字符串，以模式字符串的前缀为目标字符串，一旦字符串匹配成功，那么当前的`next`值就是匹配成功的字符串的长度，如下图所示：

![next获取a](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/4-kmp-next-a.jpg?raw=true)
![next获取b](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/5-kmp-next-b.jpg?raw=true)
![next获取c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/6-kmp-next-c.jpg?raw=true)
![next获取d](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/7-kmp-next-d.jpg?raw=true)
![next获取e](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/8-kmp-next-e.jpg?raw=true)

如果匹配失败则回退到次大匹配继续匹配（细品）。

next获取的代码实现详见 [示例程序kmp.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/example/5.2-kmp.c) 中的`getnext()`函数。

## KMP模式匹配算法改进

运用KMP算法时，如果模式字符串中有多个与首位字符相等的字符，会出现多余的判断，如下图中2、3、4、5步骤是多余的。

![KMP改进](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/images/8-kmp-optm.png?raw=true)

我们可以用首位next[1]的值去取代与它相等的字符后续next[j]的值，代码实现详见 [示例程序kmp-optm.c](https://github.com/logan70/Data-Structures-and-Algorithms/blob/master/%E5%A4%A7%E8%AF%9D%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%AC%AC%E4%BA%94%E7%AB%A0-%E4%B8%B2/example/5.3-kmp-optm.c)
