/*
ID: gabriel9
LANG: C
TASK: camelot
*/

#include <stdio.h>

#define MAX 1041 /* 26*40+1 */


typedef struct{
  int r;
  int c;
}Posicao;

int r, c;
int n;

Posicao cavalo[MAX];
Posicao rei;

Posicao FILA[MAX];
int ini, fim;

int dist[40][26][40][26];


int main()
{
  int i, j, k, l;
  int m;
  int infi = MAX*MAX;
  char t;
  int at;
  int min, soma;
  int dr, dc;
  int minl;
  FILE *fin = fopen("camelot.in", "r");
  FILE *fout = fopen("camelot.out", "w");
  
  fscanf(fin, " %d %d", &r, &c);

  fscanf(fin, " %c %d", &t, &k);
  rei.r = k - 1;
  rei.c = (int)t - 'A';

  n = 0;
  while(fscanf(fin, " %c %d", &t, &k) > 0){
    cavalo[n].r = k - 1;
    cavalo[n].c = (int)t - 'A';
    n++;
  }

  if(n == 0){
    fprintf(fout, "0\n");
    return 0;
  }

  for(i=0; i<r; i++)
    for(j=0; j<c; j++)
      for(k=0; k<r; k++)
	for(l=0; l<c; l++)
	  dist[i][j][k][l] = infi;


  for(i=0; i<r; i++)
    for(j=0; j<c; j++)
      {
	dist[i][j][i][j] = 0;
	FILA[0].r = i;
	FILA[0].c = j;
	ini = 0; fim = 1;
	while(ini < fim)
	  {
	    k = FILA[ini].r;
	    l = FILA[ini].c;
	    at = dist[i][j][k][l];
	    at++;
	    ini++;

	    if(k > 0 && l > 1 && dist[i][j][k-1][l-2] > at){
	      dist[i][j][k-1][l-2] = at;
	      FILA[fim].r = k-1;
	      FILA[fim].c = l-2;
	      fim++;
	    }

	    if(k > 1 && l > 0 && dist[i][j][k-2][l-1] > at){
	      dist[i][j][k-2][l-1] = at;
	      FILA[fim].r = k-2;
	      FILA[fim].c = l-1;
	      fim++;
	    }

	    if(k > 0 && l < c - 2 && dist[i][j][k-1][l+2] > at){
	      dist[i][j][k-1][l+2] = at;
	      FILA[fim].r = k-1;
	      FILA[fim].c = l+2;
	      fim++;
	    }

	    if(k > 1 && l < c - 1 && dist[i][j][k-2][l+1] > at){
	      dist[i][j][k-2][l+1] = at;
	      FILA[fim].r = k-2;
	      FILA[fim].c = l+1;
	      fim++;
	    }


	    if(k < r - 1 && l > 1 && dist[i][j][k+1][l-2] > at){
	      dist[i][j][k+1][l-2] = at;
	      FILA[fim].r = k+1;
	      FILA[fim].c = l-2;
	      fim++;
	    }

	    if(k < r - 2 && l > 0 && dist[i][j][k+2][l-1] > at){
	      dist[i][j][k+2][l-1] = at;
	      FILA[fim].r = k+2;
	      FILA[fim].c = l-1;
	      fim++;
	    }

	    if(k < r - 1 && l < c - 2 && dist[i][j][k+1][l+2] > at){
	      dist[i][j][k+1][l+2] = at;
	      FILA[fim].r = k+1;
	      FILA[fim].c = l+2;
	      fim++;
	    }

	    if(k < r - 2 && l < c - 1 && dist[i][j][k+2][l+1] > at){
	      dist[i][j][k+2][l+1] = at;
	      FILA[fim].r = k+2;
	      FILA[fim].c = l+1;
	      fim++;
	    }
	  }
      }


  min = infi;

  if(r >= 5 && c >= 5)
    goto etiqueta;

  for(i=0; i<r; i++)
    for(j=0; j<c; j++){
      for(k=0; k<r; k++)
	for(l=0; l<c; l++){
	  minl = dist[cavalo[0].r][cavalo[0].c][k][l] 
	       - dist[cavalo[0].r][cavalo[0].c][i][j];
	  for(m=1; m<n; m++){
	    at = dist[cavalo[m].r][cavalo[m].c][k][l] 
	       - dist[cavalo[m].r][cavalo[m].c][i][j];
	    if(at < minl)
	      minl = at;
	  }

	  dr = (rei.r > k ? rei.r - k : k - rei.r);
	  dc = (rei.c > l ? rei.c - l : l - rei.c);
	  soma = (dr < dc ? dr : dc);
	  dr -= soma;
	  dc -= soma;
	  soma += dr;
	  soma += dc;
	  soma += dist[i][j][k][l];
	  soma += minl;
	  for(m=0; m<n; m++)
	    soma += dist[cavalo[m].r][cavalo[m].c][i][j];
	  
	  if(soma < min)
	    min = soma;
	}
      }

  fprintf(fout, "%d\n", min);
  return 0;

 etiqueta:


  for(i=0; i<r; i++)
    for(j=0; j<c; j++){
      /*      
      for(k=0; k<r; k++)
	for(l=0; l<c; l++){
      */

      for(k=rei.r-2; k<=rei.r+2; k++)
	for(l=rei.c-2; l<=rei.c+2; l++){
	  if(k < 0 || k >= r || l < 0 || l >= c)
	    continue;

	  minl = dist[cavalo[0].r][cavalo[0].c][k][l] 
	       - dist[cavalo[0].r][cavalo[0].c][i][j];
	  for(m=1; m<n; m++){
	    at = dist[cavalo[m].r][cavalo[m].c][k][l] 
	       - dist[cavalo[m].r][cavalo[m].c][i][j];
	    if(at < minl)
	      minl = at;
	  }

	  dr = (rei.r > k ? rei.r - k : k - rei.r);
	  dc = (rei.c > l ? rei.c - l : l - rei.c);
	  soma = (dr < dc ? dr : dc);
	  dr -= soma;
	  dc -= soma;
	  soma += dr;
	  soma += dc;
	  soma += dist[i][j][k][l];
	  soma += minl;
	  for(m=0; m<n; m++)
	    soma += dist[cavalo[m].r][cavalo[m].c][i][j];
	  
	  if(soma < min)
	    min = soma;
	}
      }


  fprintf(fout, "%d\n", min);

  /*
  for(i=0; i<r; i++){
    for(j=0; j < c; j++)
      printf("%2d ", dist[0][0][i][j]);
    printf("\n");
  }
  */
  return 0;
}
