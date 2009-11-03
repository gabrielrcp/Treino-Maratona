#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX 1010

pair<int, int> pts[MAX];
int n;
ll d[MAX];

int main()
{
  while(scanf(" %d", &n) && n){
    for(int i = 0; i < n; i++)
      scanf(" %d %d", &pts[i].first, &pts[i].second);

    int resp = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	ll dx = pts[j].first - pts[i].first;
	ll dy = pts[j].second - pts[i].second;
	d[j] = dx*dx + dy*dy;
      }
      sort(d, d+n);
      int j = 1;
      while(j < n){
	int k = j + 1;
	while(k < n && d[k] == d[j])
	  k++;
	resp += (k - j) * (k-j-1) / 2;
	j = k;
      }
    }
    printf("%d\n", resp);
  }
  return 0;
}
