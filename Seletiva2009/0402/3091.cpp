#include <cstdio>
#include <vector>

using namespace std;

vector<pair <int,int> > v;

inline int resp(int n)
{
  return (2*n+1) / 3;
}

void resolve(int n)
{
  v.clear();
  int r = resp(n);
  int j = 1;

  for(int i = n - r + 1; i <= n; i++){
    v.push_back(make_pair(i, j));
    j += 2;
    if(j > i+1)
      j = 2;
  }
}

void imprime(int h, int n)
{

  printf("%d %d %d", h, n, v.size());
  for(int i = 0; i < v.size(); i++){
    if(i % 8 == 0) printf("\n");
    else printf(" ");
    printf("[%d,%d]", v[i].first, v[i].second);
  }
  printf("\n\n");
}

int main()
{
  int n;
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    resolve(n);
    imprime(h, n);
  }
  return 0;
}
