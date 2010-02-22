#include <cstdio>
#include <cctype>

#define MAX 110

int v[MAX];

int lerint()
{
  char c;
  int r;
  while(!isdigit(c = getchar_unlocked()));
  r = c - '0';
  while(isdigit(c = getchar_unlocked())){
    r = 10 * r + c - '0';
  }
  return r;
}

char ler()
{
  char c;
  while(!isdigit((c = getchar_unlocked())));
  return c;
}

int main()
{
  int n, r;
  for(int h = 1; scanf(" %d %d", &n, &r) && n && r; h++){
    for(int i = 0; i < n; i++)
      v[i] = lerint();

    while(r--){
      char certo, x;
      n = lerint();
      certo = ler();
      int j = 0;
      for(int i = 0; i < n; i++){
	x = ler();
	v[j] = v[i];
	if(x == certo)
	  j++;
      }
    }

    printf("Teste %d\n%d\n", h, *v);
  }
  return 0;
}
