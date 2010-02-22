#include <cstdio>

bool ehprimo(int n)
{
  if(n < 0) n = -n;
  if(n <= 1) return false;
  for(int i = 2; i <= n/i; i++){
    if(n % i == 0) return false;
  }
  return true;
}

int main()
{
  int n;
  scanf(" %d", &n);
  printf("%s\n", ehprimo(n) ? "sim" : "nao");
  return 0;
}
