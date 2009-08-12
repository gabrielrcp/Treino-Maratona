#include <cstdio>


long long memo[20];
long long fat[20];

int a[20];

int atual;

long long coef(int n)
{
  long long r = fat[atual];
  int s = 0;
  for(int i = 0; i < n; i++){
    r /= fat[a[i]];
    s += a[i];
  }
  r /= fat[atual-s];
  return r;
}

long long vai(int b, int n)
{
  long long r = coef(n);
  for(int i = 1; i <= b; i++){
    a[n] = i;
    r += vai(b-i, n+1);
  }
  return r;
}

long long resolve(int b)
{
  atual = b;
  return vai(b, 0) - 1LL;
}


int main()
{
  fat[0] = 1;
  for(int i = 1; i < 14; i++)
    fat[i] = (long long)i * fat[i-1];
  
  for(int b = 1; b <= 13; b++)
    memo[b] = resolve(b);

  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int b;
    scanf(" %d", &b);
    printf("%d %d %lld\n", h, b, memo[b]);
  }

  return 0;
}
