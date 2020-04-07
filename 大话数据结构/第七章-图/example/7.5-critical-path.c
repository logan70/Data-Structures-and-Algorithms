#include <stdio.h>
#include <stdbool.h>
#include "7.3-topo.h"

int * etv, * ltv; // 事件最早发生时间和最迟发生时间数组
int * stack2; // 用于存储拓扑序列的栈
int top2; // 用于stack2的指针

// 拓扑排序，用于关键路径计算
bool TopologicalSort(GraphAdjList GL);
// 求关键路径，GL为有向网，输出GL的各项关键活动
void CriticalPath(GraphAdjList GL);

bool TopologicalSort(GraphAdjList GL)
{
  EdgeNode * e;
  int i, k, gettop;
  int top = 0; // 用于栈指针下标
  int count = 0; // 用于统计输出顶点个数
  int * stack;
  stack = (int *)malloc(GL->numVertexes * sizeof(int));
  for (i = 0; i < GL->numVertexes; i ++)
    if (0 == GL->adjList[i].in)
      stack[++top] = i;
  top2 = 0; // 【初始化stack2的指针为0】
  etv = (int *)malloc(GL->numVertexes * sizeof(int)); // 【事件最早发生时间】
  for (i = 0; i < GL->numVertexes; i++)
    etv[i] = 0; // 【初始化为0】
  stack2 = (int *)malloc(GL->numVertexes * sizeof(int)); // 【初始化】
  while (top != 0)
  {
    gettop = stack[top--];
    count++;
    stack2[++top2] = gettop; // 【将弹出的顶点序号压入拓扑序列的栈】
    for (e = GL->adjList[gettop].firstedge; e; e = e->next)
    {
      k = e->adjvex;
      if(!(--GL->adjList[k].in))
        stack[++top] = k;
      // 【从源点开始向汇点顺推，求得各顶点事件最早发生时间】
      // 【最早发生时间应取直接连接该事件的各个活动完成时间的最大值】
      if ((etv[gettop] + e->weight) > etv[k])
        etv[k] = etv[gettop] + e->weight;
    }
  }
  return count < GL->numVertexes ? false : true;
}

void CriticalPath(GraphAdjList GL)
{
  EdgeNode * e;
  int i, gettop, k, j;
  int ete, lte; // 声明活动最早发生时间和最迟发生时间变量
  TopologicalSort(GL); // 求拓扑序列，计算数组etv和stack2的值
  ltv = (int *)malloc(GL->numVertexes * sizeof(int)); // 事件最晚发生时间
  for (i = 0; i < GL->numVertexes; i++)
    ltv[i] = etv[GL->numVertexes - 1]; // 初始化ltv
  while (top2 != 0)
  {
    gettop = stack2[top2--];
    // 求各顶点事件的最迟发生时间ltv值
    for (e = GL->adjList[gettop].firstedge; e; e->next)
    {
      k = e->adjvex;
      if (ltv[k] - e->weight < ltv[gettop])
        ltv[gettop] = ltv[k] - e->weight;
    }
  }
  for (j = 0; j < GL->numVertexes; j++) // 求ete, lte和关键活动
  {
    for (e = GL->adjList[j].firstedge; e; e = e->next)
    {
      k = e->adjvex;
      ete = etv[j]; // 活动最早发生时间
      lte = ltv[k] - e->weight; // 活动最迟发生时间
      if (ete == lte)
        printf("<v%d, v%d> length: %d , ",
        GL->adjList[j].data, GL->adjList[k].data, e->weight);
    }
  }
}