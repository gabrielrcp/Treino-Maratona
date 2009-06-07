/*
ID: gabriel9
LANG: C
TASK: transform
*/

#include <stdio.h>

int n;
char antes[10][10], depois[10][10], novo[10][10];

int compara()
{
  int i, j;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      if(depois[i][j] != novo[i][j])
	return 0;
  return 1;
}

int main()
{
  
  FILE *fin = fopen("transform.in", "r");
  FILE *fout = fopen("transform.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */
  int i, j;
  char bak[10][10];
 
  fscanf(fin, " %d", &n);

  for(i=0; i<n; i++)
    fscanf(fin, " %s", antes[i]);
  for(i=0; i<n; i++)
    fscanf(fin, " %s", depois[i]);
 
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[j][n-1-i] = antes[i][j];
    }
  }
  if(compara() == 1){
    fprintf(fout, "1\n");
    return 0;
  }
  

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[n-1-i][n-1-j] = antes[i][j];
    }
  }
  if(compara() == 1){
    fprintf(fout, "2\n");
    return 0;
  }
  
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[n-1-j][i] = antes[i][j];
    }
  }
  
  if(compara() == 1){
    fprintf(fout, "3\n");
    return 0;
  }
  
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[i][n-1-j] = antes[i][j];
      bak[i][n-1-j] = antes[i][j];
    }
  }

  if(compara() == 1){
    fprintf(fout, "4\n");
    return 0;
  }

  /**********/
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[j][n-1-i] = bak[i][j];
    }
  }
  
  if(compara() == 1){
    fprintf(fout, "5\n");
    return 0;
  }
  

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[n-1-i][n-1-j] = bak[i][j];
    }
  }
  
  if(compara() == 1){
    fprintf(fout, "5\n");
    return 0;
  }
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[n-1-j][i] = bak[i][j];
    }
  }
  if(compara() == 1){
    fprintf(fout, "5\n");
    return 0;
  }

  /**************************/
 
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      novo[i][j] = antes[i][j];
    }
  }
  if(compara() == 1){
    fprintf(fout, "6\n");
    return 0;
  }
  
  fprintf(fout, "7\n");
  /*
  for(i=0; i<n; i++){
    for(j=0; j<n; j++)
      fprintf(fout, "%c", novo[i][j]);
    putchar('\n');
  }
  */
  return 0;
}
