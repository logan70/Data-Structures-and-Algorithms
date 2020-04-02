// 网图邻接表存储
#include <stdio.h>
#include <stdbool.h>
#define MAXVEX 100
typedef char VertexType; // 顶点类型可自定义
typedef int EdgeType; // 边的权值类型可自定义
typedef struct EdgeNode // 边表结点
{
  int adjvex; // 邻接点域，存储该顶点对应的下标
  EdgeType weight; // 权值，非网图可以不要
  struct EdgeNode * next; // 链域，指向下一个邻接点
} EdgeNode;

typedef struct VertexNode // 顶点表结点
{
  VertexType data; // 顶点域，存储顶点信息
  EdgeNode * firstedge; // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
  AdjList adjList;
  int numVertexes, numEdges; // 图中当前顶点数和边数
} GraphAdjList;
bool visited[MAXVEX]; // 访问标志数组

// 建立图的邻接表结构
void CreateALGraph(GraphAdjList * G)
{
  int i, j, k;
  EdgeNode * e;
  printf("输入顶点数和边数：\n");
  scanf("%d %d", &G->numVertexes, &G->numEdges);
  for (i = 0; i < G->numVertexes; i++)
  {
    scanf(&G->adjList[i].data);
    G->adjList[i].firstedge = NULL;
  }
  for (k = 0; k < G->numEdges; k++)
  {
    printf("输入边(vi, vj)上的顶点序号：\n");
    scanf("%d %d", &i, &j);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = G->adjList[i].firstedge;
    G->adjList[i].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next = G->adjList[j].firstedge;
    G->adjList[j].firstedge = e;
  }
}

// 邻接表的深度优先递归算法
void DFS(GraphAdjList GL, int i, void(*pfun)(VertexType item))
{
  EdgeNode * p;
  visited[i] = true;
  (*pfun)(GL.adjList[i].data);
  p = GL.adjList[i].firstedge;
  while (p)
  {
    if (!visited[p->adjvex])
      DFS(GL, p->adjvex, pfun); // 对未访问的邻接顶点递归调用
    p = p->next;
  }
}

// 邻接表的深度遍历操作
void DFSTraverse(GraphAdjList GL, void(*pfun)(VertexType item))
{
  int i;
  for (i = 0; i < GL.numVertexes; i++)
    visited[i] = false; // 初始所有顶点状态都是未访问状态
  for (i = 0; i < GL.numVertexes; i++)
    if (!visited[i]) // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
      DFS(GL, i, pfun);
}

void BFSTraverse(GraphAdjList GL, void(*pfun)(VertexType item))
{
  int i;
  EdgeNode * p;
  Queue Q;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = false;
  InitQueue(&Q); // 初始化辅助用的队列
  for (i = 0; i < GL.numVertexes; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      (*pfun)(GL.adjList[i].data);
      EnQueue(&Q, i);
      // 若队列非空，则将队首元素出列，并将其邻接点入列
      while (!QueueEmpty(Q))
      {
        DeQueue(&Q, &i);
        p = GL.adjList[i].firstedge;
        while (p)
        {
          if (!visited[p->adjvex])
          {
            visited[p->adjvex] = true;
            (*pfun)(GL.adjList[p->adjvex].data);
            EnQueue(&Q, p->adjvex);
          }
          p = p->next;
        }
      }
    }
  }
}