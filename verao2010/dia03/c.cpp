#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int teto(int n, int d)
{
  int r = n / d;
  if(n % d) r++;
  if(r < 0) r = 0;
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int k, s = 0;
    scanf(" %d", &k);
    for(int i = 0; i < k; i++){
      int x;
      scanf(" %d", &x);
      s += x;
    }
    printf("%d\n", teto(95*k - 10*s, 5));
  }
  return 0;
}
