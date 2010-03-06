#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

pair<double, int> v1[110];
pair<double, int> v2[110];

int main()
{
  int n, m;
  scanf(" %d %d", &n, &m);

  double melhor;
  scanf(" %lf", &melhor);
  v1[0] = make_pair(melhor, 0);
  for(int i = 1; i < n; i++){
    double t;
    scanf(" %lf", &t);
    t += melhor;
    melhor = min(melhor, t);
    v1[i] = make_pair(t, i);
  }
  sort(v1, v1+n);


  scanf(" %lf", &melhor);
  v2[0] = make_pair(melhor, v1[m-1].second);
  for(int i = 1; i < m; i++){
    double t;
    scanf(" %lf", &t);
    t += melhor;
    melhor = min(melhor, t);
    v2[i] = make_pair(t, v1[m-1-i].second);
  }
  sort(v2, v2+m);
  for(int i = 0; i < 3; i++)
    printf("%d\n", v2[i].second+1);

  return 0;
}
