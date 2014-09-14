/*
 * Primeira fase da maratona 2014
 * Problema Volta
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4656
 * Resposta: AC
 */

#include <cstdio>

int main()
{
  int x, y;
  while(scanf(" %d %d", &x, &y) == 2){
    int d = y - x;
    printf("%d\n", 1+(x + d-1)/d);
  }
  return 0;
}
