#include <stdbool.h>
#include "7.1-adjacency-matrix.h"

bool visited[MAXVEX]; // 访问标志数组
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

// 领节矩阵的深度遍历操作
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

int main(void)
{
  MGraph * graph = (MGraph *)malloc(sizeof(MGraph));
  CreateMGraph(graph);
  DFSTraverse(*graph, printfChar);
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