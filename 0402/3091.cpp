#include <cstdio>

#define MAX 1010

int pos[MAX][MAX][3];
bool livre[MAX][3];

inline int resp(int n)
{
  return (2*n+1) / 3;
}

void resolve()
{
  for(int n = 0; n < MAX; i++)
    for(int j = 0; j < 3; j++)
      livre[n][j] = true;

  for(int n = 1; n < MAX; n++){
    int r = resp(n);
    if(r = resp(n-1)){
      for(int i = 0; i < r; i++){
	pos[n][i][0] = pos[n-1][i][0] + 1;
	for(int j = 1; j < 3; j++)
	  pos[n][i][j] = pos[n-1][i][j];
      }

      continue;
    }

  }
}

void imprime(int h, int n)
{

  printf("%d %d %d", h, n, resp);
  for(int i = 0; i < resp; i++){
    if(i % 8 == 0) printf("\n");
    else printf(" ");
    printf("[%d,%d]", n-posicoes[n][i][0], posicoes[n][i][1]+1);
  }
  printf("\n\n");
}

int main()
{
  int n;
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    resolve(n);
    imprime(h, n);
  }
  return 0;
}
