#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

#define INF (1<<30)

int somacum[55];
int v[55];
int n;

inline int soma(int i, int j)
{
  if(j >= i)
    return somacum[j+1] - somacum[i];
  return somacum[n] - somacum [i] + somacum[j+1];
}

int tam(int i, int j)
{
  if(i <= j)
    return j - i + 1;
  return n - (i-j-1);
}

int memo[55][55][55];

int vai(int i, int j, int k, int si, int teto)
{
  int s;
  if(si == n)
    s = 0;
  else
    s = ((i == 0) ? soma(si, n-1) : soma(si, i-1));

  if(i == j){
    if(k == 1)
      return ((s > 0) ? s : -INF);
    if(k == 0)
      return ((si == n ? teto : -INF));
    return -INF;
  }
  if(k == 0) return -INF;

  int &r = memo[i][k][si];
  if(r != -1)
    return r;

  r = -INF;
  if(s + v[i] <= teto){
    int nsi = (si == n ? i : si);
    r = vai((i+1)%n, j, k, nsi, teto);
  }

  int t = min(s, vai(i, j, k-1, n, teto));
  r = max(r, t);

  return r;
}


void imprime(int i, int j, int k, int si, int teto)
{
  if(i == j) return;

  int melhor = vai(i, j, k, si, teto);

  int s;
  if(si == n)
    s = 0;
  else
    s = ((i == 0) ? soma(si, n-1) : soma(si, i-1));

  if(s + v[i] <= teto){
    int nsi = (si == n ? i : si);
    if(vai((i+1)%n, j, k, nsi, teto) == melhor){
      if(si == n)
	printf("\n");
      else
	printf(" ");
      printf("%d", i+1);
      imprime((i+1)%n, j, k, nsi, teto);
      return;
    }
  }
  imprime(i, j, k-1, n, teto);
}



int main()
{
  freopen("necklace.in", "r", stdin);
  freopen("necklace.out", "w", stdout);

  int k;
  scanf(" %d %d", &n, &k);
  somacum[0] = 0;
  for(int i = 0; i < n; i++){
    scanf(" %d", v+i);
    somacum[i+1] = somacum[i] + v[i];
  }

  int r = INF;
  int ri = -1, rj = -1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      int teto = soma(i, j);
      if((ll)soma(0, n-1) > (ll)teto * k)
	continue;
      if(n - tam(i, j) < k-1)
	continue;
      memset(memo, -1, sizeof memo);
      int t = vai((j+1)%n, i, k-1, n, teto);
      if(teto - t <= r){
	r = teto - t;
	ri = i;
	rj = j;
      }
    }

  printf("%d\n", r);
  for(int m = ri; m != rj; m = ((m+1)%n)){
    if(m != ri) printf(" ");
    printf("%d", m+1);
  }
  if(ri != rj) printf(" ");
  printf("%d", rj+1);

  memset(memo, -1, sizeof memo);
  imprime((rj+1)%n, ri, k-1, n, soma(ri, rj));
  printf("\n");
  return 0;
}
