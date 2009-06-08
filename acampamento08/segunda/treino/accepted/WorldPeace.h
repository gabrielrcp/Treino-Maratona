#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

vector<int> v;
long long k;

bool tenta(long long n)
{
  long long r = 0;
  for(int i = 0; i < v.size(); i++)
    r += min((long long)v[i], n);
  //printf("%lld %lld %lld\n", r, n, k);
  return(r >= (n * k));
}

class WorldPeace {
 public:
  long long numGroups(int _k, vector<int> countries) {
    v = countries;
    k = _k;
    long long e = 0, d = (1LL << 50);
    while(e < d){
      //printf("%lld %lld\n", e, d);
      long long  m = e + (d - e + 1LL)/2LL;
      if(tenta(m))
	e = m;
      else
	d = m - 1LL;
    }
    return e;
  }

};
