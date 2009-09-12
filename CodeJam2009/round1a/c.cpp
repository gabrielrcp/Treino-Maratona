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

double memo[50];
int c, n;


long long binom[50][50];

double bin(int n, int k)
{
  if(k > n) return 0.0;
  return (double)binom[n][k];
}


double prob(int k, int i)
{
  return bin(n-i, k) * bin(i, c-k) / bin(n, c);
}

double resolve(int i)
{
  if(i >= n)
    return 0.0;

  double &r = memo[i];
  if(r > -0.5)
    return r;

  r = prob(0, i);
  for(int j = 1; j <= c; j++)
    r += (1.0 + resolve(i+j))*prob(j, i);
  r /= (1.0 - prob(0, i));
  return r;
}

int main()
{

  for(int i = 0; i < 50; i++)
    binom[i][0] = binom[i][i] = 1;
  for(int i = 1; i < 50; i++){
    for(int j = 1; j < i; j++){
      binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
    }
  }

  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d %d", &n, &c);
    for(int i = 0; i <= n; i++)
      memo[i] = -1.0;
    printf("Case #%d: %f\n", h, resolve(0));
  }
  return 0;
}
