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
    
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", a+i);

    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", b+i);

    sort(a, a+n);
    sort(b, b+n);

    int i = 0, j = 0;
    int c = 0;
    while(i < n && j < n){
      if(a[i] == b[j]){
	c++;
	i++; j++;
      }
      if(a[i] < b[j])
	i++;
      if(a[i] > b[j])
	j++;
    }

    printf("%d\n", n - c);
    
  }
  return 0;
}
