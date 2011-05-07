#include <cstdio>

double resp[1010];
double nenhuma[1010];
double fat[1010];

double prob(int n, int k)
{
  return nenhuma[n-k]*fat[k];
}

int main()
{
  double termo = -1.0;
  nenhuma[0] = 1.0;
  nenhuma[1] = 0.0;
  fat[0] = fat[1] = 1.0;
  for(int k = 2; k <= 1000; k++){
    termo /= (-1.0) * k;
    nenhuma[k] = nenhuma[k-1] + termo;
    fat[k] = fat[k-1]/k;
  }

  resp[0] = resp[1] = 0.0;

  for(int n = 2; n <= 1000; n++){
    resp[n] = prob(n, 0);
    for(int k = 1; k <= n; k++){
      resp[n] += prob(n, k) * (resp[n-k]+1.0);
    }
    resp[n] /= 1.0 - prob(n, 0);
    //printf("%d %f\n", n, resp[n]);
  }


  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int N;
    scanf("%d", &N);
    int R = N;
    for(int i = 1; i <= N; i++){
      int x;
      scanf(" %d", &x);
      if(x == i) R--;
    }
    printf("Case #%d: %.10f\n", h, resp[R]);
  }
  return 0;
}
