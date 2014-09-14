/*
 * Primeira fase da maratona 2014
 * Problema: letras
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4662
 * Resposta: AC
 */

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
char mat[110][110];
int dist[110][110];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool ok(int i, int j, int mask)
{
  if('a' <= mat[i][j] && mat[i][j] <= 'j'){
    int p = (int)mat[i][j] - 'a';
    return ((1<<p) & mask);
  }
  int p = (int)mat[i][j] - 'A';
  return (!((1<<p) & mask));
}

int go(int mask)
{
  if(!ok(0, 0, mask))
    return N*N+1;
  if(!ok(N-1, N-1, mask))
    return N*N+1;

  memset(dist, -1, sizeof dist);
  dist[0][0] = 1;
  queue< pair<int, int> > Q;
  Q.push(make_pair(0, 0));
  while(!Q.empty()){
    int i = Q.front().first;
    int j = Q.front().second;
    Q.pop();
    for(int k = 0; k < 4; k++){
      int x = i + dx[k];
      int y = j + dy[k];
      if(x < 0 || x >= N) continue;
      if(y < 0 || y >= N) continue;
      if(!ok(x, y, mask)) continue;
      if(dist[x][y] != -1) continue;
      dist[x][y] = dist[i][j] + 1;
      Q.push(make_pair(x, y));
      if(x == N-1 && y == N-1)
	return dist[x][y];
    }
  }
  return N*N+1;
}


int main()
{
  while(scanf(" %d", &N) == 1){
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	scanf(" %c", &mat[i][j]);
    int r = N*N+1;
    for(int m = 0; m < 1024; m++){
      r = min(r, go(m));
    }
    if(r > N*N)
      printf("-1\n");
    else
      printf("%d\n", r);
  }
  return 0;
}
