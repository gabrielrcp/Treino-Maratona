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

char a[55];
char b[55];
int dist[55];


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int k;
    scanf(" %s %s %d", a, b, &k);
    int n = strlen(a);
    for(int i = 0; i < n; i++){
      dist[i] = abs(a[i] - b[i]);
    }
    sort(dist, dist+n);
    int s = 0;
    for(int i = 0; i + k < n; i++)
      s += dist[i];
    for(int i = n - k; i < n; i++)
      if(dist[i] == 0)
	s++;
    printf("%d\n", s);
  }
  return 0;
}

