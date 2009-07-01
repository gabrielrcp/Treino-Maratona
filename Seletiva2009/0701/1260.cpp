#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 110
#define INF (1 << 30)

int v[MAX];
int preco[MAX];
int memo[MAX][MAX];
int n;

int vai(int i, int j)
{
  if(i+1 == n){
    return (v[i]+10) * preco[i];
  }

  int &r = memo[i][j];
  if(r != -1)
    return r;

  r = 10;
  for(int k = i; k <= j; k++)
    r += v[k];
  r *= preco[j];

  if(j+1 < n){
    int t = INF;
    for(int k = j+1; k < n; k++)
      t = min(t, vai(j+1, k));
    r += t;
  }
  //printf("%d %d %d\n", i+1, j+1, r);

  return r;  
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d %d", v+i, preco+i);
      for(int j = 0; j < n; j++)
	memo[i][j] = -1;
    }
    
    int r = INF;
    for(int j = 0; j < n; j++)
      r = min(r, vai(0, j));
    printf("%d\n", r);
  }
  
  return 0;
}
