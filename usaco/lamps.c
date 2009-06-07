/*
ID: gabriel9
LANG: C
TASK: lamps
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, c;
int ligado[100];
int estfim[100];
/*char sol[50][100];*/
char **sol;
int numsol;
int numapertos;


int ehsol()
{
  int i;
  for(i=0; i<n; i++)
    if(ligado[i] != estfim[i] && estfim[i] != -1)
      return 0;
  if(numapertos > c || (c - numapertos) % 2 == 1)
    return 0;
  return 1;
}

void insere()
{
  int i;
  for(i=0; i<n; i++)
    sol[numsol][i] = (char)ligado[i]+'0';
  sol[numsol][n] = '\0';
  numsol++;  
}

void gera(int ini)
{
  int i;

  if(ini < 4)
    gera(ini+1);
  else{
    if(ehsol())
      insere();
    return;
  }
  switch(ini)
    {
    case 0:
      for(i=0; i<n; i++)
	ligado[i] = 1 - ligado[i];
      numapertos++;
      gera(ini+1);
      numapertos--;
      for(i=0; i<n; i++)
	ligado[i] = 1 - ligado[i];
      break;

    case 1:
      for(i=0; i<n; i+=2)
	ligado[i] = 1 - ligado[i];
      numapertos++;
      gera(ini+1);
      numapertos--;
      for(i=0; i<n; i+=2)
	ligado[i] = 1 - ligado[i];
      break;

    case 2:
      for(i=1; i<n; i+=2)
	ligado[i] = 1 - ligado[i];
      numapertos++;
      gera(ini+1);
      numapertos--;
      for(i=1; i<n; i+=2)
	ligado[i] = 1 - ligado[i];
      break;

    case 3:
      for(i=0; i<n; i+=3)
	ligado[i] = 1 - ligado[i];
      numapertos++;
      gera(ini+1);
      numapertos--;
      for(i=0; i<n; i+=2)
	ligado[i] = 1 - ligado[i];
      break;
    default:
      return;
    }
}

int compara(const void *a, const void *b)
{
  return strcmp(*(char **)a, *(char **)b);
}

int main()
{
  int i, j;
  
  FILE *fin = fopen("lamps.in", "r");
  FILE *fout = fopen("lamps.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d %d", &n, &c);

  for(i=0; i<n; i++){
    ligado[i] = 1;
    estfim[i] = -1;
  }

  while(1){
    fscanf(fin, " %d", &j);
    if(j == -1)
      break;
    estfim[--j] = 1;
  }
  while(1){
    fscanf(fin, " %d", &j);
    if(j == -1)
      break;
    estfim[--j] = 0;
  }

  sol = malloc(50*sizeof(char *));
  for(i=0; i<50; i++)
    sol[i] = malloc((n+1)*sizeof(char));

  numsol = 0;
  numapertos = 0;
  gera(0);


  if(numsol == 0){
    fprintf(fout, "IMPOSSIBLE\n");
    return 0;
  }
  
  qsort(sol, numsol, sizeof(char *), compara);
  
  /*ordena();*/
  fprintf(fout, "%s\n", sol[0]);
  for(i=1; i<numsol; i++)
    if(strcmp(sol[i], sol[i-1]) != 0)
      fprintf(fout, "%s\n", sol[i]);

  return 0;
}
