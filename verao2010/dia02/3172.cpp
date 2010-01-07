#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 1010
typedef long long ll;

ll pesos[MAX];
ll soma[MAX];

int n;
ll c, melhor;

void vai(int i, ll at)
{
  if(melhor == c) return;
  if(i < 0) return;

  if((ll)at + soma[i] <= melhor) return;

  if(at + pesos[i] <= c){
    melhor = max(melhor, at+pesos[i]);
    vai(i-1, at+pesos[i]);
  }
  vai(i-1, at);
}

int main()
{
  scanf(" %d %lld", &n, &c);
  for(int i = 0; i < n; i++)
    scanf(" %d", pesos+i);

  n--;
  while(n >= 0 && pesos[n] > c) n--;
  n++;

  soma[0] = pesos[0];
  for(int i = 1; i < n; i++)
    soma[i] = soma[i-1] + pesos[i];

  melhor = 0;

  vai(n-1, 0);
  printf("%lld\n", melhor);
  return 0;
}
