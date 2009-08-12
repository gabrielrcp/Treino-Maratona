// TLE, olhar a solucao com sort do Joel

#include <cstdio>
#include <map>
#include <algorithm>

#define MAX 1010

using namespace std;

struct frac{
  int num, den;
  bool operator<(const frac &outro) const{
    return (num*outro.den < outro.num*den);
  }
};
int n;

pair<int, int> pontos[MAX];
map<frac, int> M;

int resp;

void adiciona(int i, int j)
{
  frac f;
  if(pontos[i].second == pontos[j].second)
    return;

  f.num = pontos[i].first - pontos[j].first;
  f.den = pontos[i].second - pontos[j].second;

  map<frac, int>::iterator it = M.find(f);
  if(it == M.end()){
    M[f] = 1;
  }
  else{
    resp = max(resp, it->second+1);
    it->second++;
  }
}


void vai(int p)
{
  int linha = 0;
  for(int i = 0; i < n; i++)
    if(i != p && pontos[i].second == pontos[p].second)
      linha++;
  resp = max(resp, linha);

  M.clear();
  for(int i = 0; i < n; i++)
    adiciona(p, i);
}

int main()
{
  for(int h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      scanf(" %d %d", &pontos[i].first, &pontos[i].second);

    resp = 0;
    for(int i = 0; i < n; i++)
      vai(i);
    resp++;

    if(resp < 4) resp = 0;
    printf("Photo %d: %d points eliminated\n", h, resp);

  }
  return 0;
}
