#define MAX 50010

vector<int> G[MAX];
int n;

int lbl[MAX], low[MAX];
int tempo;

void dfs(int i, int p)
{
  lbl[i] = tempo++;
  low[i] = lbl[i];

  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k];
    if(j == p) continue;
    if(lbl[j] == -1){
      dfs(j, i);
      if(low[j] >= lbl[j]){
	printf("A aresta entre %d e %d eh uma ponte.\n", i, j);
      }
      low[i] = min(low[i], low[j]);
    } else{
      low[i] = min(low[i], lbl[j]);
    }
  }
}

// Supoe que G seja um grafo conexo
void imprime_pontes()
{
  tempo = 0;
  memset(lbl, -1, sizeof lbl);
  dfs(0, -1);
}
