#include <cstdio>
#include <iostream>

using namespace std;


long double p[510][3010];

int main()
{
  freopen("die.in", "r", stdin);
  freopen("die.out", "w", stdout);

  int n, q;
  
  scanf(" %d %d", &n, &q);
  p[0][0] = 1.0;
  for(int j = 1; j <= q; j++)
    p[0][j] = 0.0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= q; j++){
      p[i][j] = 0.0;
      for(int k = 1; k <= 6; k++)
	if(j - k >= 0)
	  p[i][j] += p[i-1][j-k]/6.0;
    }
  }
  cout << p[n][q] << endl;
  return 0;
}
