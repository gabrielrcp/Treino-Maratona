#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100100

int v[MAX];

int main()
{
  int n;
  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %d", v+i);
  sort(v, v+n);

  int maximo, resp;
  resp = v[0];
  maximo = 0;
  
  int i, j;
  i = 0;
  while(i < n){
    j = i + 1;
    while(j < n && v[j] == v[i])
      j++;
    if(j - i > maximo){
      maximo = j-i;
      resp = v[i];
    }
    i = j;
  }
  printf("%d\n", resp);
  return 0;
}
