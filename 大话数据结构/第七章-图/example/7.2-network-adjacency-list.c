// 网图邻接表存储
#include <stdio.h>
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