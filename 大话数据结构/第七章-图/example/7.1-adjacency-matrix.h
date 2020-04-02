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


// 建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph * G);