#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 500010

pair< pair<int, int> , int > v[MAX];
int is[MAX], ic[MAX];

int main()
{
  int n;
  set<int> items, sales;

  scanf(" %d", &n);
  for(int i = 0; i < n; i++){
    int ii, si, vv;
    scanf(" %d %d %d", &ii, &si, &vv);
    items.insert(ii);
    sales.insert(si);

    v[i] = make_pair(make_pair(si, ii), vv);
  }

  
  int i = 0;
  set<int>::iterator it;
  for(it = items.begin(); it != items.end(); it++)
    ic[i++] = *it;
  int ni = i;
  
  i = 0;
  for(it = sales.begin(); it != sales.end(); it++)
    is[i++] = *it;
  int ns = i;
  
  sort(v, v+n);
  
  printf("-1");
  for(int j = 0; j < ni; j++)
    printf(" %d", ic[j]);
  printf("\n");
  int k = 0;
  for(i = 0; i < ns; i++){
    printf("%d", is[i]);
    for(int j = 0; j < ni; j++){
      int r = 0;
      while(k < n && v[k].first.first == is[i] && v[k].first.second == ic[j]){
	r += v[k].second;
	k++;
      }
      printf(" %d", r);
    }
    printf("\n");
  }
  
  return 0;
}
