#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int n;
int tam[55];

bool ok(int x)
{
  for(int i = 0; i < n; i++){
    if(x >= 2*tam[i] && x <= 10*tam[i])
      return false;
    if(tam[i] >= 2*x && tam[i] <= 10*x)
      return false;
  }
  return true;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int a, b;
    scanf(" %d %d %d", &a, &b, &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", tam+i);
    int conta = 0;
    for(int i = a; i <= b; i++)
      if(ok(i))
	conta++;
    printf("%d\n", conta);
  }
  return 0;
}
