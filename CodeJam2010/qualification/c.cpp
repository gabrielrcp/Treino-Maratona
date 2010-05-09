#include <cstdio>

typedef long long ll;

ll lucro[1010];
int prim[1010];
int R, N, K;
ll tam[1010];

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d %d %d", &R, &K, &N);
    for(int i = 0; i < N; i++)
      scanf(" %lld", tam+i);
    for(int i = 0; i < N; i++){
      int j = ((i+1)%N);
      lucro[i] = tam[i];
      while(j != i && lucro[i] <= K){
	if(lucro[i] + tam[j] > K)
	  break;
	lucro[i] += tam[j];
	j = ((j+1)%N);
      }
      prim[i] = j;
    }

    ll resp = 0;
    int i = 0;
    while(R--){
      resp += lucro[i];
      i = prim[i];
    }
    printf("Case #%d: %lld\n", h, resp);
  }
  return 0;
}
