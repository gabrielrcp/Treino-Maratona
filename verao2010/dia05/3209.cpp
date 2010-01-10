#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

typedef long long ll;

#define MAX (1<<25)

bitset<MAX> nep (0);
int npr;
int primos[2100000];

void crivo()
{
  for(int i = 3; i*i < MAX; i += 2){
    if(!nep[i]){
      for(int j = i*i; j < MAX; j += 2*i)
	nep[j] = 1;
    }
  }
  
  npr = 1;
  primos[0] = 2;
  for(int i = 3; i < MAX; i += 2){
    if(!nep[i])
      primos[npr++] = i;
  }
  //printf("%d\n", npr);
}


// primo 3 (mod 4) -> expoente tem que ser par
bool vai(ll n)
{
  if(n < 0) return false;
  if(n%4 == 3) return false;
  for(int i = 0; i < npr && n > 1 && (ll)primos[i]*primos[i] <= n; i++){
    int p = primos[i];
    int c = 0;
    while(n > 1 && (n % p == 0)){
      n /= p;
      c++;
    }
    if((p % 4 == 3) && (c & 1))
      return false;
  }
  return (n % 4 != 3);
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
    //printf("%lld %s\n", n, (vai(n) ? "YES" : "NO"));
  }

  return 0;
}

