#include <cstdio>
#include <algorithm>
#include <string>

#define MAX 1000

using namespace std;

char mat[MAX][MAX];
int n, m;

int altura;

string cubo[6] = {"..+---+",
		  "./   /|",
		  "+---+ |",
		  "|   | +",
		  "|   |/.",
		  "+---+.." };


void imprime(int i, int j, int k)
{
  int x = 2*i + 3*k;
  altura = max(x+6, altura);
  int y = 2*i + 4*j;

  for(i = 0; i < 6; i++)
    for(j = 0; j < 7; j++)
      if(cubo[5-i][j] != '.')
	mat[x+i][y+j] = cubo[5-i][j];
}


int main()
{

  scanf(" %d %d", &n, &m);

  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      mat[i][j] = '.';
  altura = 0;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      int x;
      scanf(" %d",&x);
      for(int k = 0; k < x; k++)
	imprime(n-i-1, j, k);
    }
  

  int lim = 4*m+1 + 2*n;
  for(int i = altura-1; i >= 0; i--){
    for(int j = 0; j < lim; j++)
      putchar(mat[i][j]);
    printf("\n");
  }

  //imprimir matriz


  return 0;
}
