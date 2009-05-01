#include <cstdio>

int s2, s3;
int pot3[40], pot2[40];
int qtd;

int simplifica(int n)
{
  s2 = s3 = 0;
  while(n % 2 == 0){
    n /= 2;
    s2++;
  }
  while(n % 3 == 0){
    n /= 3;
    s3++;
  }
  return n;
}

void resolve(long long n)
{
  qtd = 0;
  if(n == 0)
    return;

  long long i = 1;
  while((i<<1) < n)
    i <<= 1;
  for(; i > 0; i >>= 1){
    if(3LL * i <= n){
      n -= 
    }
  }
  
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int n;
    scanf( "%d", &n);

    n = simplifica(n);
    resolve(n, 0, 0);
    printf("%d %d", h, qtd);
    for(int i = 0; i < qtd; i++)
      printf(" [%d,%d]", pot2[i]+s2, pot3[i]+s3);
    printf("\n");
  }
  return 0;
}
