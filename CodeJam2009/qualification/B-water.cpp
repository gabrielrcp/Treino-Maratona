#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 110

int comp[MAX][MAX];

vector<int> G[MAX][MAX];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;

int alt[MAX][MAX];
bool baixo[MAX][MAX];
char final[MAX][MAX];
char subs[30];

void vai(int i, int j, int cp)
{
  if(comp[i][j] != -1)
    return;
  comp[i][j] = cp;
  for(int k = 0; k < G[i][j].size(); k++){
    int d = G[i][j][k];
    vai(i-dx[d], j-dy[d], cp);
  }
}

void substitui(int cp, char c)
{
}

int main()
{

  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	scanf(" %d", &alt[i][j]);
	G[i][j].clear();
	comp[i][j] = -1;
	final[i][j] = 0;
      }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	int d = -1;
	for(int k = 0; k < 4; k++){
	  int x = i + dx[k];
	  int y = j + dy[k];
	  if(x < 0 || x >= n || y < 0 || y >= m)
	    continue;
	  if(alt[x][y] >= alt[i][j])
	    continue;
	  if(d == -1 || alt[i+dx[d]][j+dy[d]] > alt[x][y])
	    d = k;
	}
	if(d != -1)
	  G[i+dx[d]][j+dy[d]].push_back(d);
	baixo[i][j] = (d == -1);
      }

    int ncp = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	if(baixo[i][j]){
	  subs[ncp] = 0;
	  vai(i, j, ncp++);
	}

    char at = 'a';
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	if(subs[comp[i][j]] == 0)
	  subs[comp[i][j]] = at++;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	final[i][j] = subs[comp[i][j]];


    printf("Case #%d:\n", h);
    for(int i = 0; i < n; i++){
      printf("%c", final[i][0]);
      for(int j = 1; j < m; j++)
	printf(" %c", final[i][j]);
      printf("\n");
    }
	  

  }
  return 0;
}
