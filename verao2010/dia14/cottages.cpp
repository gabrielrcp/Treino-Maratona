#include <cstdio>
#include <bitset>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define MAX (310)
typedef long long ll;

struct reta{
  ll A, B, C;
  bool operator< (const reta &r) const{
    if(A == r.A){
      if(B == r.B)
	return (C < r.C);
      return (B < r.B);
    }
    return (A < r.A);
  }
};

struct ponto{
  int x, y;
};

ll gcd(ll a, ll b)
{
  if(a < b) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a%b);
}

reta cruza(ponto a, ponto b)
{
  reta r;
  r.A = - (b.y - a.y);
  r.B = b.x - a.x;
  r.C = a.x * (b.y - a.y) - a.y * (b.x - a.x);
  ll m = gcd(abs(r.A), abs(r.B));
  m = gcd(m, abs(r.C));

  r.A /= m;
  r.B /= m;
  r.C /= m;
  
  if(r.A < 0 || (r.A == 0 && r.B < 0)){
    r.A = -r.A;
    r.B = -r.B;
    r.C = -r.C;
  }
  return r;
}

ponto p[MAX];
int n;

int main() 
{
  freopen("cottages.in","r",stdin);
  freopen("cottages.out","w",stdout);

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
  }

  map<reta, set<int> > M;

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      reta r = cruza(p[i], p[j]);
      M[r].insert(i);
      M[r].insert(j);
    }
  }

  int res = 0;
  for(map<reta, set<int> >::iterator it = M.begin(); it != M.end(); it++){
    res += (it->second).size() - 1;
  }
  printf("%d\n", 2*res);
  return 0;
}
