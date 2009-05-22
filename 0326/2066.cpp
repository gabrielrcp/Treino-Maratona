#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 55
#define INF (1 << 30)

int x[MAX], y[MAX];
int n;

int areatri(int i, int j, int k)
{
  int ax = x[j] - x[i];
  int ay = y[j] - y[i];
  int bx = x[k] - x[i];
  int by = y[k] - y[i];

  double r = (ax*by - ay*bx);
 
  return (r > 0 ? r : INF);
}

int memo[MAX][MAX];

int resolve(int i, int j)
{

  if(j == ((i+1)%n))
    return 0;

  int &r = memo[i][j];
  if(r != -1)
    return r;

  r = INF;
  for(int k = ((i+1)%n); k != j; k = ((k+1)%n)){
    int t = areatri(i, k, j);
    t = max(t, max(resolve(i,k), resolve(k, j)));
    r = min(r, t);
  }
  return r;
}

bool horario()
{
  long long s = 0;
  for(int i = 0; i < n; i++)
    s += x[i]*y[(i+1)%n] - x[(i+1)%n]*y[i];
  return s < 0;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d %d", x+i, y+i);

    int r = INF;
    if(horario()){
      reverse(x, x+n);
      reverse(y, y+n);
    }    

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	memo[i][j] = -1;

    for(int i = 0; i < n; i++){
      int t = areatri(i, (i+1) % n, (i+2)%n);
      t = max(t, resolve((i+2)%n, i));
      r = min(r, t);
    }

    if(r % 2 == 1)
      printf("%d.5\n", r/2);
    else
      printf("%d.0\n", r/2);
  }
  return 0;
}
