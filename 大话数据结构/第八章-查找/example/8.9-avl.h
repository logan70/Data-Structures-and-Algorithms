#define LH +1 // 左高
#define EH 0 // 等高
#define RH -1 // 右高

// 二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
  int data;
  int bf; // 结点的平衡因子
  struct BiTNode * lchild, * rchild; // 左右孩子指针
} BiTNode, * BiTree;

// 对以p为根的二叉排序树作右旋处理
// 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点
void R_Rotate(BiTree * P);

// 对以p为根的二叉排序树作左旋处理
// 处理之后p指向新的树根结点，即旋转处理之前的右子树的根结点
void L_Rotate(BiTree * P);

// 对以指针T所指结点为根的二叉树作左平衡旋转处理
// 本算法结束时，指针T指向新的根结点
void LeftBalance(BiTree * T);

// 对以指针T所指结点为根的二叉树作右平衡旋转处理
// 本算法结束时，指针T指向新的根结点
void RightBalance(BiTree * T);

/**
 * AVL树主函数
 * 若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个
 * 数据元素为e的新结点并返回true，否则返回false
 * 若因插入而使二叉排序树失去平衡，则作平衡旋转处理，布尔变量taller反应T长高与否
 */
bool InsertAVL(BiTree * T, int e, bool * taller);