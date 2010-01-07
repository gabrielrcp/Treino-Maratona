#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

char mat[200][200];

int p, q;
int n;

bool ok(int i)
{
  int v = 0, d = 0;
  for(int j = 0; j < n; j++)
    if(mat[i][j] == 'W')
      v++;
    else if(mat[i][j] == 'L')
      d++;

  if(100*v < (n-1)*p) return false;
  if(100*d < (n-1)*q) return false;
  return true;
  
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf(" %c", &mat[i][j]);

    scanf(" %d %d", &p, &q);

    int r = 0;
    while(r < n && ok(r))
      r++;
    if(r == n) r = -1;
    printf("%d\n", r);
  }
  return 0;
}
