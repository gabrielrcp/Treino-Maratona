/*
ID: gabriel9
LANG: C
TASK: clocks
*/

#include <stdio.h>

FILE *fin, *fout;

int rel[3][3];

void resta(int *num)
{
  while(*num >= 4)
    *num = *num - 4;
  while(*num < 0)
    *num = *num + 4;
}

void gira(int num, int l)
{
  int i, j;
  switch(num)
    {
    case 1:
      for(i=0; i<2; i++)
	for(j=0; j<2; j++){
	  rel[i][j] += l;
	  resta(&rel[i][j]);
	}
      break;
    case 2:
      i = 0;
      for(j=0; j<3; j++){
	rel[i][j] += l;
	resta(&rel[i][j]);
      }
      break;
    case 3:
      for(i=0; i<2; i++)
	for(j=1; j<3; j++){
	  rel[i][j] += l;
	  resta(&rel[i][j]);
	}
      break;
    case 4:
      j = 0;
      for(i=0; i<3; i++){
	  rel[i][j] += l;
	  resta(&rel[i][j]);
	}
      break;
    case 5:
      rel[0][1] += l;
      resta(&rel[0][1]);
      i = 1;
      for(j=0; j<3; j++){
	rel[i][j] += l;
	resta(&rel[i][j]);
      }
      rel[2][1] += l;
      resta(&rel[2][1]);
      break;
    case 6:
      j = 2;
      for(i=0; i<3; i++){
	rel[i][j] += l;
	resta(&rel[i][j]);
      }
      break;
    case 7:
      for(i=1; i<3; i++)
	for(j=0; j<2; j++){
	  rel[i][j] += l;
	  resta(&rel[i][j]);
	}
      break;
    case 8:
      i = 2;
      for(j=0; j<3; j++){
	rel[i][j] += l;
	resta(&rel[i][j]);
      }
      break;
    case 9:
      for(i=1; i<3; i++)
	for(j=1; j<3; j++){
	  rel[i][j] += l;
	  resta(&rel[i][j]);
	}
      break;
    default:
      break;
    }
}

int verifica()
{
  int i, j;
  for(i=0; i<3; i++)
    for(j=0; j<3; j++)
      if(rel[i][j] != 0)
	return 0;
  return 1;
}

int usados[30];
int nusos[10];
int ordem;

int imprime(int pri, int k)
{
  int i;

  if(k == ordem){
    if(verifica()){
      for(i=0; i<ordem-1; i++)
	fprintf(fout, "%d ", usados[i]);
      fprintf(fout, "%d\n", usados[ordem-1]);
      return 1;
    }
    return 0;
  }

  for(i=pri; i<=9; i++){
    if(nusos[i] == 3)
      continue;
    usados[k] = i;
    nusos[i]++;
    gira(i, 1);
    if(imprime(i, k+1))
      return 1;
    gira(i, -1);
    nusos[i]--;
  }
  return 0;
}

int main()
{
  int i,j;
  fin  = fopen("clocks.in", "r");
  fout = fopen("clocks.out", "w");

  /*fin = stdin;*/
  /*fout = stdout;*/

  for(i=0; i<3; i++)
    for(j=0; j<3; j++){
      fscanf(fin, " %d", &rel[i][j]);
      rel[i][j] /= 3;
      resta(&rel[i][j]);
    }

  for(i=1; i<=9; i++)
    nusos[i] = 0;

  ordem = 1;
  while(!imprime(1, 0))
    ordem++;
  return 0;
}
