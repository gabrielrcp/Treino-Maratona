#include <cstdio>
#include <vector>

using namespace std;


#define MAX 2000010
#define MOD 1300031;


int primos[148934];
int np;
bool crivo[MAX];

void geraprimos()
{
  np = 0;
  for(int i = 0; i < MAX; i++)
    crivo[i] = true;
  for(int i = 2; i < MAX; i++){
    if(crivo[i] == false) continue;
    primos[np++] = i;
    if(i*i < MAX)
      for(int j = i+i; j < MAX; j += i)
	crivo[j] = false;
  }
}

int potencia(int n, int p)
{
  int r = 0;
  while(n > 0){
    n /= p;
    r += n;
  }
  return r;
}

vector<int> fatorial(int n)
{
  vector<int> r;
  for(int i = 0; i < np && primos[i] <= n; i++)
    r.push_back(potencia(n, primos[i]));
  return r;
}


int vai(int n, int k)
{
  vector<int> r = fatorial(n);
  vector<int> a = fatorial(k);
  vector<int> b = fatorial(n-k);

  for(int i = 0; i < a.size(); i++)
    r[i] -= a[i];
  for(int i = 0; i < b.size(); i++)
    r[i] -= b[i];

  long long resp = 1;
  for(int i = 0; i < r.size(); i++){
    for(int j = 0; j< r[i]; j++){
      resp *= (long long)primos[i];
      resp %= MOD;
    }
  }
  return (int)resp;
  
}

int main()
{
  geraprimos();
  //printf("%d\n", np);
  int h, n, c;
  scanf(" %d", &h);
  while(h--){
    //printf("-%d\n", h);
    scanf(" %d %d", &n, &c);
    printf("%d\n", vai(c+n-1, n-1));
  }
  return 0;
}
