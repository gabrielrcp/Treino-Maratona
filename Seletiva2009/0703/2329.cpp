#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 210
#define INF (1<<25)

int matriz[MAX][MAX];
int n;
int prox_linha[MAX][MAX];

int resposta[MAX][MAX];

void monta()
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(matriz[i][j] != 0)
	prox_linha[i][j] = j;
      else{
	int d = INF;
	prox_linha[i][j] = INF;
	for(int k = 0; k < n; k++){
	  if(matriz[i][k] != 0){
	    if(abs(k-j) == d){
	      prox_linha[i][j] = -d;
	      d = -1;
	    }
	    else if(abs(k - j) < d){
	      prox_linha[i][j] = k;
	      d = abs(k-j);
	    }
	  }
	}
      }
    }
  }
}


int acha(int x, int y)
{
  int d = INF, t;
  bool empata = false;
  int resp = 0;

  for(int k = 0; k < n; k++){
    if(prox_linha[k][y] >= n) continue;
    if(prox_linha[k][y] >= 0){
      t = abs(prox_linha[k][y] - y) + abs(x-k);
      if(t == d)
	empata = true;
      else if(t < d){
	resp = matriz[k][prox_linha[k][y]];
	empata = false;
	d = t;
      }
    }
    else{
      t = -prox_linha[k][y] + abs(x-k);
      if(t <= d){
	empata = true;
	d = t;
      }
    }
  }
 
  if(empata)
    return 0;
  return resp;
}

void resolve()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      if(matriz[i][j] != 0)
	resposta[i][j] = matriz[i][j];
      else
	resposta[i][j] = acha(i, j);
    }
}

int main()
{
  scanf(" %d", &n);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf(" %d", &matriz[i][j]);

  monta();
  resolve();
  
  for(int i = 0; i < n; i++){
    printf("%d", resposta[i][0]);
    for(int j = 1; j < n; j++)
      printf(" %d", resposta[i][j]);
    printf("\n");
  }
  /*
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < n; j++)
      printf("%d ", prox_linha[i][j]);
    printf("\n");
  }
  */
  return 0;
}
