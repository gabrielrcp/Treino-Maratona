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
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    sort(v, v+n);

    int melhor = 0;
    int i = 0;
    while(i < n){
      int j = i + 1;
      while(j < n && v[j] == v[i])
	j++;
      melhor = max(melhor, j-i);
      i = j;
    }

    vector<int> resp;
    i = 0;
    while(i < n){
      int j = i + 1;
      while(j < n && v[j] == v[i])
	j++;
      if(j - i == melhor)
	resp.push_back(v[i]);
      i = j;
    }
    printf("%u\n", resp.size());
    for(int i = 0; i < (int) resp.size(); i++)
      printf("%d\n", resp[i]);
  }
  return 0;
}

