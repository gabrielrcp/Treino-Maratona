#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 5010
int n, a, b, p;

int bit[MAX];
char fora[MAX];

void update(int p, int v)
{
  p++;
  while(p < MAX){
    bit[p] += v;
    p += (p & -p);
  }
}

int get(int p)
{
  int r = 0;
  p++;
  while(p > 0){
    r += bit[p];
    p -= (p & -p);
  }
  return r; 
}

int busca(int c)
{
  int e = 0, d = MAX - 5;
  int r = d;
  while(e <= d){
    int m = (e+d)/2;
    int t = get(m);
    if(t >= c){
      r = m;
      d = m - 1;
    } else{
      e = m + 1;
    }
  }
  return r;
}

void elimina(int c)
{
  int i = busca(c);
  update(i, -1);
  fora[i] = 1;
}

int main()
{
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  while(1){  
    scanf(" %d %d %d %d", &n, &a, &b, &p);
    if(n == a && a == b && b == p && p == 0)
      break;
    memset(fora, 0, sizeof fora);
    memset(bit, 0, sizeof bit);
    for(int i = 0; i < n; i++)
      update(i, 1);
    
    for(int i = 1; i < n; i++){
      int c = 1 + ((a*i+b)%p);
      c %= (n - i + 1);
      if(c == 0)
	c = (n-i+1);
      elimina(c);
    }
    int r = 0;
    while(fora[r])
      r++;
    printf("The winner is %d.\n", r+1);
  }
  return 0;
}
