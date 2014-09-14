/*
 * Primeira fase da maratona 2014
 * Problema: teletransporte
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4656
 * Resposta: AC
 */

#include <cstdio>
#include <vector>

using namespace std;

#define MOD (10000)

typedef vector< vector<int> > matrix;

matrix mult(matrix A, matrix B)
{
  int n = (int) A.size();
  matrix C (n, vector<int> (n, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
	C[i][j] += A[i][k] * B[k][j];
	C[i][j] %= MOD;
      }
    }
  }
  return C;
}

matrix identidade(int N)
{
  matrix A (N, vector<int> (N, 0));
  for(int i = 0; i < N; i++)
    A[i][i] = 1;
  return A;
}

matrix potencia(matrix A, int p)
{
  if(p == 0)
    return identidade((int)A.size());
  if(p == 1)
    return A;
  matrix B = potencia(A, p/2);
  B = mult(B, B);
  if(p % 2 == 1)
    B = mult(B, A);
  return B;
}


int main()
{
  int N, L;
  while(scanf(" %d %d", &N, &L) == 2){
    int S, T;
    scanf(" %d %d", &S, &T);
    matrix mat (N, vector<int> (N, 0));
    for(int i = 0; i < N; i++){
      for(int j = 0; j < 4; j++){
	int k;
	scanf(" %d", &k);
	mat[i][k-1]++;
      }
    }

    matrix r = potencia(mat, L);
    printf("%d\n", r[S-1][T-1]);
  }
  return 0;
}
