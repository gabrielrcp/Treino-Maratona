#include <cstdio>


void vai(char *pre, char *em, int n)
{
  if(n == 0) return;
  int c = pre[0];

  int i = 0;
  while(em[i] != c)
    i++;
  vai(pre+1, em, i);
  vai(pre+1+i, em+i+1, n-1-i);
  putchar(c);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    char s1[100], s2[100];
    scanf(" %d %s %s", &n, s1, s2);
    vai(s1, s2, n);
    puts("");
  }
  return 0;
}
