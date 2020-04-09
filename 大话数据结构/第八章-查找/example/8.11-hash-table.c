#include <stdbool.h>
#define HASHSIZE 12 // 定义散列表长
#define NULLKEY -32768

typedef struct
{
  int * elem; // 数据元素存储基址，动态分配数组
  int count; // 当前数据元素个数
} HashTable;

int m = 0; // 散列表表长，全局变量

// 初始化散列表
bool InitHashTable(HashTable * H)
{
  int i;
  m = HASHSIZE;
  H->count = n;
  H->elem = (int *)malloc(m * sizeof(int));
  for (i = 0; i < m; i++)
    H->elem[i] = NULLKEY;
  return true;
}

// 散列函数
int Hash(int key)
{
  return key % m; // 除留余数法
}

// 插入关键字进散列表
void InsertHash(HashTable * H, int key)
{
  int addr = Hash(key); // 求散列地址
  while (H->elem[addr] != NULLKEY)
    addr = (addr + 1) % m; // 开放定址法的线性探测解决冲突
  H->elem[addr] = key;
}

// 散列表查找关键字
bool SearchHash(HashTable H, int key, int * addr)
{
  *addr = Hash(key); // 求散列地址
  while (H.elem[*addr] != key)
  {
    *addr = (*addr + 1) % m;
    if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
    { // 如果循环回到原点
      return false;
    }
  }
  return true;
}
