/* UVA 10075 - Airlines
   Accepted */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI  3.141592653589793
#define RAIO 6378
#define MAXCID 110
#define INFI 536870912
/*2147483647*/

int n;
int dist[MAXCID][MAXCID];

typedef struct {
  char nome[30];
  double lat;
  double lon;
}Cidade;

Cidade cidade[MAXCID];

int calcdist(int i, int j)
{ 
  double d;
  double a1 = cidade[i].lat;
  double a2 = cidade[j].lat;
  double b1 = cidade[i].lon;
  double b2 = cidade[j].lon;

  d = acos(cos(a1)*cos(a2)*cos(b1)*cos(b2)
	   + cos(a1)*cos(a2)*sin(b1)*sin(b2)
	   + sin(a1)*sin(a2)) * RAIO;
  return floor(d + 0.5);
} 

int acha(char *s)
{
  int i;
  for(i = 0; i < n; i++)
    if(strcmp(s, cidade[i].nome) == 0)
      break;
  return i;
}

int main()
{
  int h = 1;
  int m, q;
  int i, j, k;
  char buf[30];

  while(scanf(" %d %d %d", &n, &m, &q) && (n || m || q)){
    for(i = 0; i < n; i++){
      scanf(" %s %lf %lf", cidade[i].nome, &cidade[i].lat, &cidade[i].lon);
      cidade[i].lat *= PI / 180.0;
      cidade[i].lon *= PI / 180.0;
      for(j = 0; j < n; j++)
	dist[i][j] = INFI;
      dist[i][i] = 0;
    }
    while(m--){
      scanf(" %s", buf);
      i = acha(buf);
      scanf(" %s", buf);
      j = acha(buf);
      if(i != n && j != n)
	dist[i][j] = calcdist(i, j);
    }
    for(k = 0; k < n; k++)
      for(i = 0; i < n; i++)
	for(j = 0; j < n; j++)
	  if(dist[i][j] > dist[i][k] + dist[k][j])
	    dist[i][j] = dist[i][k] + dist[k][j];
    if(h > 1)
      putchar('\n');
    printf("Case #%d\n", h);
    h++;
    while(q--){
      scanf(" %s", buf);
      i = acha(buf);
      scanf(" %s", buf);
      j = acha(buf);
      if(i != n && j != n && dist[i][j] < INFI)
	printf("%d km\n", dist[i][j]);
      else
	printf("no route exists\n");
    }
  }
  return 0;
}
