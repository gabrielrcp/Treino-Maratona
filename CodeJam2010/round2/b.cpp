#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Jogo{
  int custo;
  int ind;
  ll resp[20];
  Jogo *e, *d;
};

Jogo _jogos[5000];
int numno;

int M[2000];
int P;

Jogo *novo()
{
  Jogo *nv = &_jogos[numno++];
  nv->e = nv->d = NULL;
  nv->custo = 0;
  nv->ind = -1;
  memset(nv->resp, -1, sizeof (nv->resp));
  return nv;
}

Jogo *monta()
{
  numno = 0;
  queue<Jogo *> Q;
  for(int i = 0; i < (1<<P); i++){
    Jogo *nv = novo();
    nv->ind = i;
    Q.push(nv);
  }

  while(!Q.empty()){
    Jogo *e, *d, *p;
    e = Q.front(); Q.pop();
    if(Q.empty()) return e;
    d = Q.front(); Q.pop();
    p = novo();
    p->e = e;
    p->d = d;

    scanf(" %d", &(p->custo));
    Q.push(p);
  }
}

#define INF (1LL<<60)

ll vai(Jogo *arv, int cp)
{
  ll &resp = arv->resp[cp];
  if(resp != -1)
    return resp;
  resp = INF;

  if(arv->e == NULL){
    if(M[arv->ind] <= cp)
      resp = 0;
    return resp;
  }

  resp = min(resp, min(arv->custo + vai(arv->e, cp+1) + vai(arv->d, cp+1),
		       vai(arv->e, cp) + vai(arv->d, cp)));
  return resp;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &P);
    for(int i = 0; i < (1<<P); i++){
      scanf(" %d", M+i);
      M[i] = P - M[i];
    }

    Jogo *arv = monta();
    printf("Case #%d: %lld\n", h, vai(arv, 0));
  }
  return 0;
}
