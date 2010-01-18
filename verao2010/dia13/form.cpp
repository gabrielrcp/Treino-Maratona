#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100010
typedef long long ll;

ll bit[MAX][12];
int v[MAX];

void update(int p, ll x, int k)
{
  while(p < MAX){
    bit[p][k] += x;
    p += (p & (-p));
  }
}

ll get(int p, int k)
{
  ll resp = 0;
  while(p > 0){
    resp += bit[p][k];
    p -= (p & (-p));
  }
  return resp;
}


int main()
{
  freopen("form.in", "r", stdin);
  freopen("form.out", "w", stdout);

  int n, k;
  scanf(" %d %d", &n, &k);

  memset(bit, 0, sizeof bit);


  for(int i = 0; i < n; i++){
    int x;
    scanf(" %d", &x);

    update(x+1, 1, 0);
    for(int j = 1; j <= k; j++){
      ll r = get(x, j-1);
      update(x+1, r, j);
    }
  }
  printf("%lld\n", get(MAX-1, k));

  return 0;
}
