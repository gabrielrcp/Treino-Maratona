#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

struct carta{
  int c, s, t;
};

carta v[100];
carta w[100];

int escolhe(int n, int compra)
{
  int r = -1;
  for(int i = 0; i < n; i++){
    if(w[i].c == -1) continue;
    if(w[i].t > 0) return i;
    if(r == -1){
      r = i;
      continue;
    }
    if(compra > 0 && make_pair(w[i].c, w[i].s) > make_pair(w[r].c, w[r].s)){
      r = i;
      continue;
    }
    if(compra <= 0 && make_pair(w[i].s, w[i].c) > make_pair(w[r].s, w[r].c)){
      r = i;
      continue;
    }
  }
  return r;   
}

int vai(int compra)
{
  for(int i = 0; i < N+M; i++)
    w[i] = v[i];

  int n = N;
  int turnos = 1;
  int r = 0;
  while(turnos > 0){
    int m = escolhe(n, compra);
    if(m == -1) break;
    turnos += w[m].t;
    r += w[m].s;
    compra -= w[m].c;
    n = min(N+M, n+w[m].c);
    w[m].c = -1;
    turnos--;
  }
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &N);
    for(int i = 0; i < N; i++){
      scanf(" %d %d %d", &v[i].c, &v[i].s, &v[i].t);
    }
    scanf(" %d", &M);
    for(int i = N; i < N+M; i++){
      scanf(" %d %d %d", &v[i].c, &v[i].s, &v[i].t);
    }
    int r = -1;
    for(int compra = 0; compra <= M; compra++)
      r = max(r, vai(compra));
    printf("Case #%d: %d\n", h, r);
  } 
  return 0;
}
