#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

long long mat[30][4][4];
long long pot[30][4][4];

int n;
long long m;
long long a;



long long resolve()
{

  mat[0][1][1] = mat[0][3][1] = (4LL*a*a)%m;
  mat[0][1][2] = mat[0][3][2] = ((((-4LL*a)%m)+m)%m);
  mat[0][2][1] = (2LL*a)%m;
  mat[0][2][2] = m-1;


  for(int l = 1; (1 << l) <= n; l++){
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
	mat[l][i][j] = 0;
	for(int k = 0; k < 4; k++)
	  mat[l][i][j] += mat[l-1][i][k] * mat[l-1][k][j];
	mat[l][i][j] %= m;
      }
    }
  }

  int at = 0;
  for(int l = 0; (1 << l) <= n; l++){
    if((1<<l) & n){
      for(int i = 0; i < 4; i++){
	for(int j = 0; j < 4; j++){
	  pot[at+1][i][j] = 0;
	  for(int k = 0; k < 4; k++)
	    pot[at+1][i][j] += pot[at][i][k] * mat[l][k][j];
	  pot[at+1][i][j] %= m;
	}
      }
      at++;
    }
  }

  long long v[4] = {1, (a*a)%m, a%m, (1+a*a)%m};
  long long resp = 0;
  for(int k = 0; k < 4; k++)
    resp += pot[at][3][k] * v[k];
  resp %= m;
  return resp;
}

int main()
{
  int casos;
  scanf(" %d", &casos);


  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++){
      mat[0][i][j] = 0;
      pot[0][i][j] = ((i == j) ? 1 : 0);
    }

  mat[0][0][1] = mat[0][1][0] = mat[0][3][0] = mat[0][3][3] = 1;

  while(casos--){
    scanf(" %lld %d %lld", &a, &n, &m);
    n -= 2;
    printf("%lld\n", resolve());
  }
  return 0;
}
