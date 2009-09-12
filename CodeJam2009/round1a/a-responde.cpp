#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;


int memo[(1<<9)];

char buf[1000];

int leitura()
{
  gets(buf);
  int r = 0;
  int x;
  char *s = buf;
  while(1){
    while(isspace(*s))
      s++;
    if(sscanf(s, "%d", &x) != 1)
      break;
    r |= (1 << (x-2));
    while(isdigit(*s))
      s++;
    if(*s == '\0')
      break;
  }
  return r;
}


int main()
{

  FILE *fp;
  fp = fopen("respostas", "r");

  for(int i = 1; i < (1 << 9); i++){
    int x, r;
    fscanf(fp, " %d %d", &x, &r);
    memo[x] = r;
    if(i != x)
      printf("aaaa\n");
  }
  
  int casos;
  scanf("%d\n", &casos);
  for(int h = 1; h <= casos; h++){
    int mask = leitura();
    printf("Case #%d: %d\n", h, memo[mask]);

  }
  
  return 0;
}
