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

char v[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %s", v);

    int melhor = 0;
    int i = 0;
    while(v[i]){
      int j = i + 1;
      while(v[j] && v[j] == v[i])
	j++;
      melhor = max(melhor, j-i);
      i = j;
    }
    printf("%d\n", melhor);
  }
  return 0;
}

