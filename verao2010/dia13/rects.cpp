#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100010
typedef long long ll;
#define INF (1<<30)

struct retangulo{
  int id;
  int x1, y1, x2, y2;
  ll v, resp;
};

retangulo rect[MAX];
int n;


bool compara(const retangulo &a, const retangulo &b)
{
  if(a.x1 == b.x1)
    return a.y1 > b.y1;
  return a.x1 < b.x1;
}

ll bit[5*MAX];
int M;

ll get(int p)
{
  ll r = 0;
  while(p > 0){
    r = max(r, bit[p]);
    p -= (p & -p);
  }
  return r;
}

void update(int p, ll x)
{
  while(p < M+10){
    bit[p] = max(bit[p], x);
    p += (p & -p);
  }
}

int proximo[MAX];
int allY[5*MAX];

int main()
{
  //freopen("rects.in", "r", stdin);
  //freopen("rects.out", "w", stdout);
 
  scanf(" %d", &n);
  int M = 0;
  for(int i = 0; i < n; i++){
    scanf(" %d %d %d %d %lld", &rect[i].x1, &rect[i].y1,
	  &rect[i].x2, &rect[i].y2, &rect[i].v);
    rect[i].id = i+1;
    allY[M++] = rect[i].y1;
    allY[M++] = rect[i].y2;
  }
  allY[M++] = -INF;
  allY[M++] = INF;


  sort(allY, allY+M);
  M = unique(allY, allY+M) - allY;
  
  for(int i = 0; i < n; i++){
    rect[i].y1 = (int)(lower_bound(allY, allY+M, rect[i].y1) - allY);
    rect[i].y2 = (int)(lower_bound(allY, allY+M, rect[i].y2) - allY);
  }
  
  sort(rect, rect+n, compara);
  memset(proximo, -1, sizeof proximo);
  memset(bit, 0, sizeof bit);
      
  ll resp = 0;
  for(int i = n-1; i>= 0; i--){
    rect[i].resp = get(rect[i].y1) + rect[i].v;
    resp = max(resp, rect[i].resp);
    update(rect[i].y2+1, rect[i].resp);
    printf("-- %d %lld\n", rect[i].id, rect[i].resp);
  }

  printf("%lld\n", resp);
  int x = -INF, y = -INF;
  for(int i = 0; i < n; i++){
    if(rect[i].resp == resp && rect[i].x1 > x && rect[i].y1 > y){
      printf("%d ", rect[i].id);
      resp -= rect[i].v;
      x = rect[i].x2;
      y = rect[i].y2;
    }
  }
  printf("\n");

  return 0;
}
