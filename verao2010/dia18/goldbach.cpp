
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

#define MAX 1000010

char ehp[MAX];
vector<int> primos;

void crivo()
{
  memset(ehp, 1, sizeof ehp);
  for(int i = 3; i*i < MAX; i += 2){
    for(int j = i*i; j < MAX; j += 2*i)
      ehp[j] = 0;
  }
  
  primos.clear();
  for(int i = 3; i < MAX; i += 2)
    if(ehp[i])
      primos.push_back(i);
}

pair<int, int> resolve(int n)
{
  int j = n - 3;
  for(int j = n-3; j >= 0; j -= 2){
    int i = n - j;
    if(ehp[i] && ehp[j])
      return make_pair(i, j);
  }
}

int main()
{
#ifndef LOCAL
  freopen("goldbach.in", "r", stdin);
  freopen("goldbach.out", "w", stdout);
#endif

  crivo();
  int n;
  while(scanf(" %d", &n) && n > 0){
    pair<int, int> p = resolve(n);
    printf("%d = %d + %d\n", n, p.first, p.second);
  }

  return 0;
}

