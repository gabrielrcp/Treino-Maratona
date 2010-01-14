#include <cstdio>
#include <cstring>

#define MOD (1234567LL)

typedef long long ll;

//mudar depois
int D[32][32][32*16];
int A[32][32*16][32*16];
int N;

int S[32*32];

int lim(int l)
{
  return l*l/2;
}

int main()
{

  int N = 31; //limite
  memset(D, 0, sizeof D);
  memset(A, 0, sizeof A);

  for(int l1 = 0; l1 <= N; l1++)
    for(int l2 = 0; l1+l2 <= N; l2++)
      for(int i = 0; i <= l1*l2; i++){
	int &at = D[l1][l2][i];
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


  A[0][0][0] = A[1][0][0] = 1;
  for(int n = 2; n <= N; n++){
    printf("Processando n = %d...", n);
    fflush(stdout);
    for(int k = 0; k < n; k++){
      int l1 = k;
      int l2 = n - l1 - 1;
      for(int q1 = 0; q1 <= lim(l1); q1++){
	for(int q2 = 0; q2 <= lim(l2); q2++){
	  int q = q1 + q2 + (n-1);
	  
	  memset(S, 0, sizeof S);
	  for(int i1 = 0; i1 <= lim(l1); i1++){
	    for(int i2 = 0; i2 <= lim(l2); i2++){
	      S[i1+i2] += ((ll)A[l1][q1][i1] * A[l2][q2][i2])%MOD;
	      S[i1+i2] %= MOD;
	    }
	  }
	  for(int ic = 0; ic <= l1*l2; ic++){
	    for(int s = 0; s <= lim(l1)+lim(l2); s++){
	      int i = s+ic+k;
	      int &resp = A[n][q][i];
	      resp += ((ll)S[s]*D[l1][l2][ic])%MOD;
	      resp %= MOD;
	    }
	  }
	}
      }
    }
    printf("done!\n");
  }
  
  char base[20] = "-sorting.";
  for(int i = 0; i <= 9; i++){
    char ent[20], sai[20];
    sprintf(ent, "%d%sin", i, base);
    sprintf(sai, "%d%sout", i, base);
    FILE *fin = fopen(ent, "r");
    FILE *fout = fopen(sai, "w");

    int n, x;
    fscanf(fin, " %d %d", &n, &x);
    ll r = 0;
    for(int q = 0; q <= lim(n); q++)
      for(int i = 0; i+n-1 <= x*q && i <= lim(n); i++){
	r += A[n][q][i];
	r %= MOD;
      }
    fprintf(fout, "%lld\n", r);
    fclose(fin);
    fclose(fout);
  }
  return 0;
}
