#define MAXSIZE 10 // 要排序的数组元素个数
typedef struct
{
  int r[MAXSIZE + 1]; // 用于存储要排序数组，r[0]用作哨兵或临时变量
  int length; // 用于记录顺序表的长度
  int length;
} SqList;

// 交换L中数组r的下标为i和j的数
void swap(SqList * L, int i, int j)
{
  int temp = L->r[i];
  L->r[i] = L->r[j];
  L->r[j] = temp;
}
