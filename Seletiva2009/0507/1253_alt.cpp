/* Essa solucao esta errada, casos de teste no .in*/

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

double vai(int, int, int);
double vai(int, int);

double memo1[MAXEST][2000][MAXEST];
double memo2[MAXEST][2000];

double vai(int i, int t, int j)
{
  double &r = memo1[i][t+1][j];

  if(r > -0.5)
    return r;

  double pac = 1.0;

  r = 0.0;
  for(int k = 0; k < partidas[i][j].size(); k++){
    if(partidas[i][j][k] > t){
      r += pac * (1 - probabi[i][j][k]) * vai(j, chegadas[i][j][k]);
      pac *= probabi[i][j][k];
    }
  }
  return r;
}


double vai(int i, int t)
{
  if(t > tempomax)
    return 0.0;
  if(i == destino)
    return 1.0;

  double &r = memo2[i][t+1];

  if(r > -0.5)
    return r;

  //r = 0.0;
  for(int j = 0; j < MAXEST; j++)
    r = max(r, vai(i, t, j));
  return r;
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
    }


    for(int i = 0; i < MAXEST; i++)
      for(int t = tempoorigem; t <= tempomax+1; t++){
	for(int j = 0; j < MAXEST; j++)
	  memo1[i][t][j] = -1.0;
	memo2[i][t] = -1.0;
      }

    double resp = vai(origem, tempoorigem - 1);
    //imprimerota(origem);
    printf("%.4lf\n", resp);
  }
  
  return 0;
}


