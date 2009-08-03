#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define MAX 110

vector<int> area;
char matriz[MAX][MAX];
int numera[MAX][MAX];
int n, m;
vector< set<int> > buracos;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j, int cp)
{
  if(i < 0 || i >= n || j < 0 || j >= m)
    return;
  if(numera[i][j] != -1 || matriz[i][j] == '.')
    return;

  numera[i][j] = cp;
  area[cp]++;
  for(int k = 0; k < 4; k++)
    dfs(i+dx[k], j+dy[k], cp);
}

void buraco(int i, int j, int nb)
{
  if(i < 0 || i >= n || j < 0 || j >= m)
    return;
  if(numera[i][j] != -1 || matriz[i][j] == '*')
    return;

  numera[i][j] = nb;
  for(int k = 0; k < 4; k++)
    buraco(i+dx[k], j+dy[k], nb);  
}



void percorre(int i)
{
  int ultcp = ((matriz[i][0] == '*') ? numera[i][0] : -1);
  for(int j = 1; j < m; j++){
    if(matriz[i][j] == '*'){
      if(matriz[i][j-1] == '.' && ultcp == numera[i][j])
	buracos[ultcp].insert(numera[i][j-1]);
      ultcp = numera[i][j];
    }
  }
}

int main()
{
  scanf(" %d %d", &m, &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      scanf(" %c", &matriz[i][j]);
      numera[i][j] = -1;
    }

  int cp = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(matriz[i][j] == '*' && numera[i][j] == -1){
	area.push_back(0);
	buracos.push_back( set<int> () );
	dfs(i, j, cp++);
      }

  int nb = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(matriz[i][j] == '.' && numera[i][j] == -1){
	buraco(i, j, nb++);
      }


  for(int i = 0; i < n; i++)
    percorre(i);


  int resp = 0;
  int arearesp = 0;
  
  for(int i = 0; i < area.size(); i++){
    int t = buracos[i].size();
    if(t > resp){
      resp = t;
      arearesp = area[i];
    }
    else if(t == resp){
      if(arearesp > area[i])
	arearesp = area[i];
    }
  }

  printf("%d\n", arearesp);
  return 0;

}
