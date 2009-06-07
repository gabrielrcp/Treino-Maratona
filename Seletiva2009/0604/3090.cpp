#include <cstdio>


#define MAX 1010

bool vis[MAX][MAX];
int resp[MAX];


void resolve()
{
  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      vis[i][j] = true;

  vis[0][0] = false;
  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++){
      if(!vis[i][j]) continue;
      for(int k = 2; k*i < MAX && k*j < MAX; k++)
	vis[i*k][j*k] = false;
    }

  resp[0] = 0;
  for(int n = 1; n < MAX; n++){
    resp[n] = resp[n-1];
    for(int i = 0; i < n; i++)
      if(vis[i][n]) resp[n]++;
    for(int j = 0; j <= n; j++)
      if(vis[n][j]) resp[n]++;
  }
}


int main()
{
  int casos;
  scanf(" %d", &casos);

  resolve();

  for(int h = 1; h <= casos; h++){
    int n;
    scanf(" %d", &n);
    printf("%d %d %d\n", h, n, resp[n]);
  }
  return 0;
}
