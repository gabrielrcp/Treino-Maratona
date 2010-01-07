#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int ini, n;
    scanf(" %d %d", &ini, &n);
    while(n--){
      char c; int x;
      scanf(" %c %d", &c, &x);
      if(c == 'D') x = -x;
      ini += x;
    }
    printf("%d\n", ini);
  }
  return 0;
}
