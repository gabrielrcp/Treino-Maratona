#include <cstdio>

int ler()
{
  int h, m;
  scanf(" %d %d", &h, &m);
  return 60*h+m;
}

int main()
{
  while(1){
    int t1 = ler();
    int t2 = ler();
    if(t1 == 0 && t2 == 0) break;
    if(t2 < t1) t2 += 24*60;
    printf("%d\n", t2 - t1);
  }
  return 0;
}
