#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 50

int n;
char mat[MAX][MAX];
int v[MAX];

int resp = 0;

int resolve()
{
  int resp = 0;
  for(int i = 0; i < n; i++){
    int j = i;
    while(v[j] > i) j++;
    for(int k = j; k > i; k--){
      resp++;
      swap(v[k], v[k-1]);
    }
  }
  return resp;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %s", mat[i]);
    for(int i = 0; i < n; i++){
      v[i] = 0;
      for(int j = 1; j < n;j++)
	if(mat[i][j] == '1')
	  v[i] = j;
    }
    printf("Case #%d: %d\n", h, resolve());
  }
  return 0;
}
