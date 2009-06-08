#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 10010
#define MOD 5000000

int tree[55][MAX];
int n, k;

pair<int, int> v[MAX];
int memo[MAX][55];

void update(int idx, int v, int tr)
{
  while(idx < MAX){
    tree[tr][idx] += v;
    tree[tr][idx] %= MOD;
    idx += idx & (-idx);
  }
}

int soma(int idx, int tr)
{
  int r = 0;
  while(idx > 0){
    r += tree[tr][idx];
    r %= MOD;
    idx -= idx & (-idx);
  }
  return r;
}

int mod(int x)
{
  while(x >= MOD)
    x -= MOD;
  while(x < 0)
    x += MOD;
  return x;
}


int main()
{
  while(scanf(" %d %d", &n, &k) == 2){


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
    printf("%d\n", soma(n, k));
  }
  return 0;
}
