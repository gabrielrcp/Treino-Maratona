#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct ponto{
  int x, y;
  bool operator < (const ponto &outro) const{
    if(x == outro.x) return y < outro.y;
    return x < outro.x;
  }
};

#define MAX 110
typedef long long ll;

int n;
ll amax;
ponto pt[MAX];

void tiramerda()
{
  for(int i = 1; i < n; i++){
    if(pt[i-1].x == pt[i].x)
      pt[i-1].x = -1;
  }
  int i = 0;
  for(int j = 0; j < n; j++){
    if(pt[j].x != -1){
      pt[i] = pt[j];
      i++;
    }
  }
  n = i;
}

int memo[MAX][MAX][MAX];

int vai(int i, int j, int kk)
{
  if(i > j) return 0;
  if(i == j) return ((pt[i].y <= pt[kk].y) ? 0 : 1);
  int &resp = memo[i][j][kk];
  if(resp != -1) return resp;

  resp = 1 + vai(i+1, j, kk);
  if(pt[i].y <= pt[kk].y){
    resp = vai(i+1, j, kk);
    return resp;
  }

  ll ma = pt[i].y;
  for(int k = i + 1; k <= j; k++){
    ma = max((ll)pt[k].y, ma);
    int t = (1<<30);
    if(ma * (ll)(pt[k].x-pt[i].x) <= amax){
      t = 1 + vai(k+1, j, kk);
    } else if(pt[k].y <= pt[i].y && 
	      (ll)pt[i].y * (pt[k].x - pt[i].x) <= amax){
      t = 1 + vai(i+1, k-1, i) + vai(k+1, j, kk);
    } else if(pt[k].y >= pt[i].y && 
	      (ll)pt[k].y * (pt[k].x - pt[i].x) <= amax){
      t = 1 + vai(i+1, k-1, k) + vai(k+1, j, kk);
    }
    resp = min(resp, t);
  }
  return resp;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %lld", &n, &amax);
    for(int i = 0; i < n; i++)
      scanf(" %d %d", &pt[i].x, &pt[i].y);
    sort(pt, pt+n);
    tiramerda();
    pt[n].y = -1;

    memset(memo, -1, sizeof memo);
    printf("%d\n", vai(0, n-1, n));
  }
  return 0;
}
