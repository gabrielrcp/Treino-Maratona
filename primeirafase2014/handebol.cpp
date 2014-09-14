/*
 * Primeira fase da maratona 2014
 * Problema: handebol
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4663
 * Resposta: AC
 */

#include <cstdio>

int N, M;

bool jogador_ok()
{
  bool ok = true;
  for(int i = 0; i < M; i++){
    int x;
    scanf(" %d", &x);
    if(x == 0)
      ok = false;
  }
  return ok;
}


int main()
{
  while(scanf(" %d %d", &N, &M) == 2){
    int r = 0;
    for(int i = 0; i < N; i++){
      if(jogador_ok())
	r++;
    }
    printf("%d\n", r);
  }
  return 0;
}
