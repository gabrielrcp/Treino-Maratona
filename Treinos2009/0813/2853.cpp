#include <cstdio>

int resolve(long long n)
{
  int conta = 0;
  for(long long k = 2; k*k <= n; k++){
    if(n % k == 0){
      long long t, l;
      t = n/k - k + 1;
      if(t >= 2LL && (t%2 == 0))
	conta++;
      if(k*k == n)
	break;
      l = n / k;
      t = n/l - l + 1;
      if(t >= 2LL && (t%2 == 0))
	conta++;
    }
  }
  return conta;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int prob;
    long long n;
    scanf(" %d %lld", &prob, &n);
    printf("%d %d\n", prob, resolve(2LL*n));
  }
  return 0;
}
