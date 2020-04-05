#include <stdbool.h>
// 图的邻接矩阵存储方式
typedef char VertexType; // 顶点类型可自定义
typedef int EdgeType; // 边的权值类型可自定义
#define MAXVEX 100 // 最大定点数，自定义
#define INFINITY 65535 // 用65535代表∞

typedef struct
{
  VertexType vexs[MAXVEX]; // 顶点表
  EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵，可看作边表
  int numVertexes, numEdges; // 图中当前的顶点数和边数
} MGraph;

// 边集数组Edge结构的定义
typedef struct
{
  int begin;
  int end;
  int weight;
} Edge;

bool visited[MAXVEX]; // 访问标志数组


// 建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph * G);
// 邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i, void (*pfun)(VertexType item));
// 邻接矩阵的深度优先遍历操作
void DFSTraverse(MGraph G, void (*pfun)(VertexType item));
// 邻接矩阵的广度优先遍历操作
void BFSTraverse(MGraph G, void(*pfun)(VertexType item));
// Prim算法生成最小生成树
void MiniSpanTree_Prim(MGraph G);
// 查找连线顶点的尾部下标
int Find(int * parent, int f);
// Kruskal算法生成最小生成树
void MiniSpanTree_Kruskal(MGraph G);

void printfChar(VertexType item);

int main(void)
{
  MGraph * graph = (MGraph *)malloc(sizeof(MGraph));
  CreateMGraph(graph);
  DFSTraverse(*graph, printfChar);
}


// 建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph * G)
{
  int i, j, k, w;
  printf("输入顶点数和边数");
  scanf("%d %d", &G->numVertexes, &G->numEdges);
  for (i = 0; i < G->numVertexes; i++) // 读入顶点信息，建立顶点表
    scanf(&G->vexs[i]);
  for (i = 0; i < G->numVertexes; i++)
    for (j = 0; j < G->numVertexes; j++)
      G->arc[i][j] = INFINITY; // 邻接矩阵初始化
  for (k = 0; k < G->numEdges; k++) // 读入numEdges条边，建立邻接矩阵
  {
    printf("输入边(vi, vj)上的下标i，下标j和权w：\n");
    scanf("%d %d %d", &i, &j, &w);
    G->arc[i][j] = w;
    G->arc[j][i] = G->arc[i][j]; // 无向图矩阵对称
  }
}

// 邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i, void (*pfun)(VertexType item))
{
  int j;
  visited[i] = true;
  (*pfun)(G.vexs[i]);
  for (j = 0; j < G.numVertexes; j++)
    if (G.arc[i][j] == 1 && !visited[j])
      DFS(G, j, pfun); // 对未访问的邻接顶点递归调用
}

// 邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G, void (*pfun)(VertexType item))
{
  int i;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = false; // 初始所有顶点状态都是未访问的状态
  for (i = 0; i < G.numVertexes; i++)
    if (!visited[i]) // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
      DFS(G, i, pfun);
}

void printfChar(VertexType item)
{
  printf("%c ", item);
}

void BFSTraverse(MGraph G, void(*pfun)(VertexType item))
{
  int i, j;
  Queue Q;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = false;
  InitQueue(&Q); // 初始化辅助用的队列
  for (i = 0; i < G.numVertexes; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      (*pfun)(G.vexs[i]);
      EnQueue(&Q, i);
      // 若队列非空，则将队首元素出列，并将其邻接点入列
      while (!QueueEmpty(Q))
      {
        DeQueue(&Q, &i);
        for (j = 0; j < G.numVertexes; j++)
        {
          if (G.arc[i][j] == 1 && !visited[j])
          {
            visited[j] = true;
            (*pfun)(G.vexs[j]);
            EnQueue(&Q, j);
          }
        }
      }
    }
  }
}

void MiniSpanTree_Prim(MGraph G)
{
  int min, i, j, k;
  int adjvex[MAXVEX]; // 保存相关顶点下标
  int lowcost[MAXVEX]; // 保存相关顶点间边的权值，为0代表对应下表的顶点已加入生成树
  lowcost[0] = 0; // 将起始顶点加入生成树
  adjvex[0] = 0; // 起始顶点无相关顶点，下标设为0
  for (i = 1; i < G.numVertexes; i++)
  {
    lowcost[i] = G.arc[0][i]; // 将v0顶点与之有边的权值存入数组
    adjvex[i] = 0; // 初始化都为v0的下标
  }
  // n个顶点，最小生成树有n-1条边，循环n-1次即可完成
  for (i = 1; i < G.numVertexes; i++)
  {
    min = INFINITY; // 初始化最小权值为∞
    j = 1; k = 0;
    // 与生成树内点连接的边中寻找权重最小的边
    while (j < G.numVertexes)
    {
      // lowcost[j] != 0确保排除已在生成树内的点
      if (lowcost[j] != 0 && lowcost[j] < min)
      {
        min = lowcost[j];
        k = j;
      }
      j++;
    }
    printf("v%d点加入生成树，其邻接顶点为v%d，两顶点边权值为%d\n",
    k, adjvex[k], min);
    lowcost[k] = 0; // 标记vk顶点已加入生成树
    // 更新与生成树内点连接的边的最小权值信息
    for (j = 1; j < G.numVertexes; j++)
    {
      if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
      {
        lowcost[j] = G.arc[k][j];
        adjvex[j] = k;
      }
    }
  }
}

void MiniSpanTree_Kruskal(MGraph G)
{
  int i, n, m;
  Edge edges[MAXVEX]; // 边集数组
  int parent[MAXVEX]; // 用来判断边与边是否形成环路
  // 此处省略邻接矩阵转换为边集数组，并按权值从大到小排序的代码
  for (i = 0; i < G.numVertexes; i++)
    parent[i] = 0;
  for (i = 0; i < G.numVertexes; i++)
  {
    n = Find(parent, edges[i].begin);
    m = Find(parent, edges[i].end);
    if (n != m) // n与m不相等，则此边没有与现有生成树形成环路
    {
      // 将此边的结尾顶点放入下标为起点的parent中，表示此顶点已经在生成树集合中
      parent[n] = m;
      printf("边(%d, %d)加入最小生成树，该边权值为%d\n",
      edges[i].begin, edges[i].end, edges[i].weight);
    }
  }
}

int Find(int * parent, int f)
{
  while (parent[f] > 0)
    f = parent[f];
  return f;
}