/*
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3439
 * User: 6414QA
 */

#include <stdio.h>

#define MAXCMB 11628

int chamados[5];
char padroes[19][5][5];
char vencs[MAXCMB][5][5];
int usar[5];
int x, y;
int ncmb;


int minimo(int p)
{
  int i,j;
  int ct, cc;
  ct = 0;
  for(j=0; j<5; j++){
    cc = 0;
    for(i=0; i<5; i++){
      if(vencs[p][i][j] == 'X')
	cc++;
    }
    if(j == 2 && vencs[p][2][2] == 'X')
      cc--;
    if(cc > chamados[j])
      ct += cc - chamados[j];
  }
  return ct;
}

void combina()
{
  int i, j, k;

  for(i=0; i<5; i++)
    for(j=0; j<5; j++)
      vencs[ncmb][i][j] = padroes[usar[0]][i][j];

  for(k=1; k<y; k++){
    for(i=0; i<5; i++){
      for(j=0; j<5; j++){
	if(vencs[ncmb][i][j] == 'X' || padroes[usar[k]][i][j] == 'X')
	  vencs[ncmb][i][j] = 'X';
	else
	  vencs[ncmb][i][j] = 'O';
      }
    }
  }
  ncmb++;
  return;
}

void geracombi(int n, int ini, int k)
{
  int i;
  if(n == 0){
    combina();
    return;
  }
  
  for(i=ini; i <= x - n; i++){
    usar[k] = i;
    geracombi(n-1, i+1, k+1);
  }
}


int main()
{
  int n;
  int i, j, k;
  int min;
  scanf(" %d", &n);
  while(n > 0){
    for(i=0; i<5; i++)
      scanf(" %d", &chamados[i]);
    scanf(" %d %d", &x, &y);
    for(i=0; i< 5; i++){
      for(k=0; k<x; k++){
	for(j=0; j<5; j++){
	  do{
	    padroes[k][i][j] = getchar();
	  }while(padroes[k][i][j] != 'O' && padroes[k][i][j] != 'X');
	}
      }
    }
    ncmb = 0;
    geracombi(y, 0, 0);
    /*printf("%d %d\n", x, y);*/
    /*printf("%d\n", ncmb);*/
    /*
    for(k=0; k<ncmb; k++){
      for(i=0; i<5; i++){
	for(j=0; j<5; j++)
	  printf("%c ", vencs[k][i][j]);
	putchar('\n');
      }
      putchar('\n');
    }
    putchar('\n');
    */
    min = minimo(0);
    for(i=1; i<ncmb; i++){
      k = minimo(i);
      if(k < min)
	min = k;
    }
    printf("%d\n", min);
    n--;
  }
  return 0;
}
