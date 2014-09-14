/*
 * Primeira fase da maratona 2014
 * Problema: baralho
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4657
 * Resposta: AC
 */

#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

#define MAX (200010)

int v[MAX];
char vis[MAX];

int new_pos(int i, int n)
{
  if(i < n)
    return 2*i + 1;
  return 2*(i-n);
}

int go(int i)
{
  if(vis[i]) return 0;
  vis[i] = 1;
  return go(v[i]) + 1;
}

int main()
{
  int p;
  while(scanf(" %d", &p) == 1){
    for(int i = 0; i < p; i++)
      v[i] = new_pos(i, p/2);
    memset(vis, 0, p*sizeof(char));
    
    set<int> S;
    for(int i = 0; i < p; i++){
      int r  = go(i);
      if(r > 0)
	S.insert(r);
    }
    printf("%d\n", *S.rbegin());
  }

  return 0;
}
