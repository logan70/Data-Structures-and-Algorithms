#include <stdio.h>
#include <stdlib.h>
#include "6.1-bitree.h"
// 与6.2-bitree.c、linkqueue.c一起编译

void printBiTNode(char ch);

int main(void)
{
  BiTree * bitree;
  printf("Please enter chars as tree node(pre-order, # represent empty): ");
  // enter pre-order chars as tree node, # is empty
  // e.g. "ABDH#K###E##CFI###G#J##"
  CreateBiTree(bitree);
  
  printf("\nPre-Order traversing: \n");
  PreOrderTraverse(*bitree, printBiTNode);
  printf("\n\n");
  
  printf("In-Order traversing: \n");
  InOrderTraverse(*bitree, printBiTNode);
  printf("\n\n");
  
  printf("Post-Order traversing: \n");
  PostOrderTraverse(*bitree, printBiTNode);
  printf("\n\n");
  
  printf("BFS-Order traversing: \n");
  BFSTraverse(*bitree, printBiTNode);
  printf("\n");
  return 0;
}

void printBiTNode(char ch)
{
  putchar(ch);
}