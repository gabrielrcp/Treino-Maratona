#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

#define MAX 210
#define EPS (1.0e-9)


struct ponto{
  double x, y;
};

ponto operator+(ponto a, ponto b)
{
  ponto p;
  p.x = a.x+b.x;
  p.y = a.y+b.y;
  return p;
}

ponto operator-(ponto a, ponto b)
{
  ponto p;
  p.x = a.x-b.x;
  p.y = a.y-b.y;
  return p;
}

ponto operator*(ponto p, double a)
{
  p.x *= a;
  p.y *= a;
  return p;
}
ponto operator/(ponto p, double a)
{
  p.x /= a;
  p.y /= a;
  return p;
}

ponto ortog(ponto p)
{
  ponto novo;
  novo.x = p.y;
  novo.y = -p.x;
  return novo;
}

double prod(ponto a, ponto b)
{
  return a.x*b.y - a.y*b.x;
}

char left(ponto a, ponto b)
{
  return ((prod(a, b) > EPS) ? 1 : 0);
}

ponto pts[MAX];
int n;


double dist(ponto a, ponto b)
{
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return dx*dx + dy*dy;
}

bool operator!= (ponto a, ponto b)
{
  double dx = a.x - b.x;
  double dy = a.y - b.y;

  return (!(-EPS < dx  && dx < EPS && -EPS < dy && dy < EPS));
}

ponto interseccao(ponto p1, ponto v1, ponto p2, ponto v2)
{
  double A1 = v1.x;
  double B1 = -v2.x;
  double C1 = p2.x - p1.x;
  double A2 = v1.y;
  double B2 = -v2.y;
  double C2 = p2.y - p1.y;

  double det = A1 * B2 - B1 * A2;
  double t1 = (C1 * B2 - B1 * C2) / det;
  //double t2 = A1 * C2 - C1 * A2 / det;

  ponto p;
  p.x = p1.x + t1*v1.x;
  p.y = p1.y + t1*v1.y;
  return p;
}

void adiciona(list<ponto> &pol, ponto a, ponto b)
{
  ponto meio = (a + b)*0.5;
  ponto vetor = ortog(b - a);

  list<ponto>::iterator it, prox;
  for(it = pol.begin(); it != pol.end(); it++){
    prox = it; prox++;
    if(prox == pol.end()) prox = pol.begin();
    if(left(vetor, *it - meio) != left(vetor, *prox - meio)){
      ponto p = interseccao(meio, vetor, *it, *prox - *it);
      if(p != *prox && p != *it)
	pol.insert(prox, p);
    }
  }

  char ori = left(vetor, a - meio);
  it = pol.begin();
  while(it != pol.end()){
    prox = it; prox++;
    if(left(vetor, *it - meio) != ori)
      pol.erase(it);
    it = prox;
  }
}

void imprime(ponto p)
{
  printf("%f %f\n", p.x, p.y);
}

int main()
{
  freopen("fire.in", "r", stdin);
  freopen("fire.out", "w", stdout);

  list<ponto> pol;
  scanf(" %d", &n);
  while(n--){
    ponto p;
    scanf(" %lf %lf", &p.x, &p.y);
    pol.push_back(p);
  }
  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %lf %lf", &pts[i].x, &pts[i].y);

  ponto resp;
  double melhor = -1.0;

  for(int i = 0; i < n; i++){
    list<ponto> temp = pol;
    //printf("%d\n", (int)temp.size());
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      adiciona(temp, pts[i], pts[j]);
      //printf("%d\n", (int)temp.size());
    }
    //printf("----\n");
    for(list<ponto>::iterator it = temp.begin(); it != temp.end(); it++){
      double t = dist(*it, pts[i]);
      if(t > melhor){
	melhor = t;
	resp = *it;
      }
    } 
  }
  
  printf("%.8f %.8f\n", resp.x, resp.y);
  return 0;
}
