#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define rep(i, n) for(i = 0; i <= n; i++)
#define repall(x1,x2,x3,x4,x5,x6,n)   rep(x1,n) rep(x2, n-x1) rep(x3, n-x1-x2) rep(x4,n-x1-x2-x3) rep(x5, n-x1-x2-x3-x4) rep(x6, n-x1-x2-x3-x4-x5)
#define repeq(x1,x2,x3,x4,x5,n)   rep(x1,n) rep(x2, n-x1) rep(x3, n-x1-x2) rep(x4,n-x1-x2-x3) rep(x5, n-x1-x2-x3-x4)

int fat[11];
double ******table1;
double ******table2;

double multinom(int *v)
{
  int n = 0;
  for(int i = 0; i < 6; i++) n += v[i];
  double r = fat[n] / pow(6.0, n);
  for(int i = 0; i < 6; i++) r /= fat[v[i]];
  return r;
}


double tabela[10][100];

void resolve(int n, int K)
{
  int x1,x2,x3,x4,x5,x6;
  repall(x1,x2,x3,x4,x5,x6,n){
    table1[x1][x2][x3][x4][x5][x6] = 
      max(max(max(x1, 2*x2), max(3*x3, 4*x4)), max(5*x5, 6*x6));
  }


  int va[6], vb[6], vc[6];

  for(int k = 0; k < K; k++){
    repall(va[0], va[1], va[2], va[3], va[4], va[5], n){

      double &resp = table2[va[0]][va[1]][va[2]][va[3]][va[4]][va[5]];
      resp = 0.0;
      int q = n;
      for(int i = 0; i < 6; i++) q -= va[i];
      
      repeq(vb[0],vb[1],vb[2],vb[3],vb[4], q){
	vb[5] = q;
	for(int i = 0; i < 5; i++) vb[5] -= vb[i];
	double escolha = 0.0;
	for(int msk = 0; msk < (1 << 6); msk++){
	  for(int i = 0; i < 6; i++){
	    vc[i] = va[i];
	    if((1<<i) & msk)
	      vc[i] += vb[i];
	  }
	  escolha =
	    max(escolha, table1[vc[0]][vc[1]][vc[2]][vc[3]][vc[4]][vc[5]]);
	}
	resp += escolha * multinom(vb);
      }
    }
    swap(table1, table2);
    tabela[n-1][k] = table1[0][0][0][0][0][0];
  }
}

double ******inicializa()
{
  double ******t;
  t = (double ******)malloc(11 * sizeof(void *));

  for(int a = 0; a < 11; a++)
    t[a] = (double *****)malloc(11 * sizeof(void *));

  for(int a = 0; a < 11; a++)
    for(int b = 0; b < 11; b++)
      t[a][b] = (double ****)malloc(11 * sizeof(void *));

  for(int a = 0; a < 11; a++)
    for(int b = 0; b < 11; b++)
      for(int c = 0; c < 11; c++)
	t[a][b][c] = (double ***)malloc(11 * sizeof(void *));

  for(int a = 0; a < 11; a++)
    for(int b = 0; b < 11; b++)
      for(int c = 0; c < 11; c++)
	for(int d = 0; d < 11; d++)
	  t[a][b][c][d] = (double **)malloc(11 * sizeof(void *));

  for(int a = 0; a < 11; a++)
    for(int b = 0; b < 11; b++)
      for(int c = 0; c < 11; c++)
	for(int d = 0; d < 11; d++)
	  for(int e = 0; e < 11; e++)
	  t[a][b][c][d][e] = (double *)malloc(11 * sizeof(double));

  return t;
}


int main()
{
  fat[0] = 1;
  for(int i = 1; i < 11; i++)
    fat[i] = i*fat[i-1];

  table1 = inicializa();
  table2 = inicializa();

  for(int n = 1; n <= 10; n++){
    cerr << "Resolvendo n = " << n << "...";
    resolve(n, 100);
    cerr << "done!" << endl;
  }


  cout << "double tabela[10][100] = ";
  cout << '{';
  for(int n = 0; n < 10; n++){
    if(n != 0) cout << ',';
    cout << '{';
    for(int k = 0; k < 100; k++){
      if(k != 0) cout << ',';
      printf("%.16f", tabela[n][k]);
    }
    cout << '}';
  }
  cout << "};";

  return 0;
}
