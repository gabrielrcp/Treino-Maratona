#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

#define MAX 70010

int n;
int resp[MAX];
int arv[5*MAX];

void monta(int x, int e, int d)
{
  int m = (e+d)/2;
  arv[x] = d - e + 1;
  if(e < d){
    monta(2*x+1, e, m);
    monta(2*x+2, m+1, d);
  }
}

int busca(int val)
{
  int x = 0, e = 0, d = n-1;
  while(e < d){
    int f = 2*x+1;
    int m = (e+d)/2;
    if(arv[f] >= val){
      d = m;
    } else{
      val -= arv[f];
      f++;
      e = m + 1;
    }
    x = f;
  }
  return e;
}

void update(int pos)
{
  int x = 0, e = 0, d = n-1;
  while(e < d){
    arv[x]--;
    int m = (e+d)/2;
    int f = 2*x+1;
    if(pos <= m)
      d = m;
    else{
      e = m + 1;
      f++;
    }
    x = f;
  }
  arv[x]--;
}

int main()
{
#ifndef LOCAL
  freopen("antiqs.in", "r", stdin);
  freopen("antiqs.out", "w", stdout);
#endif
  
  scanf(" %d", &n);

  monta(0, 0, n-1);

  for(int i = 0; i < n; i++){
    int m = ((i+n-1) / 2) - i;
    int r = busca(m+1);
    update(r);
    resp[r] = i+1;
  }
  
  for(int i = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d", resp[i]);
  }
  printf("\n");
  
  return 0;
}

