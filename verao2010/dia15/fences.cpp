#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 155

struct ponto{
  int x, y;
  bool operator<(const ponto &p) const{
    if(x == p.x)
      return (y < p.y);
    return (x < p.x);
  }
  bool operator==(const ponto &p) const{
    return (x == p.x && y == p.y);
  }
};

ponto P[MAX];
int n;

char lado[MAX];


bool left(ponto p1, ponto p2, ponto p3)
{
  int x1 = p2.x - p1.x;
  int y1 = p2.y - p1.y;
  int x2 = p3.x - p1.x;
  int y2 = p3.y - p1.y;
  return ((x1*y2 - x2*y1) > 0);
}

char left(int i, int j, int k)
{
  return (left(P[i], P[j], P[k]) ? 1 : 0);
}

int prod(ponto p1, ponto p2, ponto p3)
{
  int x1 = p2.x - p1.x;
  int y1 = p2.y - p1.y;
  int x2 = p3.x - p1.x;
  int y2 = p3.y - p1.y;
  return x1*y2 - x2*y1;
}

ponto pp[MAX];
int np;
ponto pivo;
ponto pilha[MAX];
int topo;

bool compara(const ponto &p1, const ponto &p2)
{
  if(p1 == pivo)
    return true;
  if(p2 == pivo)
    return false;
  return left(pivo, p1, p2);
}

int fecho()
{
  if(np <= 2) return false;
  pivo = pp[0];
  for(int i = 1; i < np; i++)
    pivo = min(pivo, pp[i]);
  
  sort(pp, pp+np, compara);

  topo = 0;
  pilha[topo++] = pp[0];
  pilha[topo++] = pp[1];
  for(int i = 2; i < np; i++){
    while(topo > 1 && (!left(pilha[topo-2], pilha[topo-1], pp[i])))
      topo--;
    pilha[topo++] = pp[i];
  }

  int a = 0;
  for(int i = 0; i+1 < np; i++)
    a += prod(pp[0], pp[i], pp[i+1]);
  return abs(a);
}

int resolve()
{
  int resp = 0;
  np = 0;
  for(int i = 0; i < n; i++)
    if(lado[i])
      pp[np++] = P[i];
  resp += fecho();

  np = 0;
  for(int i = 0; i < n; i++)
    if(!lado[i])
      pp[np++] = P[i];
  resp += fecho();

  return resp;
}

int main()
{
  freopen("fences.in", "r", stdin);
  freopen("fences.out", "w", stdout);

  for(int h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0) break;

    for(int i = 0; i < n; i++)
      scanf(" %d %d", &P[i].x, &P[i].y);

    int resp = (1<<30);
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++){
	memset(lado, 0, n*sizeof(char));
	for(int k = 0; k < n; k++)
	  lado[k] = left(i, j, k);
	resp = min(resp, resolve());
      }
    
    printf("Farm %d: %d.%d\n", h, resp/2, ((resp&1) ? 5 : 0));
  }
  return 0;
}
