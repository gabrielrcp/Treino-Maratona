#include <cstdio>

using namespace std;

int matriz[100][100];

int FILA[10000];
int ini, fim;

int dist[100];


inline void inicializa()
{
  ini = fim = 0;
}

inline int vazia()
{
  return (ini == fim);
}


inline void insere(int v)
{
  FILA[fim] = v;
  fim++;
  if(fim == 10000)
    fim = 0;
}

inline int retira()
{
  int v = FILA[ini];
  ini++;
  if(ini == 10000)
    ini = 0;
  return v;
}

int main()
{

  int n, s;
  int i, j;
  int max;
  int h;

  for(h = 1; ; h++)
    {
      scanf(" %d %d", &n, &s);
      s--;
      if(n == 0)
	break;
      for(i=0; i<n; i++){
	dist[i] = 0;
	for(j=0; j<n; j++)
	  matriz[i][j] = 0;
      }

      while(1){
	scanf(" %d %d", &i, &j);
	if(i == 0 && j == 0)
	  break;
	i--; j--;
	matriz[i][j] = 1;
      }
      

      max = s;
      inicializa();
      insere(s);
      while(!vazia()){
	i = retira();
	for(j=0; j<n; j++)
	  if(matriz[i][j] && dist[i] + 1 > dist[j]){
	    dist[j] = dist[i] + 1;
	    insere(j);
	    if(dist[j] > dist[max])
	      max = j;
	    else if(dist[j] == dist[max] && j < max)
	      max = j;
	  }
      }
      printf("Case %d: The longest path from %d has"
	     " length %d, finishing at %d.\n\n",
	     h, s+1, dist[max], max+1);
    }
  return 0;
}
