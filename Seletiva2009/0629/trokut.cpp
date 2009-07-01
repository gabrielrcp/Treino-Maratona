#include <cstdio>

#define MAX 310
#define INF (1<<30)

int n;
int x[MAX], y[MAX];
int esq[MAX][MAX], dir[MAX][MAX];



int prod_vet(int i, int j, int k)
{
  int a, b, c, d;
  a = x[j] - x[i];
  b = y[j] - y[i];
  c = x[k] - x[i];
  d = y[k] - y[i];

  return (a*d - b*c);
}


int main()
{
  scanf(" %d", &n);

  for(int i = 0; i < n; i++)
    scanf(" %d %d", x+i, y+i);

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      esq[i][j] = dir[i][j] = 0;
      for(int k = 0; k < n; k++){
	if(k == i || k == j) continue;
	int t = prod_vet(i, j, k);
	if(t > 0)
	  esq[i][j]++;
	else if(t < 0)
	  dir[i][j]++;
      }
      esq[j][i] = dir[i][j];
      dir[j][i] = esq[i][j];
    }
  }
  
  int minimo = INF;
  int a, b, c;

  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      for(int k = j+1; k < n; k++){
	int soma = 0, t;
	
	t = prod_vet(i, j, k);
	if(t == 0) continue;

	if(t < 0)
	  soma += esq[i][j];
	else
	  soma += dir[i][j];

	if(prod_vet(j, k, i) < 0)
	  soma += esq[j][k];
	else
	  soma += dir[j][k];

	if(prod_vet(k, i, j) < 0)
	  soma += esq[k][i];
	else
	  soma += dir[k][i];

	if(soma < minimo){
	  minimo = soma;
	  a = i; b = j; c = k;
	}
      }
  printf("%d\n%d %d %d\n", n - minimo, a+1, b+1, c+1);

  return 0;
}
