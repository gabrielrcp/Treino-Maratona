#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>

#define MAX 30010

using namespace std;


struct empregado{
  int id, altura, salario;
  bool operator <(const empregado &outro) const{
    return salario < outro.salario;
  }
};

empregado v[MAX];
int pai[MAX];
int subord[MAX];
vector<int> G[MAX];
map<int, int> M;
int n, q;

int vai(int i)
{
  int &r = subord[i];
  if(r != -1)
    return r;

  r = 0;
  for(int j = 0; j < G[i].size(); j++)
    r += vai(G[i][j]) + 1;
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &n, &q);

    M.clear();

    for(int i = 0; i < n; i++){
      empregado novo;
      scanf(" %d %d %d", &novo.id, &novo.salario, &novo.altura);
      v[i] = novo;
      pai[i] = -1;
      subord[i] = -1;
      G[i].clear();
    }
    sort(v, v+n);

    stack<int> pilha;
    for(int i = 0; i < n; i++){
      M[v[i].id] = i;
      while((!pilha.empty()) && v[pilha.top()].altura <= v[i].altura){
	G[i].push_back(pilha.top());
	pai[pilha.top()] = i;
	pilha.pop();
      }
      pilha.push(i);
    }

    while(q--){
      int id;
      scanf(" %d", &id);
      int i = M[id];
      printf("%d %d\n", (pai[i] == -1 ? 0 : v[pai[i]].id), vai(i));
    }
  }
  return 0;
}
