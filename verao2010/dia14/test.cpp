#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);

  int n, m;
  scanf(" %d %d", &n, &m);

  for(int i = 1; i <= n && m > 0; i++){
    for(int j = i+1; j <= n && m > 0; j++){
      printf("%d %d %d\n", i, j, j - i - 1);
      m--;
    }
  }
  return 0;
}
