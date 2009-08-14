#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LIM 50100

vector< pair<int, int> > invest;
int memo[LIM];

int ganha(int n)
{
  int &r = memo[n];
  if(r != -1)
    return r;
  r = 0;
  for(int i = 0; i < invest.size(); i++)
    if(n >= invest[i].first)
      r = max(r, ganha(n-invest[i].first)+invest[i].second);
  return r;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int grana, anos;
    scanf(" %d %d", &grana, &anos);
    int d;
    scanf(" %d", &d);
    invest.clear();
    while(d--){
      int x, y;
      scanf(" %d %d", &x, &y);
      x /= 1000;
      invest.push_back(make_pair(x, y));
    }
    
    memo[0] = 0;
    for(int i = 1; i < LIM; i++)
      memo[i] = -1;

    while(anos--){
      int t = ganha(grana/1000);
      grana += t;
    }
    printf("%d\n", grana);
  }
  return 0;
}
