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
    int a[3], b[3];
    for(int i = 0; i < 3; i++)
      scanf(" %d", a+i);
    for(int i = 0; i < 3; i++)
      scanf(" %d", b+i);

    sort(b, b+3);
    int r = 0;
    do{
      int t = (a[0]/b[0]) * (a[1]/b[1]) * (a[2]/b[2]);
      r = max(r, t);
    }while(next_permutation(b, b+3));
    printf("%d\n", r);
  }
  return 0;
}
