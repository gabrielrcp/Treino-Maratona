#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

#define MAX 510

int n, m;

int qtd[2][MAX][MAX];
int somacum1[MAX][MAX];
int somacum2[MAX][MAX];


inline int soma1(int i, int j)
{
  return somacum1[i][j];
}

inline int soma2(int i, int j)
{
  return somacum2[i][j];

}

int memo[MAX][MAX];

int vai(int i, int j)
{
  if(i < 0 || j < 0)
    return 0;

  int &resp = memo[i][j];
  if(resp != -1)
    return resp;

  resp  = soma2(i, j) + vai(i, j-1);
  int t = soma1(i, j) + vai(i-1, j);
  if(t > resp)
    resp = t;

  return resp;
}


int main()
{
  while(1){
    scanf(" %d %d", &n, &m);

    if(n == 0 || m == 0)
      break;

    if(n <= m){
      for(int k = 0; k < 2; k++)
	for(int i = 0; i < n; i++)
	  for(int j = 0; j < m; j++)
	    scanf(" %d", &qtd[k][i][j]);
    }
    else{
      for(int k = 0; k < 2; k++){
	for(int i = 0; i < n; i++)
	  for(int j = 0; j < m; j++)
	    scanf(" %d", &qtd[k][j][i]);
      }
      int t = n;
      n = m;
      m = t;      
    }

    for(int i = 0; i < n; i++){
      somacum1[i][0] = qtd[0][i][0];
      for(int j = 1; j < m; j++)
	somacum1[i][j] = qtd[0][i][j] + somacum1[i][j-1];
    }
    for(int j = 0; j < m; j++){
      somacum2[0][j] = qtd[1][0][j];
      for(int i = 1; i < n; i++)
	somacum2[i][j] = qtd[1][i][j] + somacum2[i-1][j];
    }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	memo[i][j] = -1;

    printf("%d\n", vai(n-1, m-1));

  }
  return 0;
}
