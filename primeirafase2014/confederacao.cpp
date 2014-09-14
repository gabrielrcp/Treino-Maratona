/*
 * Primeira fase da maratona 2014
 * Problema: confederacao
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4658
 * Resposta: AC
 */

#include <cstdio>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

struct plano{
  int a, b, c, d;
  bool esquerda(int x, int y, int z){
    return a*x + b*y + c*z > d;
  }
};

map< vector<bool> , int> contagem;
plano p[500];

int main()
{
  int M, N;
  while(scanf(" %d %d", &M, &N) == 2){
    for(int i = 0; i < M; i++){
      scanf(" %d %d %d %d", &p[i].a, &p[i].b, &p[i].c, &p[i].d);      
    }
    contagem.clear();
    int r = 1;
    for(int i = 0; i < N; i++){
      int x, y, z;
      scanf(" %d %d %d", &x, &y, &z);
      vector<bool> m (M, false);
      for(int j = 0; j < M; j++)
	if(p[j].esquerda(x, y, z))
	  m[j] = true;
      
      map<vector<bool>, int>::iterator it = contagem.find(m);
      if(it == contagem.end()){
	contagem[m] = 1;
      } else{
	if(it->second >= r)
	  r = it->second + 1;
	contagem[m]++;
      }
      
    }
    printf("%d\n", r);
  }
  return 0;
}
