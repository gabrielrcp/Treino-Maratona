#include <cstdio>
#include <algorithm>

using namespace std;

struct rect{
  int x1, y1, x2, y2;
};

rect ler()
{
  rect r;
  scanf(" %d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
  if(r.x1 > r.x2)
    swap(r.x1, r.x2);
  if(r.y1 > r.y2)
    swap(r.y1, r.y2);
  return r;
}

pair<rect, bool> inter(rect a, rect b)
{
  rect r;
  r.x1 = max(a.x1, b.x1);
  r.x2 = min(a.x2, b.x2);
  r.y1 = max(a.y1, b.y1);
  r.y2 = min(a.y2, b.y2);
  if(r.x1 > r.x2 || r.y1 > r.y2)
    return make_pair(r, false);
  return make_pair(r, true);
}

int main()
{
  int n;
  for(int h = 1; scanf(" %d", &n) && n; h++){
    rect at;
    at.x1 = -1000000;
    at.x2 = 1000000;
    at.y1 = -1000000;
    at.y2 = 1000000;

    bool fail = false;
    while(n--){
      rect novo = ler();
      if(!fail){
	pair<rect, bool> p = inter(at, novo);
	if(!p.second)
	  fail = true;
      at = p.first;
      }
    }
    printf("Teste %d\n", h);
    if(!fail)
      printf("%d %d %d %d\n\n", at.x1, at.y2, at.x2, at.y1);
    else
      printf("nenhum\n\n");
  }
}
