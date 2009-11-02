#include <cstdio>

#define MAX 510

int n, m;
int mat[MAX][MAX];
int l1[MAX], l2[MAX];

void monta(int *l, int v)
{
  
  l[n] = 0;
  for(int i = n-1; i >= 0; i--){
    l[i] = l[i+1];
    while(l[i] < m && mat[i][l[i]] < v)
      l[i]++;
  }
}

int resolve(int a, int b)
{
  monta(l1, a);
  monta(l2, b+1);
  int r = 0;
  for(int i = 0; i < n; i++){
    int j = l1[i];
    while(i + r < n && j + r < l2[i+r])
      r++;
  }
  return r;
}

int main()
{
  while(scanf(" %d %d", &n, &m) && n && m){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	scanf(" %d", &mat[i][j]);

    int q;
    scanf(" %d", &q);
    while(q--){
      int a, b;
      scanf(" %d %d", &a, &b);
      printf("%d\n", resolve(a, b));
    }
    printf("-\n");
  }
  return 0;
}
