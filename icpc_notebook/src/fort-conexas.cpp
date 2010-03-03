//numero maximo de vertices
#define MAX 5010

// grafo original, o seu transposto e numero de vertices
vector<int> G[MAX];
vector<int> Ginv[MAX];
int n;


int numcomp;
int comp[MAX];

int tempo;
int final[MAX];
char vis[MAX];

void dfs1(int i)
{
  if(vis[i]) return;
  vis[i] = 1;
  for(int k = 0; k < (int)G[i].size(); k++)
    dfs1(G[i][k]);
  final[tempo++] = i;
}

void dfs2(int i, int cp)
{
  if(comp[i] != -1)
    return;
  comp[i] = cp;

  for(int k = 0; k < (int)Ginv[i].size(); k++)
    dfs2(Ginv[i][k], cp);
}

void encontra_componentes()
{
  memset(vis, 0, sizeof vis);
  memset(comp, -1, sizeof comp);


  tempo = 0;
  for(int i = 0; i < n; i++)
    dfs1(i);

  numcomp = 0;
  for(int i = n-1; i >= 0; i--){
    int j = final[i];
    if(comp[j] == -1)
      dfs2(j, numcomp++);
  }
}
