#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100010
typedef long long ll;
#define INF (1<<30)

int left[MAX], right[MAX], down[MAX], up[MAX];
ll soma[MAX], val[MAX];
int n;

ll bit[5*MAX];
int M;


ll get(int p)
{
  ll r = 0;
  while(p > 0){
    r = max(r, bit[p]);
    p -= (p & -p);
  }
  return r;
}

void update(int p, ll x)
{
  while(p < M+10){
    bit[p] = max(bit[p], x);
    p += (p & -p);
  }
}

int main()
{
  freopen("rects.in", "r", stdin);
  freopen("rects.out", "w", stdout);
 
  scanf(" %d", &n);
  vector<int> allY;
  for(int i = 0; i < n; i++){
    scanf(" %d %d %d %d %lld", left+i, down+i, right+i, up+i, val+i);
    allY.push_back(down[i]);
    allY.push_back(up[i]);
  }
  allY.push_back(-INF);
  allY.push_back(INF);

  sort(allY.begin(), allY.end());
  unique(allY.begin(), allY.end());
  M = allY.size();

  for(int i = 0; i < n; i++){
    up[i] = (int)(lower_bound(allY.begin(), allY.end(), up[i]) - allY.begin());
    down[i] = (int)(lower_bound(allY.begin(), allY.end(), down[i]) - allY.begin());
  }

  vector<pair < int, pair<int,int> > > v;
  
  for(int i = 0; i < n; i++){
    v.push_back(make_pair(left[i] , make_pair( 0, i ) ));
    v.push_back(make_pair(right[i] , make_pair( 1, i ) ));
  }
  sort(v.begin(), v.end());

  memset(bit, 0, sizeof bit);
      
  ll resp = 0;
  for(int ii = (int)v.size()-1; ii>= 0; ii--){
    int i = v[ii].second.second;
    if(v[ii].second.first == 0) //left
      update(up[i]+1, soma[i]);
    else{
      soma[i] = get(down[i]) + val[i];
      resp = max(resp, soma[i]);
    //printf("-- %d %lld\n", rect[i].id, rect[i].resp);
    }
  }

  printf("%lld\n", resp);
  int x = -INF, y = INF;
  for(int j = 0; j < (int)v.size(); j++){
    if(v[j].second.first == 0) continue;
    int i = v[j].second.second;
    if(soma[i] == resp && left[i] > x && up[i] < y){
      printf("%d ", i+1);
      resp -= val[i];
      x = right[i];
      y = down[i];
    }
  }
  printf("\n");
  return 0;
}
