#include <cstdio>

int n, m;

int v[20][20];

inline int posicao(int i, int j)
{
  return i * m + j;
}
/*
int vizinhos(int i, int j, int x)
{
  int conta = 0;
  for(int k = i - 1; k <= i+1; k++)
    for(int l = j - 1; l <= j+1; l++){
      int a = k, b = l;
      if(a < 0) a = n-1; if(a >= n)  a = 0;
      if(b < 0) b = m-1; if(b >= m)  b = 0;
      if((a!=i || b!=j) && (x & (1 << posicao(a, b))))
	conta++;
    }
  return conta;
}
*/
int proximo(int x)
{
  int r = x;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      v[i][j] = 0;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      if(x & (1 << posicao(i, j))){
	for(int k = i - 1; k <= i+1; k++)
	  for(int l = j - 1; l <= j+1; l++){
	    int a = k, b = l;
	    if(a < 0) a = n-1; if(a >= n)  a = 0;
	    if(b < 0) b = m-1; if(b >= m)  b = 0;
	    if(k!=i || l!=j)
	      v[a][b]++;
	  }
      }
    }


  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      int nv = v[i][j];
      int k = posicao(i, j);
      if(nv <= 1 || nv >= 4)
	r = (r & (~(1 << k)));
      else if(nv == 3)
	r = (r | (1 << k));
    }

  return r;
}

int main()
{

  for(int h = 1; ; h++){
    scanf(" %d %d", &n, &m);
    if(n == 0 && m == 0)
      break;

    int obj = 0;
    int k;
    scanf(" %d", &k);
    while(k--){
      int i, j;
      scanf(" %d %d", &i, &j);
      obj |= (1 << posicao(i, j));
    }
    
    int conta = 0;
    int lim = (1 << (n*m));
    for(int x = 0; x < lim; x++)
      if(proximo(x) == obj)
	conta++;

    printf("Case %d: ", h);
    if(conta == 0)
      printf("Garden of Eden.\n");
    else
      printf("%d possible ancestors.\n", conta);
  }
return 0;
}
