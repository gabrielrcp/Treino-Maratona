/*
ID: gabriel9
LANG: C
TASK: castle
*/

#include <stdio.h>

FILE *fin, *fout;

int castelo[50][50];
int comp[50][50];

int FILA[50*50][2];
int ini=0, fim=0;

int tamc[50*50];


int vazia()
{
  return (ini == fim);
}

void insere(int i, int j)
{
  FILA[fim][0] = i;
  FILA[fim][1] = j;
  fim++;
}

void retira(int *i, int *j)
{
  *i = FILA[ini][0];
  *j = FILA[ini][1];
  ini++;
}


int preenche(int i, int j, int k)
{
  int l, t;

  ini = fim = 0;
  insere(i,j);

  t = 0;
  comp[i][j] = k;
  while(!vazia()){
    retira(&i, &j);
    t++;

    /*fprintf(stderr, "Visitei %d %d\n", i, j);*/
    l = castelo[i][j];
    if(l % 2 == 0 && comp[i][j-1] == 0){
      comp[i][j-1] = k;
      insere(i, j-1);
    }
    l = l >> 1;
    if(l % 2 == 0 && comp[i-1][j] == 0){
      comp[i-1][j] = k;
      insere(i-1, j);
    }
    l = l >> 1;
    if(l % 2 == 0 && comp[i][j+1] == 0){
      comp[i][j+1] = k;
      insere(i, j+1);
    }
    l = l >> 1;
    if(l % 2 == 0 && comp[i+1][j] == 0){
      comp[i+1][j] = k;
      insere(i+1, j);
    }
  }
  return t;
}

int main()
{
  int i, j, k;
  int n, m;
  int numq, tamm;
  char dir;
  int lx, ly;
  
  fin = fopen("castle.in", "r");
  fout = fopen("castle.out", "w");
  /*  fin = stdin;*/
  /*fout = stdout;*/


  fscanf(fin, " %d %d", &m, &n);
  for(i=0; i<n; i++)
    for(j=0; j<m; j++){
      fscanf(fin, " %d", &castelo[i][j]);
      comp[i][j] = 0;
    }

  numq = 0;
  tamm = 0;
  for(i=0; i<n; i++)
    for(j=0; j<m; j++)
      if(comp[i][j] == 0){
	numq++;
	k = preenche(i, j, numq);
	tamc[numq-1] = k;
	if(k > tamm)
	  tamm = k;
	/*
	fprintf(stderr, "-->%d %d\n", numq, k);
	*/
      }
  /*
  for(i=0; i<n; i++){
    for(j=0; j<m; j++)
      fprintf(stderr, "%d ", comp[i][j]);
    fprintf(stderr, "\n");
  }
  */
  fprintf(fout, "%d\n%d\n", numq, tamm);

  tamm = 0;
  lx = ly = 0;
  dir = 'A';
  for(j=0; j < m; j++)
    for(i=n-1; i >= 0; i--){
      if(i > 0 &&
	 comp[i][j] != comp[i-1][j] &&
	 tamc[comp[i][j]-1] + tamc[comp[i-1][j]-1] > tamm)
	{
	  tamm = tamc[comp[i][j]-1] + tamc[comp[i-1][j]-1];
	  dir = 'N';
	  lx = i;
	  ly = j;
	}

     if(j < m-1 &&
	 comp[i][j] != comp[i][j+1] &&
	 tamc[comp[i][j]-1] + tamc[comp[i][j+1]-1] > tamm)
	{
	  tamm = tamc[comp[i][j]-1] + tamc[comp[i][j+1]-1];
	  dir = 'E';
	  lx = i;
	  ly = j;
	}
    }

  fprintf(fout, "%d\n%d %d %c\n", tamm, lx+1, ly+1, dir);

  return 0;
}
