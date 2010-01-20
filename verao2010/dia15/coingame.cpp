#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 200

int v[MAX];
int soma[MAX];

int memo[MAX][100];

int vai(int n, int k)
{
  if(n <= k)
    return soma[n];

  int &r = memo[n][k];
  if(r != -1) return r;

  r = 0;
  for(int j = 1; j <= k; j++)
    r = max(r, soma[n] - vai(n-j, j));
  return r;
}

int main()
{
  freopen("coingame.in", "r", stdin);
  freopen("coingame.out", "w", stdout);

  int n, k;
  scanf(" %d", &n);
  soma[0] = 0;
  for(int i = n; i > 0; i--)
    scanf(" %d", v+i);

  for(int i = 1; i <= n; i++)
    soma[i] = soma[i-1] + v[i];

  scanf(" %d", &k);
  /*
  for(int i = 1; i <= n; i++)
    fprintf(stderr, "%d\n", v[i]);
  */
  memset(memo, -1, sizeof memo);

  printf("%d\n", vai(n, k));

  return 0;
}
