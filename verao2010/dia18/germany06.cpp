
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

string nomes[16];
double prob[16][16];
char buf[100];

struct node{
  double prob[16];
  node *f1, *f2;
};

node _nos[1000];
int contano;

void resolve(node *arv)
{
  if(arv->f1 == NULL || arv->f2 == NULL)
    return;

  resolve(arv->f1);
  resolve(arv->f2);

  double *res = arv->prob;

  for(int i = 0; i < 16; i++)
    res[i] = 0.0;
  
  for(int i = 0; i < 16; i++)
    for(int j = 0; j < 16; j++)
      res[i] += arv->f1->prob[i] * arv->f2->prob[j] * prob[i][j];

  for(int i = 0; i < 16; i++)
    for(int j = 0; j < 16; j++)
      res[i] += arv->f2->prob[i] * arv->f1->prob[j] * prob[i][j];
  /*
  for(int i = 0; i < 16; i++)
    printf("%.2f ", res[i]);
  printf("\n");
  */
}

node *monta(int i, int j)
{
  //printf("%d %d\n", i, j);
  node *arv = &_nos[contano++];
  arv->f1 = arv->f2 = NULL;

  if(i == j){
    for(int k = 0; k < 16; k++)
      arv->prob[k] = 0.0;
    arv->prob[i] = 1.0;
    return arv;
  }

  int m = (i+j)/2;
  arv->f1 = monta(i, m);
  arv->f2 = monta(m+1, j);
  return arv;
}



int main()
{
#ifndef LOCAL
  freopen("germany06.in", "r", stdin);
  freopen("germany06.out", "w", stdout);
#endif

  for(int i = 0; i < 16; i++){
    scanf(" %s", buf);
    nomes[i] = buf;
  }
  
  for(int i = 0; i < 16; i++)
    for(int j = 0; j < 16; j++){
      int x;
      scanf(" %d", &x);
      prob[i][j] = (double)x / 100.0;
    }
  /*
  for(int i = 0; i < 16; i++){
    for(int j = 0; j < 16; j++)
      printf("%.2f ", prob[i][j]);
    printf("\n");
  }
  */

  contano = 0;
  node *arv = monta(0, 15);
  resolve(arv);

  for(int i = 0; i < 16; i++)
    while(nomes[i].size() < 10)
      nomes[i] = nomes[i] + " ";

  for(int i = 0; i < 16; i++)
    printf("%s p=%.2f%%\n", nomes[i].c_str(), 100.0 * arv->prob[i]);
       

  return 0;
}

