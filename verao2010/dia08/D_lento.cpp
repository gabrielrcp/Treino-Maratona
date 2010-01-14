#include <cstdio>
#include <cstring>

#define MOD (1234567LL)

typedef long long ll;

ll D[35][35][1100];
ll A[35][1000][1100];
int N;

ll vai(int n, int q, int i)
{

  if(n <= 1)
    return ((q == 0 && i == 0) ? 1 : 0);
  ll &resp = A[n][q][i];
  if(resp != -1) return resp;

  resp = 0;
  for(int k = 0; k < n; k++){
    int l1 = k;
    int l2 = n - l1 - 1;
    for(int q1 = 0; q1 <= l1*l1; q1++){
      int q2 = q - q1 - (n-1);
      if(q2 < 0) break;
      for(int i1 = 0; i1 <= l1*l1; i1++){
	for(int i2 = 0; i2 <= l2*l2; i2++){
	  int ic = i - i1 - i2 - k;
	  if(ic < 0) break;
	  resp += (vai(l1,q1,i1)*vai(l2,q2,i2)*D[l1][l2][ic])%MOD;
	  resp %= MOD;
	}
      }
    }
  }
  return resp;
}

int main()
{
  int x;
  scanf(" %d %d", &N, &x);

  memset(D, 0, sizeof D);
  memset(A, -1, sizeof A);

  for(int l1 = 0; l1 <= N; l1++)
    for(int l2 = 0; l1+l2 <= N; l2++)
      for(int i = 0; i <= l1*l2; i++){
	ll &at = D[l1][l2][i];
	if(l1 == 0 || l2 == 0 || i == 0)
	  at = 1;
	else{
	  at = D[l1-1][l2][i];
	  if(i >= l1){
	    at += D[l1][l2-1][i - l1];
	    at %= MOD;
	  }
	}
      }
  

  ll r = 0;
  for(int q = 0; q <= N*N; q++)
    for(int i = 0; i+N-1 <= x*q; i++){
      r += vai(N, q, i);
      r %= MOD;
    }
  printf("%lld\n", r);

  return 0;
}
