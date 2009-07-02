#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double r2;

double resolve(int n, int m)
{
  if(n % 2 == 1 && m % 2 == 1){
    int r = m*n - 1;
    return (double)r + r2;
  }
  int r = 2*(n-1) + 2*(m-1) + (m-2) * (n-2);
  return (double) r;    
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  r2 = sqrt(2.0);
  for(int h = 1; h <= casos; h++){
    int n, m;
    scanf(" %d %d", &n, &m);
    printf("Scenario #%d:\n", h);
    printf("%.2lf\n\n", resolve(n, m));
  }
  return 0;
}
