#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 10010
char consigo[MAX];

int v[110];
int n;

char resolve(int x, int y, int s)
{
  s += x + y;
  if(s % 2 == 1)
    return 'N';
  s /= 2;
  if(s < x || s < y)
    return 'N';

  sort(v, v+n);
  memset(consigo, 0, sizeof consigo);
  consigo[0] = 1;
  int ult = 0;

  for(int i = 0; i < n; i++){
    ult += v[i];
    for(int j = ult; j >= v[i]; j--){
      if(consigo[j-v[i]])
	consigo[j] = 1;
    }
    if(consigo[s-x] && consigo[s-y])
      return 'S';
  }
  return 'N';
}

int main()
{
  for(int h = 1; ; h++){
    int x, y;
    scanf(" %d %d %d", &x, &y, &n);
    if(x == 0) break;
    int s = 0;

    for(int i = 0; i < n; i++){
      scanf(" %d", v+i);
      s += v[i];
    }

    printf("Teste %d\n%c\n\n", h, resolve(x, y, s));
  }
  return 0;
}
