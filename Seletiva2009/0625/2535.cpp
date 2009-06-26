#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 110

int notas[MAX][MAX];
int mini[MAX], maxi[MAX];
int n, p;

bool ehfacil(int j)
{
  int conta = 0;
  for(int i = 0; i < n; i++){
    if(notas[i][j] == mini[i])
      conta++;
    if(notas[i][j] == maxi[i])
      return false;
  }
  return (2*conta > n);
}

int main()
{
  scanf(" %d %d", &n, &p);
  for(int i = 0; i < n; i++){
    mini[i] = (1 << 30);
    maxi[i] = -1;
    for(int j = 0; j < p; j++){
      scanf(" %d", &notas[i][j]);
      mini[i] = min(mini[i], notas[i][j]);
      maxi[i] = max(maxi[i], notas[i][j]);
    }
  }

  int conta = 0;
  for(int j = 0; j < p; j++){
    if(ehfacil(j)){
      if(conta != 0)
	printf(" ");
      printf("%d", j+1);
      conta++;
    }
  }
  if(conta == 0)
    printf("0");
  printf("\n");

  return 0;
}
