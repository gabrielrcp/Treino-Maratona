#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buf[500];

int lernum()
{
  int r = 0;
  gets(buf);
  sscanf(buf, " %d", &r);
  return r;  
}

int n, m;
char mapa[55][55];
int comp[55][55];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

char sai[3000];

void fill(int i, int j, int h, int cp)
{
  if(i < 0 || i >= n) return;
  if(j < 0 || j >= m) return;
  if(comp[i][j] != -1) return;
  if(mapa[i][j] >= h) return;
  comp[i][j] = cp;
  for(int k = 0; k < 4; k++)
    fill(i+dx[k], j+dy[k], h, cp);  
}

int main()
{
  int casos = lernum();
  while(casos--){
    n = lernum();
    for(int i = 0; i < n; i++)
      gets(mapa[i]);
    m = strlen(mapa[0]);
    /*
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i++)
      printf("%s\n", mapa[i]);
    */
    int resp = 0;
    for(int h = 32; h <= 126; h++){

      memset(comp, -1, sizeof comp);
      for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	  fill(i, j, h, i*m+j);
      /*
      if(h == '2'){
	for(int i = 0; i < n; i++){
	  for(int j = 0; j < m; j++)
	    printf("%d ", comp[i][j]);
	  printf("\n");
	}
      }
      */

      memset(sai, 0, sizeof sai);
      for(int i = 0; i < n; i++){
	if(comp[i][0] != -1)
	  sai[comp[i][0]] = 1;
	if(comp[i][m-1] != -1)
	  sai[comp[i][m-1]] = 1;
      }
      for(int j = 0; j < m; j++){
	if(comp[0][j] != -1)
	  sai[comp[0][j]] = 1;
	if(comp[n-1][j] != -1)
	  sai[comp[n-1][j]] = 1;
      }
      
      for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	  if(comp[i][j] != -1 && sai[comp[i][j]] == 0)
	    resp = max(resp, h - mapa[i][j]);
	}
      }
    }
    printf("%d\n", resp);
  }
  return 0;
}
