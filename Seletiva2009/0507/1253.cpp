#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


#define MAXEST 12


vector< int >  partidas[MAXEST][MAXEST];
vector< int >  chegadas[MAXEST][MAXEST];
vector<double> probabi[MAXEST][MAXEST];
vector< pair<pair<int,int>, double> > G[MAXEST][MAXEST];


int destino, tempomax, tempoorigem;

int lerhora()
{
  int h, m;
  scanf(" %d:%d", &h, &m);
  return 60*h + m;
}

void ler()
{
  char x, y;
  int ta, tb;
  double p;

  scanf(" %c", &x);
  ta = lerhora();
  scanf(" %c", &y);
  tb = lerhora();
  scanf(" %lf", &p);

  G[x-'A'][y-'A'].push_back(make_pair(make_pair(ta,tb), p));
}


bool usado[MAXEST];
int rota[MAXEST];

int melhor[MAXEST];
double resp;
int tamrota;

double memo[MAXEST][1500];

double vai(int i, int t)
{
  if(t > tempomax)
    return 0.0;
  if(rota[i] == destino)
    return 1.0;

  double &r = memo[i][t+1];
  if(r > -0.5)
    return r;

  r = 0.0;  
  int x = rota[i];
  int y = rota[i+1];
  double pac = 1.0;

  for(int k = 0; k < partidas[x][y].size(); k++){
    if(partidas[x][y][k] > t){
      r += pac * (1.0 - probabi[x][y][k]) * vai(i+1, chegadas[x][y][k]);
      pac *= probabi[x][y][k];
    }
  }
  return r;
}

void confere(int n)
{
  for(int i = 0; i < MAXEST; i++)
    for(int j = tempoorigem; j <= tempomax; j++)
      memo[i][j] = -1.0;
  /*
  printf("-->");
  for(int i = 0; i <= n; i++)
    printf("%c ", rota[i]+'A');
  printf("\n");
  */
  double p = vai(0, tempoorigem - 1);
  if(p > resp){
    resp = p;
    for(int i = 0; i <= n; i++)
      melhor[i] = rota[i];
    tamrota = n;
  }
}


void gerarotas(int at, int tempo, int k)
{
  if(usado[at] || tempo > tempomax)
    return;
  rota[k] = at;
  usado[at] = true;
  if(at == destino)
    confere(k);
  else{
    for(int i = 0; i < MAXEST; i++){
      int t = tempomax + 1;
      for(int j = 0; j < partidas[at][i].size(); j++)
	if(partidas[at][i][j] > tempo)
	  t = min(t, chegadas[at][i][j]);
      gerarotas(i, t, k+1);
    }
  }
  usado[at] = false;

}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){

    for(int i = 0; i < MAXEST; i++)
      for(int j = 0; j < MAXEST; j++){
	partidas[i][j].clear();
	chegadas[i][j].clear();
	probabi[i][j].clear();
	G[i][j].clear();
      }
	

    int n;
    scanf(" %d", &n);
    while(n--)
      ler();
    int origem;
    char c;
    scanf(" %c", &c);
    origem = c - 'A';
    tempoorigem = lerhora();
    scanf(" %c", &c);
    destino = c - 'A';
    tempomax = lerhora();


    for(int i = 0; i < MAXEST; i++){
      for(int j = 0; j < MAXEST; j++){
	sort(G[i][j].begin(), G[i][j].end());
	for(int k = 0; k < G[i][j].size(); k++){
	  partidas[i][j].push_back(G[i][j][k].first.first);
	  chegadas[i][j].push_back(G[i][j][k].first.second);
	  probabi[i][j].push_back(G[i][j][k].second);
	}
      }
      usado[i] = false;
    }

    resp = -1.0;
    tamrota = 0;
    gerarotas(origem, tempoorigem-1, 0);

    for(int i = 0; i < tamrota; i++)
      printf("%c ", melhor[i]+'A');    
    printf("%c\n", destino+'A');
    printf("%.4lf\n", resp);
  }
  
  return 0;
}


