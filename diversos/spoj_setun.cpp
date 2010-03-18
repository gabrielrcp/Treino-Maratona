#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll pot[30];

void imprime(ll n)
{
  if(n == 0) return;
  int resto = (((n%3)+3)%3);
  if(resto == 2) resto = -1;

  imprime((n-resto)/3);
  if(resto == 1)
    printf("+");
  else if(resto == -1)
    printf("-");
  else
    printf("0");
}

int main()
{
  ll n;
  pot[0] = 1;
  for(n = 1; n < 30; n++)
    pot[n] = 3*pot[n-1]; 

  while(scanf(" %lld", &n) == 1){
    if(n == 0) printf("0");
    else imprime(n);
    puts("");
  }

  return 0;
}
