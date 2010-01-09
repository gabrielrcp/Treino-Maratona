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

char mat[55][55];
int n, m;

int conta(int a, int b)
{
  int s = 0;
  for(int i = 0; i < n; i++){
    if(mat[i][a] < mat[i][b])
      s++;
  }
  return s;
}

bool ganha(int i)
{
  for(int j = 0; j < m; j++){
    if(j == i) continue;
    int c1 = conta(i, j);
    int c2 = conta(j, i);
    if(c1 <= c2) return false;
  }
  return true;
}

int resolve()
{
  for(int i = 0; i < m; i++)
    if(ganha(i))
      return i;
  return -1;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %s", mat[i]);
    m = strlen(mat[0]);

    printf("%d\n", resolve());

  }
  return 0;
}

