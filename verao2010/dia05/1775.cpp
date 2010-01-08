// errado/incompleto

#include <cstdio>

#define MAX 110
#define EPS (1.0e-9)

double mat[MAX][MAX];

int ent[MAX][3];

char resol[MAX];

bool zero(double x)
{
  return (-EPS < x && x < EPS);
}

bool vai(int n, int m)
{
  for(int i = 0; i < n; i++){
    int j = 0;
    while(j < m && zero(mat[i][j]))
      j++;
    if(j == m){
      n--;
      for(j = 0; j < m; j++)
	mat[i][j] = mat[n][j];
      i--;
    }
    for(int k = i + 1; k < n; k++){
      double x = - mat[k][j] / mat[i][j];
      for(int l = 0; l < m; l++){
	mat[k][l] -= x * mat[i][l];
      }
    }
  }
  if(n == m) return false;

  for(int i = n-1; i >= 0; i--){
    
  }
}

int main()
{
  int n;
  scanf(" %d", &n);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++)
      scanf(" %d", &ent[i][j]);

  for(int i = 0; i < n; i++){

    for(int a = 0; a < MAX; a++)
      for(int b = 0; b < MAX; b++)
	mat[a][b] = 0.0;

    int k = 0;
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      for(int l = 0; l < 3; l++)
	mat[k][l] = 1.0 / ent[j][l] - 1.0/ent[i][l];
      mat[k][k+3] = -1.0;
      k++;
    }
    printf("%s\n", (vai(n-1, n-1+3) ? "YES" : "NO"));
  }

}
