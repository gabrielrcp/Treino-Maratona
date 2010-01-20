#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 5010
int n, a, b, p;

int arv[5*MAX];


void monta(int x, int e, int d)
{
  arv[x] = d - e + 1;
  if(e == d)
    return;
  int m = (e+d)/2;
  monta(2*x+1, e, m);
  monta(2*x+2, m+1, d);
}

int busca(int x, int e, int d, int c)
{
  while(e < d){
    x = 2*x+1;
    int m = (e+d)/2;
    if(arv[x] < c){
      c -= arv[x];
      x++;
      e = m+1;
    } else{
      d = m;
    }
  }
  return e;
}

void update(int x, int e, int d, int p)
{
  while(e < d){
    arv[x]--;
    int m = (e+d)/2;
    x = 2*x+1;
    if(p <= m){
      d = m;
    } else{
      e = m+1;
      x++;
    }
  }
  arv[x]--;
}

int main()
{
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  while(1){  
    scanf(" %d %d %d %d", &n, &a, &b, &p);
    if(n == a && a == b && b == p && p == 0)
      break;

    monta(0, 0, n-1);
    
    for(int i = 1; i < n; i++){
      int c = 1 + ((a*i+b)%p);
      c %= (n - i + 1);
      if(c == 0)
	c = (n-i+1);
      update(0, 0, n-1, busca(0, 0, n-1, c));
    }
    printf("The winner is %d.\n", busca(0, 0, n-1, 1)+1);
  }
  return 0;
}
