/*
 * Primeira fase da maratona 2014
 * Problema: pizza
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4666
 * Resposta: AC
 */

#include <cstdio>

int pos[10010];
int N, C;


bool entre(int x, int a, int b)
{
  a %= C;
  b %= C;
  x %= C;
  if(a < b)
    return (a <= x && x < b);
  return (a <= x || x < b);
}

bool go(int s)
{
  int p = C/N;
  for(int i = 0; i < N; i++){
    if(!entre(pos[i], s, s+p))
      return false;
    s += p;
  }
  return true;
}

char solve()
{
  int q = C/N;
  for(int i = C-q+1; i <= C + q; i++)
    if(go(i%C))
      return 'S';
  return 'N';
}

int main()
{
  while(scanf(" %d %d", &C, &N) == 2){
    for(int i = 0; i < N; i++)
      scanf(" %d", pos+i);
    printf("%c\n", solve());
  }
  return 0;
}
