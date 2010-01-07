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

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    sort(v, v+n);

    int r = 0;
    for(int i = 0; i < n; i++){
      r = max(r, v[i] * (n - i));
    }
    printf("%d\n", r);
  }
  return 0;
}
