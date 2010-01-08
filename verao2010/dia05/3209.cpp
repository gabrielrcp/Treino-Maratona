// errado (lento)

#include <cstdio>
#include <cstring>

typedef long long ll;

#define MAX (1<<25)

char nep[MAX];

int npr;
int primos[1000];

void crivo()
{
  memset(nep, 0, sizeof nep);
  npr = 1;
  primos[0] = 2;

  for(int i = 3; i*i < MAX; i += 2){
    if(!nep[i]){
      primos[npr++] = i;
      for(int j = i*i; j < MAX; j += 2*i)
	nep[j] = 1;
    }
  }
  //printf("%d\n", npr);
}


// primo 3 (mod 4) -> expoente tem que ser par

bool vai(ll n)
{
  if(n < 0) return false;
  if(n % 4LL == 3LL) return false;
  for(int i = 0; i < npr; i++){
    int p = primos[i];
    int c = 0;
    while(n > 1 && (n % p == 0)){
      n /= p;
      c++;
    }
    if((p % 4 == 3) && (c % 2 == 1))
      return false;
  }
  return (n <= 1);
}

bool fb(ll n)
{
  for(int i = 0; i*i <= n; i++)
    for(int j = i; j*j <= n; j++)
      if(i*i + j*j == n)
	return true;
  return false;
}

int main()
{

  int casos;
  scanf(" %d", &casos);
  crivo();
  while(casos--){
    long long n;
    scanf(" %lld", &n);
    printf("%s\n", (vai(n) ? "YES" : "NO"));
  }

  ll n = 0;
  while(1){
    bool a = vai(n);
    bool b = fb(n);
    if( (a && (!b)) || ((!a) && b) )
      printf("%lld\n", n);
    n++;
  }

  return 0;
}
