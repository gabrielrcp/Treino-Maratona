/*
 * UVA 10245
 * The Closest Pair Problem
 * http://acm.uva.es/p/v102/10245.html
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_proble
 * Accepted
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

#define MAX (10010)
#define INF (1.0e8)

typedef pair<double, double> ponto;

ponto v[MAX], w[MAX];

inline double quad(double x)
{
  return x*x;
}

inline double dist(ponto a, ponto b)
{
  return quad(a.first - b.first) + quad(a.second-b.second);
}


void uniao(int l, int r, int m)
{
  int i = l, j = m, k = l;
  while(i < m && j < r){
    if(v[i].second <= v[j].second)
      w[k] = v[i++];
    else
      w[k] = v[j++];
    k++;
  }
  while(i < m){
    w[k] = v[i++];
    k++;
  }
  while(j < r){
    w[k] = v[j++];
    k++;
  }
  for(k = l; k < r; k++)
    v[k] = w[k];
}

double vai(int l, int r)
{
  if(r - l <= 1){
    return INF;
  }
  int m = (r+l)/2;
  double x = v[m].first;

  double d = vai(l, m);
  d = min(d, vai(m, r));
  uniao(l, r, m);

  int M = 0;
  for(int i = l; i < r; i++){
    if(quad(v[i].first - x) < d)
      w[M++] = v[i];
  }
  for(int  i = 0; i < M; i++){
    for(int j = i+1; j < M && quad(w[j].second - w[i].second) < d; j++){
      d = min(d, dist(w[i], w[j]));
      assert(j-i <= 8);
    }
  }
  return d;
}

int main()
{
  int N;
  while(scanf(" %d", &N) == 1){
    if(N == 0) break;
    
    for(int i = 0; i < N; i++){
      cin >> v[i].first;
      cin >> v[i].second;
    }
    sort(v, v+N);

  
    double d = sqrt(vai(0, N));
    if(d-10000.0 > -1.0e-9)
      printf("INFINITY\n");
    else
      printf("%.4lf\n", d);
  }
  return 0;
}
