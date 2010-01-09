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

int v[55];

bool melhor(int i, int j, int s, int mi, int mj, int ms)
{
  if((j - i) * ms < (mj - mi) * s)
    return true;
  if((j - i) * ms > (mj - mi) * s)
    return false;
  if(j - i > mj - mi)
    return true;
  if(j - i < mj - mi)
    return false;
  return (i < mi);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n, k;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    scanf(" %d", &k);
    
    int mi = 100, mj = 100, ms = -1;
    int i = 0;
    while(i + k <= n){
      int s = 0;
      for(int j = 0; j+1 < k; j++)
	s += v[i+j];
      int j = i+k;
      while(j <= n){
	s += v[j-1];
	if(melhor(i, j, s, mi, mj, ms)){
	  mi = i;
	  mj = j;
	  ms = s;
	}
	j++;
      }
      i++;
    }
    printf("2\n%d\n%d\n", mi, mj-1);
  }
  return 0;
}

