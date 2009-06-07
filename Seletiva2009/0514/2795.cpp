#include <cstdio>
#include <cstring>

#define MOD 1000000000

char fita[500];
long long memo[500][500];


long long vai(int i, int j)
{
  if(i > j || fita[i] != fita[j])
    return 0;
  if(i == j)
    return 1;

  long long &r = memo[i][j];
  if(r != -1) return r;

  r = vai(i+1, j-1) % MOD;
  for(int k = i+2; k < j; k++){
    if(fita[k] == fita[i]){
      r += (vai(i+1, k-1)%MOD) * (vai(k, j)%MOD);
      r %= MOD;
    }
  }
  return r;
}

int main()
{

  scanf(" %s", fita);
  int n = strlen(fita);
  
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
      memo[i][j] = -1;

  printf("%lld\n", vai(0, n-1));

  /*
  printf("c --");
  for(int j = 0; j < n; j++)
    printf("%d ", j);
  printf("\n");
  for(int i = 0; i < n; i++){
    printf("%d --", i);
    for(int j = 0; j < n; j++)
      printf("%lld ", vai(i, j));
    printf("\n");
  }
  */

  return 0;
}
