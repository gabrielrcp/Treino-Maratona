#include <cstdio>
#include <algorithm>

using namespace std;

int t, x;
int m;

int main()
{
  while(scanf(" %d", &t) == 1 && t >= 0){
    scanf(" %d %d", &x, &m);
    int menor = t;
    for(int i = 0; i < m; i++){
      int d, s, at;
      scanf(" %d %d", &d, &s);
      at = d/s - ((d%s == 0) ? 1 : 0);
      menor = min(menor, at);
    }
    int resp;
    if(menor != 0)
      resp = menor + (t - menor)/2;
    else
      resp = 0;
    printf("%d\n", x*resp);
  }
  return 0;
}
