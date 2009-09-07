#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000
#define MOD (10000)

char str[MAX];
char bsc[30] = "welcome to code jam";
int n, m;

int memo[MAX][30];


int conta(int i, int j)
{
  if(j == m) return 1;

  int &r = memo[i][j];
  if(r != -1) return r;

  r = 0;
  for(int k = i; k < n; k++)
    if(str[k] == bsc[j])
      r = (r + conta(k+1, j+1)) % MOD;
  return r;
}

int main()
{
  int casos;
  scanf("%d\n", &casos);
  m = strlen(bsc);
  for(int h = 1; h <= casos; h++){
    gets(str);
    n = strlen(str);
    for(int i = 0; i <= n; i++)
      for(int j = 0; j < 30; j++)
	memo[i][j] = -1;
    printf("Case #%d: %04d\n", h, conta(0, 0));
  }
  return 0;
}
