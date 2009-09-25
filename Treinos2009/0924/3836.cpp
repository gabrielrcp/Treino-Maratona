#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1100


int M[MAX][MAX];
int n, custo;
int memo[MAX];
int usadas[MAX];

int vai(int i)
{
  if(i == n) return 0;
  int &resp = memo[i];
  if(resp != -1) return resp;

  resp = (1<<30);
  int manut = custo;
  for(int k = i+1; k <= n; k++){
    manut += M[i][k-1];
    resp = min(resp, manut + vai(k));
  }
  return resp;
}

int main()
{
  while(scanf(" %d %d", &custo, &n) == 2){
    if(n >= MAX) return 2;
    custo = 0;
    for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++)
	scanf(" %d", &M[i][j]);
      memo[i] = -1;
    }
    printf("%d\n", vai(0));
  }
  return 0;
}
