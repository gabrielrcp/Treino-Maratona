#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

pair<int, string> ler()
{
  char buf[50];
  scanf(" %s", buf);
  int mi = 100000;
  int ma = -100000;

  int s = 0;
  for(int i = 0; i < 12; i++){
    int x;
    scanf(" %d", &x);
    s += x;
    mi = min(mi, x);
    ma = max(ma, x);
  }
  s -= mi + ma;
  return make_pair(-s, buf);
}

pair<int, string> v[1010];
int pos[1010];

int main()
{
  int n;
  for(int h = 1; scanf(" %d", &n) && n; h++){
    for(int i = 0; i < n; i++)
      v[i] = ler();

    sort(v, v+n);

    printf("Teste %d\n", h);
    pos[0] = 1;
    for(int i = 1; i < n; i++)
      pos[i] = ((v[i].first != v[i-1].first) ? i+1 : pos[i-1]);
    for(int i = 0; i < n; i++)
      printf("%d %d %s\n", pos[i], -v[i].first, v[i].second.c_str());
    puts("");
  
  }
  return 0;
}
