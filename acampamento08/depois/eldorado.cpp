#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 110

long long tree[MAX][MAX];

pair<int, int> v[MAX];
long long memo[MAX][55];

void update(int idx, long long v, int tr)
{
  while(idx < MAX){
    tree[tr][idx] += v;
    idx += idx & (-idx);
  }
}

long long soma(int idx, int tr)
{
  long long r = 0;
  while(idx > 0){
    r += tree[tr][idx];
    idx -= idx & (-idx);
  }
  return r;
}


int main()
{
  while(1){
    int n, k;
    scanf(" %d %d", &n, &k);
    if(n == k && k == 0)
      break;

    for(int i = 0; i < n; i++){
      int x;
      scanf(" %d", &x);
      v[i].first = x;
      v[i].second = n - i;
    }
    sort(v, v+n);
    memset(tree, 0, sizeof(tree));


    for(int l = n-1; l >= 0; l--){
      for(int j = k; j > 0; j--){
	int i = v[l].second;
	if(j == 1)
	  memo[i][j] = 1;
	else
	  memo[i][j] = soma(i-1, j-1);
	update(i, memo[i][j], j);
      }
    }
    /*
    for(int i = 0; i < n; i++)
      printf("%d ", v[i].first);
    printf("\n");
    
    for(int i = 0; i < n; i++)
      printf("%d ", v[i].second);
    printf("\n");
    
    for(int j = 1; j <= k; j++){
      for(int l = 0; l < n; l++){
	int i = v[l].second;
	printf("%d ", memo[i][j]);
      }
      printf("\n");
    }
    */
    printf("%lld\n", soma(n, k));
  }
  return 0;
}
