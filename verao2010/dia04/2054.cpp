//TLE! :/

#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

struct no{
  int custo;
  int tempo;
  int id;
  bool operator < (const no &outro) const{
    int a = custo * outro.tempo;
    int b = outro.custo * tempo;
    if(a == b) return id < outro.id;
    return a < b;
  }
};

#define MAX 1010

no v[MAX];

int pai[MAX];
int grafo[MAX];
int ultimo[MAX];
int vertice[MAX];
int proximo[MAX];
int nume;

void add_edge(int p, int f)
{
  //printf("%d %d\n", f+1, p+1);
  int e = nume++;
  if(grafo[p] == -1)
    ultimo[p] = e;
  proximo[e] = grafo[p];
  grafo[p] = e;
  vertice[e] = f;
  pai[f] = p;
}

int total;
int tat;

set<no> S;

void contrai()
{
  int f = S.rbegin()->id;
  int p = pai[f];

  //printf("-- %d %d\n", f+1, p+1);

  S.erase(v[f]);

  for(int e = grafo[f]; e != -1; e = proximo[e])
    pai[vertice[e]] = p;


  if(p != -1){
    S.erase(v[p]);
    int e = ultimo[p];
    proximo[e] = grafo[f];    
    ultimo[p] = ultimo[f];
    total += v[f].custo * v[p].tempo;

    v[p].tempo += v[f].tempo;
    v[p].custo += v[f].custo;
    S.insert(v[p]);
    return;
  }

  total += v[f].custo*tat;
  tat += v[f].tempo;
}

int main()
{
  int n, raiz;
  while(scanf(" %d %d", &n, &raiz) && n > 0){
    raiz--;
    for(int i = 0; i < n; i++){
      scanf(" %d", &v[i].custo);
      v[i].tempo = 1;
      v[i].id = i;
    }
    pai[raiz] = -1;
    memset(grafo, -1, sizeof grafo);
    nume = 0;
    for(int i = 1; i < n; i++){
      int p, f;
      scanf(" %d %d", &p, &f);
      p--; f--;
      add_edge(p, f);
    }
    /*
    for(int i = 0; i < n; i++)
      printf("%d %d\n", i+1, pai[i]+1);
    */
    S.clear();
    for(int i = 0; i < n; i++){
      S.insert(v[i]);
    }
    total = 0;
    tat = 1;
    while(!S.empty()){
            
      contrai();
      //printf("%d %d\n", total, tat);
      /*
      for(set<no>::iterator it = S.begin(); it != S.end(); it++){
	printf("%d %d %d\n", it->id+1, it->custo, it->tempo);
      }
      printf("\n");
      */
    }
    printf("%d\n", total);
  }
  return 0;
}
