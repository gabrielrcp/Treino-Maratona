#include <cstdio>
#include <map>
#include <algorithm>

#define MAX 1010

using namespace std;

int gdc(int a, int b)
{
  if(a == 0 || b == 0) return 1;
  if(a < b) return gdc(b, a);
  if(a % b == 0) return b;
  return gdc(b, a%b);
}

typedef pair<int, int> frac;
int n;

frac pontos[MAX];
map<frac, int> M;

int atual;

void adiciona(int i, int j)
{
  if(pontos[i].second == pontos[j].second)
    return;
  frac f;

  f.first = pontos[j].first - pontos[i].first;
  f.second = pontos[j].second - pontos[i].second;
  int t = gdc(abs(f.first), abs(f.second));
  f.first /= t;
  f.second /= t;

  if(f.second < 0){
    f.first = -f.first;
    f.second = -f.second;
  }

  map<frac, int>::iterator it = M.find(f);
  if(it == M.end())
    M[f] = 1;
  else{
    if(it->second+1 > atual)
      atual = it->second+1;
    M[f]++;
  }
    
}

int vai(int p)
{
  atual = 0;
  for(int i = 0; i < n; i++)
    if(i != p && pontos[i].second == pontos[p].second)
      atual++;

  M.clear();
  for(int i = 0; i < n; i++)
    adiciona(p, i);

  return atual;
}

int main()
{
  for(int h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      scanf(" %d %d", &pontos[i].first, &pontos[i].second);

    int resp = 0;
    for(int i = 0; i < n; i++)
      resp = max(resp, vai(i));
    resp++;

    if(resp < 4) resp = 0;
    printf("Photo %d: %d points eliminated\n", h, resp);

  }
  return 0;
}
