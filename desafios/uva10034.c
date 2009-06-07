/* UVA 10034 - Freckles
   Accepted */

#include <stdio.h>
#include <math.h>


double dist[100][100];
double px[100];
double py[100];
double d[100];
char vis[100];
int n;

int minimo()
{
  int r, i;
  r = 0;
  while(r < n){
    if(!vis[r])
      break;
    r++;
  }
  for(i = r + 1; i < n; i++)
    if(!vis[i] && d[i] < d[r])
      r = i;
  return r;
}

int main()
{
  int casos;
  int i, j;
  double total;

  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(i = 0; i < n; i++)
      scanf(" %lf %lf", px+i, py+i);
    for(i = 0; i < n; i++){
      dist[i][i] = 0.0;
      for(j = i + 1; j < n; j++){
	dist[i][j] = (px[i] - px[j]) * (px[i] - px[j]) + 
	             (py[i] - py[j]) * (py[i] - py[j]);
	dist[i][j] = sqrt(dist[i][j]);      
	dist[j][i] = dist[i][j];
      }
    }
    total = 0;
    d[0] = 0.0;
    vis[0] = 1;
    for(i=1; i<100; i++){
      d[i] = dist[0][i];
      vis[i] = 0;
    }
    while(1){
      i = minimo();
      if(i == n)
	break;
      vis[i] = 1;
      total += d[i];
      for(j = 1; j < n; j++){
	if(d[j] > dist[i][j])
	  d[j] = dist[i][j];
      }
    }
    printf("%.2f\n", total);
    if(casos)
      putchar('\n');
  }
  return 0;  
}
