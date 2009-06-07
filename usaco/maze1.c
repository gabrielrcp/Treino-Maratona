/*
ID: gabriel9
LANG: C
TASK: maze1
*/

#include <stdio.h>

#define MW 38
#define MH 100

char labirinto[2*MH+1][2*MW+1];
int dist[2*MH+1][2*MW+1];


int FILA[10000][2];
int ini, fim;

void insere(int x, int y)
{
  FILA[fim][0] = x;
  FILA[fim][1] = y;
  fim++;
}

void retira(int *x, int *y)
{
  *x = FILA[ini][0];
  *y = FILA[ini][1];
  ini++;
}

int vazia()
{
  return (ini == fim);
}


int main()
{
  int i, j;
  int infi;
  int max;


  FILE *fin = fopen("maze1.in", "r");
  FILE *fout = fopen("maze1.out", "w");

  int w, h;

  fscanf(fin, " %d %d", &w, &h);


  infi = 10000;

  for(i=0; i<2*h+1; i++){
    for(j=0; j<2*w+1; j++){
      do{
	labirinto[i][j] = getc(fin);
      }while(labirinto[i][j] == '\n');
      dist[i][j] = infi;
    }
  }

  ini = fim = 0;

  for(i=0; i<2*h+1; i++){
    if(labirinto[i][0] == ' '){
      dist[i][1] = 1;
      insere(i, 1);
    }
    if(labirinto[i][2*w] == ' '){
      dist[i][2*w-1] = 1;
      insere(i, 2*w-1);
    }
  }

  for(j=0; j<2*w+1; j++){
    if(labirinto[0][j] == ' '){
      dist[1][j] = 1;
      insere(1, j);
    }
    if(labirinto[2*h][j] == ' '){
      dist[2*h-1][j] = 1;
      insere(2*h-1, j);
    }
  }


  while(!vazia()){
    retira(&i, &j);

    if(i < 2*h-1 && labirinto[i+1][j] == ' ' && labirinto[i+2][j] == ' '
       && dist[i][j] + 1 < dist[i+2][j])
      {
	dist[i+2][j] = dist[i][j] + 1;
	insere(i+2, j);
      }

    if(i > 1  && labirinto[i-1][j] == ' ' && labirinto[i-2][j] == ' '
       && dist[i][j] + 1 < dist[i-2][j])
      {

	dist[i-2][j] = dist[i][j] + 1;
	insere(i-2, j);
      }

    if(j < 2*w-1 && labirinto[i][j+1] == ' ' && labirinto[i][j+2] == ' '
       && dist[i][j] + 1 < dist[i][j+2])
      {

	dist[i][j+2] = dist[i][j] + 1;
	insere(i, j+2);
      }

    if(j > 1  && labirinto[i][j-1] == ' ' && labirinto[i][j-2] == ' '
       && dist[i][j] + 1 < dist[i][j-2])
      {

	dist[i][j-2] = dist[i][j] + 1;
	insere(i, j-2);
      }
  }

  max = 0;
  for(i=0; i<2*h+1; i++){
    for(j=0; j<2*w+1; j++){
      if(dist[i][j] < infi && dist[i][j] > max)
	max = dist[i][j];
    }
  }


  fprintf(fout,"%d\n", max);


  return 0;
}
