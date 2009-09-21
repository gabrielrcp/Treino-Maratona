#include <cstdio>
#include <cstring>

#define MAX 100000

char v1[MAX];
char v2[MAX];

void ler(char *v, int n)
{
  memset(v, 0, MAX);
  while(n--){
    int x;
    scanf(" %d", &x);
    v[--x] = 1;
  }
}

int main()
{
  int n, m;
  while(scanf(" %d %d", &n, &m) && n && m){
    ler(v1, n);
    ler(v2, m);

    int c1 = 0, c2 = 0;
    for(int k = 0; k < MAX; k++){
      if(v1[k] && (!v2[k]))
	c1++;
      if((!v1[k]) && v2[k])
	c2++;
    }
    if(c2 < c1) c1 = c2;
    printf("%d\n", c1);
  }
  return 0;
}
