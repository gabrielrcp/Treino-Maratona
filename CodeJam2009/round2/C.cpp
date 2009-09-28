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

int graf[30][30];
int n, k;

bool pode[30][30];
int memo[(1<<18)];

int vai(int e)
{
  int &r = memo[e];
  if(r != -1) return r;

  r = n;
  int i = 0;
  while(!((e << i) & 1)) i++;




}


bool verifica(int i, int j)
{
  if(graf[i][0] > graf[j][0])
    swap(i, j);

  for(int l = 1; l < k; l++)
    if(graf[i][l] >= graf[j][l])
      return false;
  return true;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d %d", &n, &k);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < k; j++)
	scanf(" %d", &graf[i][j]);

    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++)
	pode[i][j] = pode[j][i] = verifica(i, j);

    for(int i = 1; i < (1<<n); i++)
      memo[i] = -1;
    memo[0] = 0;

    printf("Case #%d: %d\n", h, vai((1<<n)-1));
  }
  return 0;
}
