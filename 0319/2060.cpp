#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define pii pair<int, int>

struct ride{
  int chegada;
  pii origem, destino;
};

vector <ride> corridas;
int ultima[600];

int distancia(pii a, pii b)
{
  return abs(a.first - b.first) + abs(a.second - b.second);
}

bool pode(int i, int j)
{
  return (corridas[i].chegada +
    distancia(corridas[i].origem, corridas[i].destino) +
    distancia(corridas[i].destino, corridas[j].origem) < 
	  corridas[j].chegada);
}


vector< vector<int> > G;
vector< int > emparelhado;
int M;


void aumenta(int dest, vector<int> &ant)
{
  int i = dest;
  while(i != -1){
    int j = ant[i];
    int k = ant[j];
    emparelhado[i] = j;
    emparelhado[j] = i;
    i = k;
  }
}



bool vai()
{
  queue<int> Q;
  vector<int> ant(2*M, -1);

  for(int i = 0; i < M; i++)
    if(emparelhado[i] == -1)
      Q.push(i);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    if(i < M){ // desco por qualquer aresta nao emparelhada
      for(int k = 0; k < G[i].size(); k++){
	int j = G[i][k];
	if(emparelhado[j] == -1){
	  ant[j] = i;
	  aumenta(j, ant);
	  return true;
	}
	if(emparelhado[j] != i && ant[j] == -1){
	  ant[j] = i;
	  Q.push(j);
	}
      }
    }
    else{
      int j = emparelhado[i];
      if(ant[j] == -1){
	Q.push(j);
	ant[j] = i;
      }
    }
  }
  return false;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &M);
    corridas = vector<ride> (M);

    for(int i = 0; i < M; i++){
      int hr, mn, ox, oy, dx, dy;
      scanf(" %d:%d %d %d %d %d", &hr, &mn, &ox, &oy, &dx, &dy);
      corridas[i].chegada = hr * 60 + mn;
      corridas[i].origem = make_pair(ox, oy);
      corridas[i].destino = make_pair(dx, dy);
    }

    G = vector< vector<int> > (2*M, vector<int> ());
    emparelhado = vector<int> (2*M, -1);
    for(int i = 0; i < M; i++)
      for(int j = i + 1; j < M; j++)
	if(pode(i, j))
	  G[i].push_back(j+M);

    /*
    for(int i = 0; i < M; i++){
      printf("%d: ", i);
      for(int j = i + 1; j < M; j++)
	if(pode(i, j))
	  printf("%d ", j);
      printf("\n");
    }

    */

    while(vai());

    int resp = M;
    for(int i = 0; i < M; i++)
      if(emparelhado[i] != -1)
	resp--;
    printf("%d\n", resp);
  }
  return 0;
}
