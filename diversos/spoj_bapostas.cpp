#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 10010

int v[MAX], s[MAX];
int P[MAX];
int topo;

int main()
{
  int n;
  while(scanf(" %d", &n) && n){

    s[0] = 0;
    for(int i = 1; i <= n; i++){
      scanf(" %d", v+i);
      s[i] = s[i-1] + v[i];
    }

    topo = 0;
    for(int i = 1; i <= n; i++){
      while(topo > 0 && s[P[topo-1]] <= s[i])
	topo--;
      P[topo++] = i;
    }

    int r = -1;
    int j = 0;
    for(int i = 1; i <= n; i++){
      while(P[j] < i) j++;
      r = max(r, s[P[j]] - s[i-1]);
    }
    if(r > 0)
      printf("The maximum winning streak is %d.\n", r);
    else
      printf("Losing streak.\n");
  }
  return 0;
}
