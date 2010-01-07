#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int a[50], b[50];

int tmp[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    int n, m;
    scanf(" %d", &n);

    scanf(" %d", &m);
    for(int i = 0; i < m; i++){
      int x;
      scanf(" %d", &x);
      a[x]++;
    }
    scanf(" %d", &m);
    for(int i = 0; i < m; i++){
      int x;
      scanf(" %d", &x);
      b[x]++;
    }

    int r = 0;
    for(int i = 1; i < n; i++){
      if(b[i] > b[r] || (b[i] == b[r] && a[i] > a[r]))
	r = i;
    }
    printf("%d\n", r);

  }
  return 0;
}
