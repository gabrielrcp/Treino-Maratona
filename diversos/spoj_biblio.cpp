#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


#define MAX 70

int n;
int v[MAX];
int sum[MAX];
int memo[MAX][MAX];

inline int soma(int i, int j)
{
  return sum[j+1] - sum[i];
}

int vai(int i, int j)
{
  if(i >= j) return 0;
  int &r = memo[i][j];
  if(r != -1) return r;

  r = (1<<30);
  for(int k = i; k <= j; k++){
    int t = vai(i, k-1) + soma(i, k-1) + vai(k+1, j) + soma(k+1, j);
    r = min(r, t);  
  }
  return r;
}

int main()
{

  for(int h = 1;scanf(" %d", &n) && n; h++){
    sum[0] = 0;
    for(int i = 0; i < n; i++){
      scanf(" %d", v+i);
      sum[i+1] = sum[i] + v[i];
    }

    memset(memo, -1, sizeof memo);
    printf("Teste %d\n%d\n\n", h, vai(0, n-1));
  }
  return 0;
}
