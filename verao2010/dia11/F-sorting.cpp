#include <cstdio>
#include <cstring>

typedef long long ll;

int A[32][32*16][32*16];
int D[32][32][32*32];
int S[32*32];

#define MOD (1234567LL)

inline int lim(int n)
{
  return n * (n-1)/2;
}

int main()
{

  int N = 31;

  for(int l1 = 0; l1 <= N; l1++)
    for(int l2 = 0; l2 <= N; l2++)
      for(int i = 0; i <= l1*l2; i++){
	int &at = D[l1][l2][i];
	if(i == 0)// || l1 == 0 || l2 == 0)
	  at = 1;
	else if(l1 == 0 || l2 == 0)
	  at = 0;
	else{
	  at = D[l1-1][l2][i];
	  if(l1 <= i)
	    at += D[l1][l2-1][i-l1];
	  at %= MOD;
	}
      }

  memset(A, 0, sizeof A);
  A[0][0][0] = A[1][0][0] = 1;
  for(int n = 2; n <= N; n++){
    fprintf(stderr, "Resolvendo n = %d... ", n);
    for(int k = 0; k < n; k++){
      int l1 = k;
      int l2 = n-k-1;
      for(int q1 = 0; q1 <= lim(l1); q1++){
	for(int q2 = 0; q2 <= lim(l2); q2++){
	  int q = q1 + q2 + n-1;

	  memset(S, 0, sizeof S);
	  for(int i1 = 0; i1 <= lim(l1); i1++)
	    for(int i2 = 0; i2 <= lim(l2); i2++)
	      S[i1+i2] = (((ll)S[i1+i2]+((ll)A[l1][q1][i1]*A[l2][q2][i2]))%MOD);
	  
	  for(int s = 0; s <= lim(l1) + lim(l2); s++){
	    for(int ic = 0; ic <= l1*l2; ic++){
	      int i = s+ic+k;
	      int &at = A[n][q][i];
	      at = (((ll)at + (ll)S[s] * D[l1][l2][ic])%MOD);
	    }
	  }
	}
      }
    }
    fprintf(stderr, "done!\n");
  }



  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n, x;
    scanf(" %d %d", &n, &x);
    int r = 0;
    for(int q = 0; q <= lim(n); q++){
      for(int i = 0; i+n-1 <= q*x && i <= lim(n); i++){
	r += A[n][q][i];
	r %= MOD;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
