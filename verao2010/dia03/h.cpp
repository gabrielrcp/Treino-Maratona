#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int a[55], b[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;

    int s = 0;    
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d", a+i);
      s += a[i];
    }

    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d", b+i);
      s += b[i];
    }

    int r = 0;
    for(int i = 0; i < n; i++){
      if(n*(a[i]+b[i]) < s)
	r++;
    }
    printf("%d\n", r);
    
  }
  return 0;
}
