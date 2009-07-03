#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 410

vector<int> G[MAX];
int n;
int comp[MAX];

bool possivel[110][110];


void dfs(int i, int cp)
{
  comp[i] = cp;
  for(int k = 0; k < G[i].size(); k++){
    int j = G[i][k];
    if(comp[j] == -1)
      dfs(j, cp);
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int m;
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < 2*n; i++){
      G[i].clear();
      comp[i] = -1;
    }
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      G[i].push_back(j+n);
      G[j+n].push_back(i);
    }

    /*
    int isola1 = 0, isola2 = 0;
    for(int i = 0; i < 2*n; i++)
      if(G[i].size() == 0){
	if(i < n)
	  isola1++;
	else
	  isola2++;
      }
    */

    vector< pair<int, int> > qtd;

    int cp = 0;
    for(int i = 0; i < 2*n; i++){
      if(comp[i] == -1){
	dfs(i, cp);
	int conta1 = 0, conta2 = 0;
	for(int j = 0; j < n; j++)
	  if(comp[j] == cp)
	    conta1++;
	for(int j = n; j < 2*n; j++)
	  if(comp[j] == cp)
	    conta2++;
	qtd.push_back( make_pair(conta1, conta2) );
	cp++;
      }
    }

    for(int i = 0; 2*i <= n; i++)
      for(int j = 0; 2*j <= n; j++)
	possivel[i][j] = false;

    possivel[0][0] = true;
    
    for(int k = 0; k < qtd.size(); k++){
      for(int i = n/2; i >= qtd[k].first; i--)
	for(int j = n/2; j >= qtd[k].second; j--){
	  if(possivel[i-qtd[k].first][j-qtd[k].second])
	    possivel[i][j] = true;
	}
    }

    int resp = 0;
    for(int i = 1; 2*i <= n; i++)
      if(possivel[i][i])
	resp = i;

    printf("%d\n", resp);
  }
  return 0;
}
