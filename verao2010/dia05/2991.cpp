// errado, nem terminei

#include <cstdio>

#define MAX 10010

double bitx[MAX];
double bity[MAX];

double ang[MAX];

double update(int i, double x, double *tree)
{
  while(i < MAX){
    tree[i] += x;
    i += ((i) & (-i));
  }
}

double sum(int i, double *tree)
{
  double resp = 0.0;
  while(i > 0){
    resp += tree[i];
    i -= ((i)&(-i));
  }
  return resp;
}


int main()
{
  int n, c;
  bool pri = true;
  while(scanf(" %d %d", &n, &c) == 2 && n && c){
    if(!pri)
      printf("\n");
    else
      pri = false;

    for(int i = 0; i < MAX; i++){
      bitx[i] = 0.0;
      bity[i] = 0.0;
      ang[i] = 0.0;
    }
    for(int i = 0; i < n; i++){
      int l;
      scanf(" %d", &l);
      update(n-i, (double)l, bitx);
    }



  }
}
