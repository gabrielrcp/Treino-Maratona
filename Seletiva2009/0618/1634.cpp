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
map<int, int> M;
int n, q;

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
      subord[i] = 0;
    }
    sort(v, v+n);

    stack<int> pilha;
    for(int i = 0; i < n; i++){
      M[v[i].id] = i;
      while(!pilha.empty()){
	int j = pilha.top();
	if(v[j].altura > v[i].altura)
	  break;
	pilha.pop();	
	subord[i] += subord[j] + 1;
	pai[j] = i;
      }
      pilha.push(i);
    }

    while(q--){
      int id;
      scanf(" %d", &id);
      int i = M[id];
      printf("%d %d\n", (pai[i] == -1 ? 0 : v[pai[i]].id), subord[i]);
    }
  }
  return 0;
}
