/*
 * Problema: Pegs (3437)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3437
 * Login: 6414QA
 */

#include <stdio.h>
#include <string.h>

#define MAX 2097153 /* 2^21 + 1 */
#define INFI 30

char mat[5][5];
char tabs[MAX];

int calcula()
{
  int i, j, t=0;
  for(i=0; i<5; i++){
    for(j=0; j<5; j++){
      if(mat[i][j] == 'o')
	t++;
      if(mat[i][j] != '#')
	t = (t << 1);
    }
  }
  return (t >> 1);
}

int minpecas()
{
  int i, j;
  int at, min=INFI;
  int t;
    
  t = calcula();
  if(tabs[t] != INFI)
    return tabs[t];

  for(i=0; i<3; i++){
    for(j=0; j<5; j++){
      if(mat[i][j] == 'o' && mat[i+1][j] == 'o' && mat[i+2][j] == '.'){
	
	mat[i][j] = '.';
	mat[i+1][j] = '.';
	mat[i+2][j] = 'o';
	at = minpecas();
	if(at < min)
	  min = at;
	mat[i][j] = 'o';
	mat[i+1][j] = 'o';
	mat[i+2][j] = '.';
	if(min <= 1)
	  return min;
      }
    }
  }
  for(i=2; i<5; i++){
    for(j=0; j<5; j++){
      if(mat[i][j] == 'o' && mat[i-1][j] == 'o' && mat[i-2][j] == '.'){
	mat[i][j] = '.';
	mat[i-1][j] = '.';
	mat[i-2][j] = 'o';
	at = minpecas();
	if(at < min)
	  min = at;
	mat[i][j] = 'o';
	mat[i-1][j] = 'o';
	mat[i-2][j] = '.';
	if(min <= 1)
	  return min;
      }
    }
  }

  
  for(i=0; i<5; i++){
    for(j=0; j<3; j++){
      if(mat[i][j] == 'o' && mat[i][j+1] == 'o' && mat[i][j+2] == '.'){
	mat[i][j] = '.';
	mat[i][j+1] = '.';
	mat[i][j+2] = 'o';
	at = minpecas();
	if(at < min)
	  min = at;
	mat[i][j] = 'o';
	mat[i][j+1] = 'o';
	mat[i][j+2] = '.';
 	if(min <= 1)
	  return min;
      }
    }
  }

  for(i=0; i<5; i++){
    for(j=2; j<5; j++){
      if(mat[i][j] == 'o' && mat[i][j-1] == 'o' && mat[i][j-2] == '.'){
	mat[i][j] = '.';
	mat[i][j-1] = '.';
	mat[i][j-2] = 'o';
	at = minpecas();
	if(at < min)
	  min = at;
	mat[i][j] = 'o';
	mat[i][j-1] = 'o';
	mat[i][j-2] = '.';
	if(min <= 1)
	  return min;
      }
    }
  }
  
  if(min == INFI){
    min = 0;
    for(i=0; i<5; i++)
      for(j=0; j<5; j++)
	if(mat[i][j] == 'o')
	  min++;
  }
  
  tabs[t] = min;
  return min;
}

int main()
{
  int n, h;
  int i, j;
  scanf(" %d", &n);
  for(h=0; h<n; h++){
    memset(tabs, INFI, MAX*sizeof(char));
    for(i=0; i<5; i++){
      for(j=0; j<5; j++){
	do{
	  mat[i][j] = getchar();
	}while(mat[i][j] != 'o' && mat[i][j] != '.' && mat[i][j] != '#');
      }
    }
    /*
    for(i=0; i<5; i++){
      for(j=0; j<5; j++)
	printf("%c ", mat[i][j]);
      putchar('\n');
    }
    */
    
    printf("The best case ends with %d pegs.\n", minpecas());
  }
  return 0;
}
