#include <cstdio>
#include <cstring>

#define MAX 100010
int v[MAX];

int bit[MAX];
int n;

void add(int p, int v)
{
  while(p <= n){
    bit[p] += v;
    p += (p & (-p));
  }
}

int get(int p)
{
  int r = 0;
  while(p > 0){
    r += bit[p];
    p -= (p & (-p));
  }
  return r;
}

int busca(int k)
{
  int e = 1, d = n;
  int r = d;
  while(e <= d){
    int m = (e+d)/2;
    int v = get(m);
    if(v > k){
      r = m;
      d = m - 1;
    } else
      e = m + 1;
  }
  return r;
}

int main()
{
  int m;
  while(scanf(" %d %d", &n, &m) && n > 0){
    memset(v, -1, sizeof v);
    memset(bit, 0, sizeof bit);

    for(int i = 1; i <= n; i++)
      add(i, 1);

    int i = 1;
    while(m--){
      int k;
      scanf(" %d", &k);
      int j = busca(k);
      v[j] = i;
      add(j, -1);
      i++;
    }
    for(int j = 1; j <= n; j++)
      if(v[j] == -1)
	v[j] = i++;
    printf("%d", v[1]);
    for(int j = 2; j <= n; j++)
      printf(" %d", v[j]);
    printf("\n");
  }
  return 0;
}
