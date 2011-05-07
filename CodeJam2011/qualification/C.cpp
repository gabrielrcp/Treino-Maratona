#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int n;
    scanf(" %d", &n);
    int r = 0, m = 1<<25, s = 0;
    for(int i = 0; i < n; i++){
      int x;
      scanf(" %d", &x);
      s += x;
      m = min(m, x);
      r ^= x;
    }
    printf("Case #%d: ", h);
    if(r != 0){
      printf("NO\n");
    } else{
      printf("%d\n", s-m);
    }
  }
  return 0;
}
