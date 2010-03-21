#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 5010

int pai[MAX];
int conta[MAX];

char s1[50], s2[50];

int find(int i)
{
  return (i == pai[i] ? i : (pai[i] = find(pai[i])));
}

void uniao(int i, int j)
{
  i = find(i);
  j = find(j);
  if(i == j) return;
  if(conta[i] < conta[j]) swap(i, j);
  pai[j] = i;
  conta[i] += conta[j];
  conta[j] = 0;
}

int main()
{
  int n, m;
  while(scanf(" %d %d", &n, &m) && n){
    map<string, int> M;
    for(int i = 0; i < n; i++){
      scanf(" %s", s1);
      M[s1] = i;
      pai[i] = i;
      conta[i] = 1;
    }
    while(m--){
      scanf(" %s %s", s1, s2);
      int i = M[s1];
      int j = M[s2];
      uniao(i, j);
    }
    int r = 0;
    for(int i = 0; i < n; i++)
      r = max(r, conta[i]);
    printf("%d\n", r);
  }
  return 0;
}
