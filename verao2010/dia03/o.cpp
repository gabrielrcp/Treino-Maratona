#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int memo[10010];

int main()
{
  int casos;
  scanf(" %d", &casos);
  memset(memo, -1, sizeof memo);
  while(casos--){
    int n;
    scanf(" %d", &n);
    if(memo[n] != -1){
      printf("%d\n", memo[n]);
      continue;
    }

    int r = 0;
    for(int i = 1; 2*i < n; i++){
      int j = (n - 2*i) / 2;
      r = max(r, i*j);
    }
    memo[n] = r;
    printf("%d\n", r);
  }
  return 0;
}
