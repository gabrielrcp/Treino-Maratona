#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define MAX 5010

pii v[2*MAX];

int final(int i)
{
  int s = 1; i++;
  while(s > 0){
    s -= v[i].second;
    i++;
  }
  return i-1;
}

int main()
{
  int p, n;
  for(int h = 1; scanf(" %d %d", &p, &n) && n; h++){
    for(int i = 0; i < n; i++){
      int a, b;
      scanf(" %d %d", &a, &b);
      v[2*i] = make_pair(a, -1);
      v[2*i+1] = make_pair(b, 1);
    }
    sort(v, v+2*n);

    printf("Teste %d\n", h);
    int i = 0;
    while(i < 2*n){
      int j = final(i);
      printf("%d %d\n", v[i].first, v[j].first);
      i = j + 1;
    }
    puts("");
  }
}
