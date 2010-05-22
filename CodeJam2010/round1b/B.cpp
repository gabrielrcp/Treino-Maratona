#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (1<<30)

int N, K, B, T;

int X[55], V[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d %d %d %d", &N, &K, &B, &T);
    for(int i = 0; i < N; i++)
      scanf(" %d", X+i);
    for(int i = 0; i < N; i++)
      scanf(" %d", V+i);

    int resp = 0;
    for(int i = N-1; i >= 0 && K > 0; i--){
      if(X[i] + V[i] * T >= B)
	K--;
      else
	resp += K;
    }
    printf("Case #%d: ", h);
    if(K <= 0)
      printf("%d\n", resp);
    else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}
