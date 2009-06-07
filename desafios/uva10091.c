/* UVA 10091 - Valentines Day
   Accepted */

#include <stdio.h>
#include <string.h>


char mat[50][50];

int ncid;
char nomes[100][50];
int noviz[50];

double prob1[50], prob2[50];
double temp[50];

int acha(char *s)
{
  int i;
  for(i = 0; i < ncid; i++)
    if(strcmp(nomes[i], s) == 0)
      break;
  return i;
}

int main()
{
  int casos;
  int y, m, d, r;
  char buf[100];
  int i, j, k;
  double saida;

  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %d %d", &y, &m, &d, &r);
    ncid = 0;

    for(i = 0; i < 50; i++){
      for(j = 0; j < 50; j++)
	mat[i][j] = 0;
      mat[i][i] = 1;
      noviz[i] = 1;
    }

    while(r--){
      scanf(" %s", buf);
      i = acha(buf);
      if(i == ncid){
	strcpy(nomes[i], buf);
	ncid++;
      }
      scanf(" %s", buf);
      j = acha(buf);
      if(j == ncid){
	strcpy(nomes[j], buf);
	ncid++;
      }
      if(mat[i][j] == 0)
	noviz[i]++;
      if(mat[j][i] == 0)
	noviz[j]++;
      mat[i][j] = mat[j][i] = 1;
    }

    scanf(" %s", buf);
    i = acha(buf);
    if(i == ncid){
      strcpy(nomes[i], buf);
      ncid++;
    }
    
    scanf(" %s", buf);
    j = acha(buf);
    if(j == ncid){
      strcpy(nomes[j], buf);
      ncid++;
    }

    for(k = 0; k < ncid; k++)
      prob1[k] = prob2[k] = 0.0;

    prob1[i] = 1.0;
    prob2[j] = 1.0;


    while(42){
      if(y >= 470 && m == 2 && d < 14){
	saida = 0.0;
	for(i = 0; i < ncid; i++)
	  saida += prob1[i] * prob2[i];
	printf("%.5f\n", saida);
	break;
      }

      for(i = 0; i < ncid; i++){
	temp[i] = 0.0;
	for(j = 0; j < ncid; j++)
	  if(mat[i][j])
	    temp[i] += prob1[j] / ((double)noviz[j]);
      }
      for(i = 0; i < ncid; i++)
	prob1[i] = temp[i];

      for(i = 0; i < ncid; i++){
	temp[i] = 0.0;
	for(j = 0; j < ncid; j++)
	  if(mat[i][j])
	    temp[i] += prob2[j] / ((double)noviz[j]);
      }
      for(i = 0; i < ncid; i++)
	prob2[i] = temp[i];
      
      d = 1; m++;
      if(m == 13){
	m = 1;
	y++;
      }
    }

  }
  return 0;
}
