#include <cstdio>
#include <cstring>

int r, c;

char mapa[20][20];

int codifica(int i, int j, int t)
{
  int x = j + i*c + t*r*c + 2;
  //printf("%d\n", x);
  return x;
}

#define MAXV 40000
#define MAXE 4000000
#define MAXT 110

int grafo[MAXV];
int vertice[MAXE];
int proximo[MAXE];
int cap[MAXE];
int fluxo[MAXE];
int nume;

void add_edge(int i, int j, int cp)
{
  int e1 = nume++;
  int e2 = nume++;

  proximo[e1] = grafo[i];
  grafo[i] = e1;
  vertice[e1] = j;
  cap[e1] = cp;
  fluxo[e1] = 0;

  proximo[e2] = grafo[j];
  grafo[j] = e2;
  vertice[e2] = i;
  cap[e2] = 0;
  fluxo[e2] = 0;
}

int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};

int nump;

int vis[MAXV];
int mark;

bool aumenta(int i)
{
  if(vis[i] == mark) return false;
  vis[i] = mark;
  if(i == 1)
    return true;

  for(int e = grafo[i]; e != -1; e = proximo[e]){
    if(fluxo[e] >= cap[e]) continue;
    if(aumenta(vertice[e])){
      fluxo[e]++;
      fluxo[e^1]--;
      return true;
    }
  }
  return false;
}

int fluxo_maximo()
{
  int r = 0;
  while(aumenta(0)){
    r++;
    mark++;
  }
  mark++;
  return r;
}

int resolve()
{
  int tot = 0;
  memset(vis, 0, sizeof vis);
  mark = 1;

  for(int t = 1; t < MAXT; t++){

    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++){
	if(mapa[i][j] == 'D')
	  add_edge(codifica(i, j, t), 1, 1);
	if(mapa[i][j] != '.') continue;
	for(int k = 0; k < 5; k++){
	  int x = i + dx[k];
	  int y = j + dy[k];
	  if(mapa[x][y] != 'X'){
	    int a = codifica(i, j, t-1);
	    int b = codifica(x, y, t);
	    add_edge(a, b, (1<<30));
	  }
	}
      }
    tot += fluxo_maximo();
    if(tot == nump) return t;
    //printf("%d %d\n", t, tot);
  }
  //printf("-- %d\n", tot);
  return -1;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &r, &c);

    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
	scanf(" %c", &mapa[i][j]);
      }
    }
    /*
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++)
	putchar(mapa[i][j]);
      putchar('\n');
    }
    */

    memset(grafo, -1, sizeof grafo);
    nume = 0;
    nump = 0;    
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	if(mapa[i][j] == '.'){
	  nump++;
	  add_edge(0, codifica(i, j, 0), 1);
	}

    /*
    for(int i = 0; i < MAXV; i++){
      if(grafo[i] == -1) continue;
      printf("%d - ", i);
      for(int e = grafo[i]; e != -1; e = proximo[e]){
	printf("%d ", vertice[e]);
      }
      printf("\n");
    }
    */

    int t = resolve();
    if(t == -1)
      printf("impossible\n");
    else
      printf("%d\n", t);
    
  }
  return 0;
}
