#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define MAX 100010

struct vilao{
  int a, b, c;
  bool operator < (const vilao &outro) const{
    if(a != outro.a)
      return a < outro.a;
    if(b != outro.b)
      return b < outro.b;
    return c < outro.c;
  }
};

vilao v[MAX];
set < pair<int, int> > S;

int main()
{
  int n;
  long long m;
  while(1){
    scanf(" %d %lld", &n, &m);
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i < n; i++)
      scanf(" %d %d %d", &(v[i].a), &(v[i].b), &(v[i].c));

    sort(v, v+n);
    S.clear();

    S.insert(make_pair(m+1, 0));
    S.insert(make_pair(0, m+1));

    long long areaant = 0;
    long long resp = 0;
    int xant = m+1;
    for(int i = n-1; i >= 0; i--){
      int x = v[i].a, y = v[i].b, z = v[i].c;
      resp += areaant * (xant - x);
      xant = x;
      //printf("%d %d %d\n", x, y, z);
      set< pair<int, int> >::iterator pri, ult;
      ult = S.upper_bound(make_pair(y, z));

      if(ult->second >= z)
	continue;

      pri = ult;
      do{
	pri--;
      }while(pri->second <= z);

      /*
      printf("--  %d %d\n", pri->first, pri->second);
      printf("--  %d %d\n", ult->first, ult->second);
      */
      
      set< pair<int, int> >::iterator it, prox;
      it = pri; it++;
      prox = it; prox++;
      int yant = pri->first;
      while(it != ult){
	areaant -= (it->second - ult->second) * (it->first - yant);
	yant = it->first;
	S.erase(it);
	it = prox;
	prox++;
      }
      S.insert(make_pair(y, z));
      areaant += (y - pri->first) * (z - ult->second);
      //printf("-- %lld\n", areaant);
    }

    resp += areaant * xant;
    printf("%lld\n", m*m*m - resp);
  }

  return 0;
}
