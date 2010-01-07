#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int v[55];
int paga[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n, s = 0;

    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d", v+i);
      s += 100*v[i];
    }
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", paga+i);

    int f;
    scanf(" %d", &f);
    s -= 100*v[f];
    s -= paga[f]*v[f];

    printf("%d\n", s);
  }
  return 0;
}
