#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100010

typedef pair<int, int> pii;

pii v[MAX];
int n;

bool compara(const pii  &a, const pii &b)
{
  int da = (a.second-a.first)/2 + 1;
  int db = (b.second-b.first)/2 + 1;

  if(a.first + da <= b.second - db)
    return true;
  if(b.first + db <= a.second - da)
    return false;

  return a < b;
}

int main()
{
  while(scanf(" %d", &n) && n){
    for(int i = 0; i < n; i++)
      scanf(" %d %d", &v[i].first, &v[i].second);
    sort(v, v+n, compara);

    int at = 0;
    bool fail = false;
    for(int i = 0; i < n; i++){
      at = max(at, v[i].first);
      at += (v[i].second-v[i].first)/2 + 1;
      if(at > v[i].second){
	fail = true;
	break;
      }

    }

    printf("%s\n", (fail ? "NO" : "YES"));
  }
  return 0;
}
