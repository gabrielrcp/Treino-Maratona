#include <cstdio>

#define MAX 510

int moedas[MAX];
int m25[MAX];
int m10[MAX];
int m5[MAX];
int m1[MAX];

#define INF (1<<30)


void resolve()
{
  moedas[0] = m25[0] = m10[0] = m5[0] = m1[0] = 0;

  for(int n = 1; n < MAX; n++){
    moedas[n] = INF;
    if(n >= 1 && moedas[n-1] < moedas[n]){
      moedas[n] = moedas[n-1]+1;
      m1[n] =  m1[n-1] + 1;
      m5[n] =  m5[n-1];
      m10[n] = m10[n-1];
      m25[n] = m25[n-1];
    }
    if(n >= 5 && moedas[n-5] < moedas[n]){
      moedas[n] = moedas[n-5]+1;
      m1[n] =  m1[n-5];
      m5[n] =  m5[n-5] + 1;
      m10[n] = m10[n-5];
      m25[n] = m25[n-5];
    }
    if(n >= 10 && moedas[n-10] < moedas[n]){
      moedas[n] = moedas[n-10]+1;
      m1[n] =  m1[n-10];
      m5[n] =  m5[n-10];
      m10[n] = m10[n-10] + 1;
      m25[n] = m25[n-10];
    }
    if(n >= 25 && moedas[n-25] < moedas[n]){
      moedas[n] = moedas[n-25]+1;
       m1[n] =  m1[n-25];
       m5[n] =  m5[n-25];
      m10[n] = m10[n-25];
      m25[n] = m25[n-25] + 1;
    }
  }
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  resolve();
  for(int h = 1; h <= casos; h++){
    int n;
    scanf(" %d", &n);
    printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
	   h, m25[n], m10[n], m5[n], m1[n]);
  }
  return 0;
}
