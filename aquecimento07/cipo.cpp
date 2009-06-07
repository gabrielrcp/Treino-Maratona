// https://br.spoj.pl/problems/CIPO/
// TLE

#include <cstdio>

#define INFI 999999

int mat[1001][1001];
char foi[1001];
int dist[1001];
int n;


int minimo()
{
  int ret = 1;
  while(foi[ret] == 1)
    ret++;
  for(int i = ret + 1; i < n; i++)
    if(foi[i] == 0 && dist[i] < dist[ret])
      ret = i;
  return ret;
}

int main()
{
  int m;
  int resp;
  int h = 1;
  while(!feof(stdin) && scanf(" %d %d", &n, &m) > 0){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
	mat[i][j] = INFI;
      foi[i] = 0;
    }
    for(int k = 0; k < m; k++){
      int i, j, c;
      scanf(" %d %d %d", &i, &j, &c);
      i--; j--;
      if(mat[i][j] > c)
	mat[i][j] = mat[j][i] = c;
    }

    foi[0] = 1;
    for(int i = 1; i < n; i++)
      dist[i] = mat[0][i];
    resp = 0;
    for(int k = 2; k < n; k++){
      int i = minimo();
      printf("%d\n", i);
      foi[i] = 1;
      resp += dist[i];
      for(int j = 1; j < n; j++)
	if(mat[i][j] < dist[j])
	  dist[j] = mat[i][j];
    }
    printf("Instancia %d\n%d\n\n", h++, resp + dist[minimo()]);
  }
  return 0;
}
