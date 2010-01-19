#include <cstdio>
#include <cstring>

int entra[1500][55];
int sai[1500][55];
char buf[1555];
int n;


void setar(int i, int j)
{
  int k1 = j / 32;
  int k2 = j % 32;
  sai[i][k1] |= (1 << k2);
  k1 = i / 32;
  k2 = i % 32;
  entra[j][k1] |= (1 << k2);
}

bool vai(int i, int j)
{
  int k1 = j / 32;
  int k2 = j % 32;
  return (sai[i][k1] & (1 << k2));
}

int conta(int i, int j)
{
  int r = 0;
  for(int k = 0; 32*k <= n; k++){
    int x = (entra[i][k] & sai[j][k]);
    r += __builtin_popcount(x);
  }
  return r;
}

int main()
{

  freopen("triatrip.in", "r", stdin);
  freopen("triatrip.out", "w", stdout);

  scanf(" %d ", &n);
  memset(entra, 0, sizeof entra);
  memset(sai, 0, sizeof sai);

  for(int i = 0; i < n; i++){
    gets(buf);
    for(int j = 0; j < n; j++)
      if(buf[j] == '+')
	setar(i, j);
  }

  long long r = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j || !vai(i, j)) continue;
      r += (long long)conta(i, j);
    }
  }
  printf("%lld\n", r/3);
  return 0;
}
