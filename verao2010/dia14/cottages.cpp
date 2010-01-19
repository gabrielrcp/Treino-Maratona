#include <cstdio>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 310;
const double EPS = 1e-9;

struct Point { int x,y; Point(int x=0, int y=0) : x(x), y(y) {} };

int n;
struct B {
  bitset<MAXN> b;
  bool operator<(const B& o) const {
    for (int i=0; i < n; ++i)
      if (b[i]!=o.b[i])
	return b[i]<o.b[i];
    return false;
  }
  void set(int n) { b.set(n); }
  void print() const{
    for (int i = 0; i < n; ++i) if (b[i]) printf("%d ", i);
    puts("");
  }
};

Point p[MAXN];
set< B > s;

int ccw(Point& a, Point& b, Point& c) {
  int p = a.x*b.y+b.x*c.y+c.x*a.y;
  int n = a.y*b.x+b.y*c.x+c.y*a.x;
  return p - n;
}

Point ortog(Point a)
{
  int t = a.x;
  a.x = -a.y;
  a.y = t;
  return a;
}


int main() {
  freopen("cottages.in","r",stdin);
  freopen("cottages.out","w",stdout);

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
  }

  B all, empty;
  for (int i = 0; i < n; ++i) {
    all.set(i);
    for (int j = 0; j < n; ++j) {
      if(i == j) continue;
      Point a(p[i].x, p[i].y);
      Point b(p[j].x, p[j].y);
      Point ort(b.x-a.x, b.y-a.y);
      ort = ortog(ort);
      ort.x += a.x;
      ort.y += a.y;
      Point c (2*b.x-a.x, 2*b.y-a.y);

      B bs;
      for(int k = 0; k < n; k++){
	if(k == i || k == j) continue;
	if(ccw(a, b, p[k]) < 0){
	  bs.set(k);
	} else if(ccw(a, b, p[k]) == 0){
	  if((ll)ccw(a, ort, b) * (ll)ccw(a, ort, p[k]) < 0)
	    bs.set(k);
	}
      }
      bs.set(i);
      s.insert(bs);

      ort.x += b.x - a.x;
      ort.y += b.y - a.y;

      for(int k = 0; k < n; k++){
	if(k == i || k == j) continue;
	if(ccw(a, b, p[k]) == 0){
	  if((ll)ccw(b, ort, c) * (ll)ccw(b, ort, p[k]) < 0)
	    bs.set(k);
	}
      }
      bs.set(j);
      s.insert(bs);
    }
  }

  int res = s.size() - s.count(all) - s.count(empty);
  printf("%d\n", res);
  return 0;
}
