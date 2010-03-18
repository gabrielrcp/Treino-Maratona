#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int v[10];
  bool pri = true;
  while(scanf(" %d", &n) && n){
    for(int i = 0; i < n; i++)
      scanf(" %d", v+i);
    sort(v, v+n);

    if(!pri) printf("\n");
    pri = false;
    do{
      printf("%d", v[0]);
      for(int i = 1; i < n; i++)
	printf(" %d", v[i]);
      printf("\n");
    }while(next_permutation(v, v+n));
  }
  return 0;
}
