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
#include <cctype>

using namespace std;

#define MAX 1000000

int memo[MAX][10];

int prox(int n, int b)
{
  int s = 0;
  while(n > 0){
    int d = n % b;
    s += (d*d);
    n /= b;
  }
  return s;
}


int resolve(int n, int b)
{
  if(n == 1) return 1;

  if(n < MAX){
    if(memo[n][b-2] != -1){
      if(memo[n][b-2] == -2)
	memo[n][b-2] = 0;
      return memo[n][b-2];
    }
  }

  if(n < MAX) memo[n][b-2] = -2;
  int r = resolve(prox(n, b), b);
  if(n < MAX) memo[n][b-2] = r;
  return r;
}

int bases[10];
int nb;
char buf[1000];

bool vale(int n)
{
  for(int i = 0; i < nb; i++)
    if(resolve(n, bases[i]) == 0)
      return false;
  return true;
}


void monta(int mask)
{
  nb = 0;
  for(int i = 0; i < 9; i++)
    if((1 << i) & mask)
      bases[nb++] = i+2;
}


int resposta()
{
  for(int n = 2;;n++)
    if(vale(n))
      return n;
}

int main()
{
  for(int i = 0; i < MAX; i++)
    for(int b = 0; b < 9; b++)
      memo[i][b] = -1;
  
  for(int mask = 1; mask < (1 << 9); mask++){
    monta(mask);

    printf("%d %d\n", mask, resposta());
  }
  return 0;
}
