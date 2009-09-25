#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 10010

int n, l;

pair<int, int> pares[MAX];

int main()
{
  while(scanf(" %d %d", &n, &l) == 2){
    for(int i = 0; i < n; i++)
      scanf(" %d %d", &pares[i].second, &pares[i].first);
 
    int resp = 0;

    if(n > 0 && l > 0){
      sort(pares, pares+n);
      
      set<pair<int, int> > foram;
      
      for(int i = 0; i < n; i++){
	int d = pares[i].first+1;
	int p = pares[i].second;
	if(l*d <= foram.size() && foram.begin()->first < p){
	  resp -= foram.begin()->first;
	  foram.erase(foram.begin());
	}
	if(l*d > foram.size()){
	  resp += p;
	  foram.insert(make_pair(p, i));
	}	
      }
      
    }
    printf("%d\n", resp);
    
  }
  return 0;
}
