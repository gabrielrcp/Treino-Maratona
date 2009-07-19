#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 676
#define INF (1 << 30)

struct node{
  int c;
  int v;
};

node G[MAX][MAX];
int num[MAX];
int inv[MAX][MAX];
int numinv[MAX];
int mat[MAX][MAX];

inline int numera(char a, char b)
{
  return 26*(int)(a-'a') + (int)(b-'a');
}

char buf[1010];
double resposta;

void nova_aresta()
{
  scanf(" %s", buf);
  int n = strlen(buf);
  if(n < 2) return;

  int i = numera(buf[0], buf[1]);
  int j = numera(buf[n-2], buf[n-1]);

  if(i == j){
    if((double)n > resposta)
      resposta = (double) n;
    return;
  }
  if(mat[i][j] < n)
    mat[i][j] = n;
}

int comp[MAX];
int ncomp;
int tamcomp[MAX];
int term[MAX];
bool vis[MAX];
int tempo;


void dfs1(int i)
{
  if(vis[i])
    return;
  vis[i] = true;
  for(int k = 0; k < num[i]; k++)
    dfs1(G[i][k].v);
  term[tempo++] = i;
}

void dfs2(int i, int cp)
{
  if(comp[i] != -1)
    return;
  comp[i] = cp;
  tamcomp[cp]++;
  for(int k = 0; k < numinv[i]; k++)
    dfs2(inv[i][k], cp);
}

void achacomp()
{
  tempo = 0;
  for(int i = 0; i < MAX; i++){
    comp[i] = -1;
    vis[i] = false;
    tamcomp[i] = 0;
  }

  for(int i = 0; i < MAX; i++)
    dfs1(i);

  ncomp = 0;
  for(int i = MAX-1; i >= 0; i--){
    int j = term[i];
    if(comp[j] == -1)
      dfs2(j, ncomp++);
  }
}

int dist[MAX][MAX+1];

bool foi[MAX];

double vai()
{
  int lim = 0;
  achacomp();
  for(int cp = 0; cp < ncomp; cp++){
    foi[cp] = false;
    lim = max(lim, tamcomp[cp]);
  }
  for(int i = 0; i < MAX; i++)
    dist[i][0] = INF;

  for(int i = 0; i < MAX; i++){
    int cp = comp[i];
    if(foi[cp]) continue;
    foi[cp] = true;
    dist[i][0] = 0;
  }

  for(int k = 1; k <= lim; k++){
    for(int i = 0; i < MAX; i++)
      dist[i][k] = INF;
    for(int i = 0; i < MAX; i++){
      if(tamcomp[comp[i]] < k) continue;
      for(int l = 0; l < num[i]; l++){
	int j = G[i][l].v;
	if(comp[j] != comp[i]) continue;
	int c = G[i][l].c;
	dist[j][k] = min(dist[j][k], dist[i][k-1] + c);
      }
    }
  }

  double resp = 0.0;
  for(int i = 0; i < MAX; i++){
    double t = -1.0e100;
    int n = tamcomp[comp[i]];
    for(int k = 0; k < n; k++)
      t = max(t, (dist[i][n] - dist[i][k]) / (double)(n - k));
    resp = min(resp, t);
  }

  return resp;
}

int main()
{
  int n;
  while(1){
    scanf(" %d", &n);
    if(n == 0)
      break;

    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++)
	mat[i][j] = 0;
    resposta = 0;

    while(n--)
      nova_aresta();
    for(int i = 0; i < MAX; i++)
      num[i] = numinv[i] = 0;
    for(int i = 0; i < MAX; i++){
      for(int j = 0; j < MAX; j++)
	if(mat[i][j] != 0){
	  G[i][num[i]].v = j;
	  G[i][num[i]].c = -mat[i][j];
	  num[i]++;

	  inv[j][numinv[j]] = i;
	  numinv[j]++;
	}
    }

    resposta = max(resposta, -vai());
    if(resposta < 1.0)
      printf("No solution.\n");
    else
      printf("%.2lf\n", resposta);
  }
  return 0;
}
