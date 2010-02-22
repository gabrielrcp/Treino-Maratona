#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 110

int pai[MAX];

int find(int x)
{
  if(x == pai[x])
    return x;
  pai[x] = find(pai[x]);
  return pai[x];
}


int main()
{
  int n;
  for(int h = 1; scanf(" %d", &n) && n; h++){

    int m;
    scanf(" %d", &m);
    for(int i = 0; i < n; i++)
      pai[i] = i;
    
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      int pi = find(i);
      int pj = find(j);
      if(pi != pj)
	pai[pi] = pj;
    }

    int x = find(0);
    bool fail = false;
    for(int i = 1; i < n && (!fail); i++)
      if(find(i) != x)
	fail = true;
    
    printf("Teste %d\n%s\n\n", h, fail ? "falha" : "normal");

  }
}
