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

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %d", v+i);
    }

    int melhor = 0;
    int i = 0;
    while(i < n){
      int j = i;
      while(j < n && v[j] > 0)
	j++;
      melhor = max(melhor, j-i);
      i = j + 1;
    }
    printf("%d\n", melhor);
  }
  return 0;
}

