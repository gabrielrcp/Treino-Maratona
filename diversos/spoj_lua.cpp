#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100010

int v[MAX];

int main()
{
  int n, m;
  for(int h = 1; scanf(" %d %d", &n, &m) && n; h++){
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    int s = 0;
    for(int i = 0; i < m; i++)
      s += v[i];
    int mi = s, ma = s;
    for(int i = m; i < n; i++){
      s += v[i] - v[i-m];
      mi = min(s, mi);
      ma = max(s, ma);
    }
    printf("Teste %d\n%d %d\n\n", h, mi/m, ma/m);
  }
  return 0;
}
