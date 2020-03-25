// 暴风(Brute Force)算法是普通的模式匹配算法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BF(char * t, char * p);

int main(void)
{
  BF("abbaabbaaba", "abbaaba");
  BF("abbaabbaaba", "bbaa");
  BF("abbaabbaaba", "abbaabab");
  return 0;
}

int BF(char * t, char * p)
{
  int i = 0, j = 0;
  int tlen = (int)strlen(t);
  int plen = (int)strlen(p);
  while (i < tlen && j < plen)
  {
    if (t[i] == p[j])
    {
      i++;
      j++;
    }
    else
    {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j == plen)
  {
    printf("\"%s\" is in \"%s\" from index %d\n", p, t, i - j);
    return i - j;
  }
  printf("\"%s\" is not in \"%s\"\n", p, t);
  return -1;
}