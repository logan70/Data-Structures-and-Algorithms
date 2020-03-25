#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP(char * t, char * p);
void getnext(char * p, int * next);

int main(void)
{
  KMP("abcdcccaassf", "assf");
  KMP("abcdcccaassf", "cdccc");
  KMP("abcdcccaassf", "caassfc");
  return 0;
}

int KMP(char * t, char * p)
{
  int i = 0, j = 0;
  int tlen = (int)strlen(t);
  int plen = (int)strlen(p);
  int next[plen];
  getnext(p, next);
  while (i < tlen && j < plen)
  {
    if (j == -1 || t[i] == p[j])
    {
      i++;
      j++;
    }
    else
      j = next[j];
  }
  if (j == plen)
  {
    printf("\"%s\" is in \"%s\" from index %d\n", p, t, i - j);
    return i - j;
  }
  printf("\"%s\" is not in \"%s\"\n", p, t);
  return -1;
}

void getnext(char * p, int * next)
{
  int i = 0, j = -1;
  next[i] = j;
  while (i < strlen(p) - 1)
  {
    if (j == -1 || p[i] == p[j])
    {
      i++;
      j++;
      printf("next[%d] = %d\n", i, j);
      next[i] = j;
    }
    else
      j = next[j];
  }
}
