#include <cstdio>

typedef long long ll;

ll vai(int n)
{
  if(n == 1) return 0;

  ll s = 1;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0){
      s += i;
      int j = n/i;
      if(j != i) s += j;
    }
  }
  return s;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    printf("%lld\n", vai(n));
  }
  return 0;
}
