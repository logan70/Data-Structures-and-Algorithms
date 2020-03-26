#include <stdio.h>
#include <stdlib.h>
#include "6.4-threaded-bitree.h"
// 与6.5-threaded-bitree.c一起编译

void printBiTNode(char ch);

int main(void)
{
  BiThrTree * bithrtree;
  printf("Please enter chars as tree node(pre-order, # represent empty): ");
  // enter pre-order chars as tree node, # is empty
  // e.g. "ABDH#K###E##CFI###G#J##"
  CreateBiThrTree(bithrtree);
  
  printf("\nIn-Order traversing: \n");
  InOrderTraverse(*bithrtree, printBiTNode);
  printf("\n\n");
  
  printf("In-Order threaded traversing: \n");
  InThreading(*bithrtree);
  InOrderTraverse_Thr(*bithrtree, printBiTNode);
  printf("\n\n");

  return 0;
}

void printBiTNode(char ch)
{
  putchar(ch);
}