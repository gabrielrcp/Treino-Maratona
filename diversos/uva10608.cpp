#include <cstdio>
#include <vector>
#include <set>

using namespace std;

//#define forit(it, M) for(typeof(M.begin()) it = (M).begin(); it != (M).end(); (it)++)

int conta(int i, vector < set <int> > &G, vector <bool> &v)
{
  if(v[i])
    return 0;
  int r = 1;
  v[i] = true;
  for(set<int>::iterator it = G[i].begin(); it != G[i].end(); it++)
    r += conta(*it, G, v);
  return r;
}

int main()
{
  int casos;
  int n, m;
  int i, j;

  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &n, &m);
    vector < set<int> > G (n);
    while(m--){
      scanf(" %d %d", &i, &j);
      i--; j--;
      G[i].insert(j);
      G[j].insert(i);
    }
    int a;
    m = 0;
    vector<bool> v (n, false);
    for(int i = 0; i < n; i++){
      a = conta(i, G, v);
      if(a > m)
	m = a;
    }
    printf("%d\n", m);
  }
  return 0;
}
