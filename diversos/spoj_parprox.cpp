#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ponto;

ponto P[1010];
int n;

ll dist2(int i, int j)
{
  ll dx = P[i].first - P[j].first;
  ll dy = P[i].second - P[j].second;
  return dx*dx + dy*dy;
}

int main()
{
  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %d %d", &P[i].first, &P[i].second);

  ll melhor = (1LL << 60);

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      ll t = dist2(i, j);
      if(t < melhor)
	melhor = t;
    }
  }

  printf("%.3f\n", sqrt((double)melhor));
  return 0;
}
