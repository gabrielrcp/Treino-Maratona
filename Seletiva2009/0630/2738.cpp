#include <cstdio>
#include <algorithm>

#define MAX 1010

using namespace std;

int v[MAX];
int memo[MAX][MAX];


int vai(int i, int j)
{
  if(i == j)
    return 0;

  if(memo[i][j] != -1)
    return memo[i][j];

  int r1, r2;

  r1 = v[i] - max(v[i+1], v[j]);
  if(v[i+1] >= v[j])
    r1 += vai(i+2, j);
  else
    r1 += vai(i+1, j-1);

  r2 = v[j] - max(v[i], v[j-1]);
  if(v[i] >= v[j-1])
    r2 += vai(i+1, j-1);
  else
    r2 += vai(i, j-2);
      
  memo[i][j] = max(r1,r2);
  return max(r1, r2);
  
}

int main()
{
  int n;
  for(int h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0)
      break;
    for(int i = 0; i < n; i++){
      scanf(" %d", v+i);
      for(int j = i+1; j < n; j++)
	memo[i][j] = -1;
    }

    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",
	   h, vai(0, n-1));
  }
  return 0;
}
