#include <cstdio>

#define MAX 20

int v[MAX];

char resolve(int b)
{
  for(int i = 0; i < b; i++)
    if(v[i] < 0)
      return 'N';
  return 'S';
}

int main()
{
  int b, n;
  while(scanf(" %d %d", &b, &n) && b && n){
    for(int i = 0; i < b; i++)
      scanf(" %d", v+i);
    while(n--){
      int i, j, c;
      scanf(" %d %d %d", &i, &j, &c);
      i--; j--;
      v[i] -= c;
      v[j] += c;
    }
    printf("%c\n", resolve(b));
  }
  return 0;
}
