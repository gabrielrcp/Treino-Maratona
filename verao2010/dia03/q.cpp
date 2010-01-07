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
    int n;
    scanf(" %d", &n);
    int r = 1;
    while((1 << r) <= n)
      r++;
    printf("%d\n", r);
  }
  return 0;
}
