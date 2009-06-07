#include <cstdio>

#define MAX 110

int v[MAX];
int n;


int conta()
{
  int c = 0, t;
  for(int i = n; i > 0; i--)
    for(int j = 1; j < i; j++)
      if(v[j-1] > v[j]){
	t = v[j];
	v[j] = v[j-1];
	v[j-1] = t;
	c++;
      }
  return c;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    printf("Optimal train swapping takes %d swaps.\n", conta());
  }
  return 0;
}
