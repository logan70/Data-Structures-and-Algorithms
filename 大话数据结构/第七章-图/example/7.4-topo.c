#include <stdio.h>
#include <stdbool.h>
#include "7.3-topo.h"
// 拓扑排序，若GL无回路，则输出拓扑排序序列并返回true，若有回路则返回false
bool TopologicalSort(GraphAdjList GL);

bool TopologicalSort(GraphAdjList GL)
{
  EdgeNode * e;
  int i, k, gettop;
  int top = 0; // 用于栈指针下标
  int count = 0; // 用于统计输出顶点个数
  int * stack; // 建栈存储入度为0的顶点
  stack = (int *)malloc(GL->numVertexes * sizeof(int));
  for (i = 0; i < GL->numVertexes; i++)
    if (GL->adjList[i].in == 0)
      stack[++top] = i; // 将入度为0的顶点入栈
  while (top != 0)
  {
    gettop = stack[top--]; // 出栈
    printf("%d -> ", GL->adjList[gettop].data); // 打印此顶点
    count++;
    for (e = GL->adjList[gettop].firstedge; e; e = e->next)
    {
      // 对此顶点弧表遍历
      k = e->adjvex;
      if (!(--GL->adjList[k].in)) // 将k号顶点邻接点的入度减1
        stack[++top] = k; // 若为0则入栈，以便于下次循环输出
    }
  }
  // count小于顶点数，说明存在环
  return count < GL->numVertexes ? false : true;
}
