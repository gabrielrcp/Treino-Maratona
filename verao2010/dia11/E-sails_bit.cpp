#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100050
typedef long long ll;
typedef pair<int, int> pii;

int N;
pii v[MAX];

int bit[MAX];

int pos(int p)
{
  return MAX - p - 10;
}

void update(int i, int v)
{
  while(i < MAX){
    bit[i] += v;
    i += (i & (-i));
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

int maior;

int inicio(int v)
{
  if(v == 0) return maior;
  int e = 1, d = maior;
  int r = maior;
  while(e <= d){
    int m = (e+d)/2;
    int t = get(pos(m));
    if(t <= v){
      r = m;
      d = m - 1;
    }
    else if(t > v){
      e = m + 1;
    }
  }
  return r;
}

void adiciona(int k, int h)
{
  //printf("%d -- ", maior);
  int p = maior;
  if(p + k-1 <= h){
    update(pos(p+k-1), 1);
    update(pos(p-1), -1);
    maior = p + k;
    //printf("%d %d--\n", p, k);
    return;
  }
  p = h - (k-1);
  int x = get(pos(p));

  int p1 = inicio(x);
  int p2 = min(inicio(x-1), h+1);

  int k2 = h - p2+1;
  int k1 = k - k2;

  update(pos(p2+k2-1), 1);
  update(pos(p2-1), -1);
  update(pos(p1+k1-1), 1);
  update(pos(p1-1), -1);
  maior = h + 1;
  //printf("%d - %d %d %d %d\n", x, p1, k1, p2, k2);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &N);
    for(int i = 0; i < N; i++)
      scanf(" %d %d", &v[i].first, &v[i].second);
    sort(v, v+N);
    memset(bit, 0, sizeof bit);

    maior = 1;
    for(int i = 0; i < N; i++){
      int k = v[i].second, h = v[i].first;
      adiciona(k, h);
      /*
      for(int x = 1; x <= 5; x++)
	printf("%d ", get(pos(x)));
      printf("\n");
      */
    }
    
    ll r = 0;
    for(int x = 1; pos(x) > 0; x++){
      ll at = get(pos(x));
      //printf("%d %lld\n", x, at);
      r += at * (at-1)/2;
    }
    printf("%lld\n", r);

  }
  return 0;
}
