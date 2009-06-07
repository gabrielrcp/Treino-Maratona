/*
ID: gabriel9
LANG: C
TASK: cowtour
*/

#include <stdio.h>
#include <math.h>

#define MAX 150
#define EPS 1.0e-9

typedef struct {
  int x;
  int y;
} Ponto;


double distancia(Ponto p1, Ponto p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double max3(double x, double y, double z)
{
  if(x > y)
    return ((x > z) ? x : z);
  else
    return((y > z) ? y : z);
}


int main()
{
  int n;
  Ponto pontos[MAX];
  double dist[MAX][MAX];
  double  maxdist[MAX];
  int i, j, k;
  double infi = 100000*150;
  double diametro[MAX];
  int componente[MAX], numc;
  char c;

  double min, at;

  FILE *fin = fopen("cowtour.in", "r");
  FILE *fout = fopen("cowtour.out", "w");


  fscanf(fin, " %d", &n);

  for(i=0; i<n; i++)
    fscanf(fin, " %d %d", &(pontos[i].x), &(pontos[i].y));

  for(i=0; i<n; i++)
    for(j=0; j<n; j++){
      fscanf(fin, " %c", &c);
      if(c == '1')
	dist[i][j] = distancia(pontos[i], pontos[j]);
      else if(i == j)
	dist[i][j] = 0.0;
      else
	dist[i][j] = infi;
    }
  for(k=0; k<n; k++)
    for(i=0; i<n; i++)
      for(j=0; j<n; j++)
	if(dist[i][k] + dist[k][j] < dist[i][j])
	  dist[i][j] = dist[i][k] + dist[k][j];


  for(i=0; i<n; i++)
    componente[i] = 0;

  k = numc = 0;
  while(numc < n){
    for(i=0; componente[i] != 0; i++);
    componente[i] = ++k;
    numc++;
    for(j=i+1; j<n; j++)
      if(dist[i][j] < infi - EPS){
	componente[j] = k;
	numc++;
      }
  }
  numc = k;

  for(i=0; i<n; i++){
    maxdist[i] = 0;
    for(j=0; j<n; j++)
      if(componente[i] == componente[j] && dist[i][j] > maxdist[i])
	maxdist[i] = dist[i][j];
  }

  for(k=1; k <= numc; k++){
    diametro[k] = 0.0;
    for(i=0; i<n; i++)
      if(componente[i] == k && maxdist[i] > diametro[k])
	diametro[k] = maxdist[i];
  }

  min = infi;
  for(i=0; i<n; i++)
    for(j=i+1; j<n; j++)
      if(componente[i] != componente[j]){
	at = max3(maxdist[i] + maxdist[j] + distancia(pontos[i], pontos[j]),
		  diametro[componente[i]], diametro[componente[j]]);
	if(at < min)
	  min = at;
      }

  fprintf(fout, "%.6f\n", min);
  return 0;
}
