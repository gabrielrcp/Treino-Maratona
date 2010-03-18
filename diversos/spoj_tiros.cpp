#include <cstdio>
#include <algorithm>
#include <cctype>

using namespace std;

#define MAX (1010)
typedef long long ll;

struct Ponto{
  int x, y;
};

int n;
Ponto pts[MAX];
Ponto pd[MAX];

ll prod_vet(Ponto a, Ponto b)
{
  return ((ll)a.x*b.y - (ll)a.y*b.x);
}

bool compara(const Ponto &a, const Ponto &b)
{
  return (prod_vet(a, b) < 0);
}

int pivota(int p)
{
  int m = 0;
  for(int i = 0; i < n; i++){
    if(i == p) continue;
    pd[m].x = pts[i].x - pts[p].x;
    pd[m].y = pts[i].y - pts[p].y;

    if(pd[m].x < 0 || (pd[m].x == 0 && pd[m].y < 0)){
      pd[m].x = -pd[m].x;
      pd[m].y = -pd[m].y;
    }
    m++;
  }

  sort(pd, pd+m, compara);

  int r = 1;
  int i = 0, j = 1;
  while(i < m){
    j = i + 1;
    while(j < m && prod_vet(pd[i], pd[j]) == 0)
      j++;
    r = max(r, j-i+1);
    i = j;
  }
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d %d", &pts[i].x, &pts[i].y);
    }

    int r = 0;
    for(int i = 0; i < n; i++)
      r = max(r, pivota(i));
    printf("%d\n", r);
  }
  return 0;
}
