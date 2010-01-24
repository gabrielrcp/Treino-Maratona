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

int grafo[30];
int vertice[60];
char usado[60];
int prox[60];
int nume;
int n;

void add_edge(int i, int j)
{
  int e1 = nume++;
  int e2 = nume++;

  prox[e1] = grafo[i];
  grafo[i] = e1;
  vertice[e1] = j;
 
  prox[e2] = grafo[j];
  grafo[j] = e2;
  vertice[e2] = i;
}

int resp;

void bt(int v, int at)
{
  resp = max(resp, at);
  for(int e = grafo[v]; e != -1; e = prox[e]){
    if(usado[e]) continue;
    usado[e] = usado[e^1] = 1;
    bt(vertice[e], at+1);
    usado[e] = usado[e^1] = 0;
  }
}

int main()
{
#ifndef LOCAL
  freopen("catan.in", "r", stdin);
  freopen("catan.out", "w", stdout);
#endif

  int m;
  while(scanf(" %d %d", &n, &m) && (n > 0 || m > 0)){

    memset(grafo, -1, sizeof grafo);
    memset(usado, 0, sizeof usado);
    nume = 0;
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      add_edge(i, j);
    }

    resp = 0;
    for(int i = 0; i < n; i++)
      bt(i, 0);
    printf("%d\n", resp);

  }

  return 0;
}

