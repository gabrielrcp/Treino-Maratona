#include <cstdio>
#include <cstring>

#define MOD (100003)
#define MAX (510)

typedef long long ll;

ll pd[MAX][MAX];
ll cb[MAX][MAX];

ll comb(int a, int b)
{
  if(b < 0 || b > a)
    return 0;
  return cb[a][b];
}

ll vai(int x, int k)
{
  if(k == 1) return 1;

  ll &r = pd[x][k];
  if(r != -1) return r;
  r = 0;
  for(int i = 1; i < k; i++){
    int a = x-k-1;
    int b = k-i-1;
    r = (r + vai(k, i) * comb(a, b)) % MOD;
  }
  return r;
}

int main()
{
  memset(pd, -1, sizeof pd);

  for(int i = 0; i < MAX; i++)
    cb[i][0] = cb[i][i] = 1;
  for(int i = 2; i < MAX; i++)
    for(int j = 1; j < i; j++)
      cb[i][j] = ((cb[i-1][j] + cb[i-1][j-1])%MOD);

  int casos, n;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    ll r = 0;
    for(int i = 1; i <= n; i++)
      r += vai(n, i);
    r %= MOD;
    printf("Case #%d: %lld\n", h, r);
  }
  return 0;
}
