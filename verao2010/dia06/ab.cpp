#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;


vector<int> vai(vector<int> v)
{
  vector<int> w;
  for(int i = 1; i < (int)v.size(); i++){
    w.push_back(v[i] - v[i-1]);
  }
  return w;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    vector<int> v;
    while(n--){
      int x;
      scanf(" %d", &x);
      v.push_back(x);
    }
    scanf(" %d", &n);
    while(n--)
      v = vai(v);
    printf("%u\n", v.size());
    for(int i = 0; i < n; i++)
      printf("%d\n", v[i]);	   
  }
  return 0;
}

