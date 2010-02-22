#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 25

int nao[MAX];
int n;

bool ok(int m)
{
  for(int i = 0; i < n; i++){
    if((1<<i) & m){
      if(nao[i] & m)
	return false;
    }
  }
  return true;
}

int main()
{
  for(int h = 1; scanf(" %d", &n) && n; h++){

    memset(nao, 0, sizeof nao);


    for(int i = 0; i < n; i++){
      while(1){
	int j;
	scanf(" %d", &j); j--;
	if(j == -1) break;
	nao[i] |= (1<<j);
	nao[j] |= (1<<i);
      }
    }

    int resp = 0;
    for(int x = (1<<n)-1; x > 0; x--){
      int t = __builtin_popcount(x);
      if(t <= resp) continue;
      if(ok(x))
	resp = t;
    }
    printf("Teste %d\n%d\n\n", h, resp);
  }
  return 0;
}
