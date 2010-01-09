#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;

int a[55], b[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n, m;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", a+i);

    scanf(" %d", &m);
    for(int i = 0; i < m; i++)
      scanf(" %d", b+i);

    int i = 0, j = 0;
    int s = 0;
    while(j < m){
      if(a[i] >= b[j]){
	a[i] -= b[j];
	j++;
      }
      else{
	s += a[i];
	i++;
      }
    }
    while(i < n){
      s += a[i];
      i++;
    }
    printf("%d\n", s);    
  }
  return 0;
}

