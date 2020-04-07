// 拓扑排序算法中涉及的结构定义
#define MAXVEX 100
typedef struct EdgeNode // 边表结点
{
  int adjvex; // 邻接点域，存储该顶点对应的下标
  int weight; // 用于存储权值，非网图不需要
  struct EdgeNode * next; // 链域，指向下一个邻接点
} EdgeNode;
typedef struct VertexNode // 顶点表结点
{
  int in; // 顶点入度
  int data; // 顶点域，存储顶点信息
  EdgeNode * firstedge; // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
  AdjList adjList;
  int numVertexes, numEdges; // 图中当前顶点数和边数
} graphAdjList, * GraphAdjList;
