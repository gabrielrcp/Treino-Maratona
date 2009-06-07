#include <cstdio>
#include <cstring>

using namespace std;

#define DIGI 100
#define POT 10000

struct bignum{
  int v[DIGI];
};

void somar(bignum &a, bignum &b)
{
  int r = 0;
  for(int i = 0; i < DIGI; i++){
    a.v[i] += b.v[i] + r;
    r = 0;
    while(a.v[i] >= POT){
      r++;
      a.v[i] -= POT;
    }
  }
}


void zerar(bignum &a)
{
  memset(a.v, 0, sizeof(a.v));
}

void multiplicar(bignum &a, int x)
{
  int r = 0;
  for(int i = 0; i < DIGI; i++){
    a.v[i] *= x;
    a.v[i] += r;
    r = 0;
    while(a.v[i] >= POT){
      a.v[i] -= POT;
      r++;
    }
  }
}


bignum resp[55][55];


void resolve()
{
  bignum temp;

  zerar(resp[0][0]);
  resp[0][0].v[0] = 1;


  for(int n = 1; n <= 50; n++){
    zerar(resp[n][0]);
    for(int k = 1; k <= 50; k++){
      zerar(resp[n][k]);
      zerar(temp);

      somar(resp[n][k], resp[n-1][k]);
      somar(temp, resp[n-1][k-1]);

      multiplicar(resp[n][k], k);
      multiplicar(temp, 2*n-k);

      somar(resp[n][k], temp);
    }
    zerar(resp[n][n+1]);
  }
}

void imprime(bignum &a)
{
  int i = DIGI - 1;
  while(i > 0 && a.v[i] == 0)
    i--;

  printf("%d", a.v[i]);
  i--;
  while(i >= 0){
    int p = POT / 10;
    while(a.v[i] < p){
      printf("0");
      p /= 10;
    }
    if(a.v[i] != 0)
      printf("%d", a.v[i]);
    i--;
  }
  printf("\n");
}


void responder(int n, int k)
{
  if(k > n){
    printf("0\n");
    return;
  }

  imprime(resp[n][k]);
}

int main()
{
  int casos;

  resolve();
  scanf(" %d", &casos);
  while(casos--){
    int n, k;
    scanf(" %d %d", &n, &k);

    responder(n, k);
  }

  return 0;
}
