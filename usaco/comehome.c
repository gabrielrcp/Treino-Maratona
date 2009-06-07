/*
ID: gabriel9
LANG: C
TASK: comehome
*/

#include <stdio.h>

#define  MAX 2*('Z' - 'A' + 1)

int pesos[MAX][MAX];
char visitados[MAX];
int dist[MAX];


int main()
{
  int e;
  int k, i, j, peso;
  char o, d;
  int infi = MAX*1000;
  int min;

  FILE *fin = fopen("comehome.in", "r");
  FILE *fout = fopen("comehome.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */

  for(i=0; i<MAX; i++){
    for(j=0; j<MAX; j++)
      pesos[i][j] = infi;
    visitados[i] = 0;
    dist[i] = infi;
  }
    

  fscanf(fin, " %d", &e);
  for(k=0; k<e; k++){
    fscanf(fin, " %c %c %d", &o, &d, &peso);
    if(o >= 'A' && o <= 'Z')
      i = (int)'Z' - o;
    else
      i = o - 'a' + 'Z' - 'A' + 1;

    if(d >= 'A' && d <= 'Z')
      j = (int)'Z' - d;
    else
      j = d - 'a' + 'Z' - 'A' + 1;

    if(pesos[i][j] > peso)
      pesos[i][j] = pesos[j][i] = peso;
  }

  
  dist[0] = 0;
  while(42){

    for(min=0; min<MAX; min++)
      if(visitados[min] == 0)
	break;

    for(i=min; i<MAX; i++)
      if(visitados[i] == 0 && dist[i] < dist[min])
	min = i;

    if(min > 0 && min <= 'Z' - 'A'){
      fprintf(fout, "%c %d\n", 'Z' - min, dist[min]);
      return 0;
    }

    visitados[min] = 1;

    for(i=0; i<MAX; i++)
      if(pesos[min][i] + dist[min] < dist[i])
	dist[i] = pesos[min][i] + dist[min];
  }

  /*
  dist[0] = infi;
  d = 'Z';
  for(o = 'A'; o < 'Z'; o++)
    if(dist[(int)'Z' - o] < dist[(int)'Z' - d])
      d = o;

  fprintf(fout, "%c %d\n", d, dist[(int)'Z' - d]);
  */
  /*
  for(o = 'A'; o <= 'Z'; o++)
    fprintf(stderr, "%c %d\n", o, dist[(int)'Z' - o]);
   for(o = 'a'; o <= 'z'; o++)
    fprintf(stderr, "%c %d\n", o, dist[(int)o - 'a' + 'Z' - 'A' + 1]); 
  */
  return 1;
}
