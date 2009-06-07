/*
ID: gabriel9
LANG: C
TASK: concom
*/

#include <stdio.h>


char controla[100][100];
int quanto[100][100];
char somei[100][100];
int orig[100][100];


int main()
{
  int i, j, p;
  int n, k;
  int numc;
  char denovo;
  
  FILE *fin = fopen("concom.in", "r");
  FILE *fout = fopen("concom.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  fscanf(fin, " %d", &n);

  numc = 0;
  for(k=0; k<n; k++){
    fscanf(fin, " %d %d %d", &i, &j, &p);
    if(i > numc)
      numc = i;
    if(j > numc)
      numc = j;
    orig[--i][--j] += p;
    quanto[i][j] += p;
  }
  
  for(i=0; i<numc; i++){
      controla[i][i] = 1;
      somei[i][i] = 1;
  }

  denovo = 1;
  while(1){
    denovo = 0;
    for(i=0; i<numc; i++)
      for(j=0; j<numc; j++)
	if(quanto[i][j] > 50 && controla[i][j] == 0){
	  controla[i][j] = 1;
	  denovo = 1;
	}

    if(!denovo)
      break;
    
    for(i=0; i<numc; i++)
      for(j=0; j<numc; j++)
	if(controla[i][j] == 1 && somei[i][j] == 0){
	  for(k=0; k<numc; k++)
	    quanto[i][k] += orig[j][k];
	  somei[i][j] = 1;
	}

  }

  for(i=0; i<numc; i++)
    for(j=0; j<numc; j++)
      if(controla[i][j] && i != j)
	fprintf(fout, "%d %d\n", i+1, j+1);
  
  return 0;
}
