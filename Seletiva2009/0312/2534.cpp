#include <cstdio>
#include <cmath>

#define EPS 1.0e-9

using namespace std;

typedef pdd pair<double, double>;


bool igual(double x, double y)
{
  return (-EPS < x - y && x - y < EPS);
}

double prodinterno(pdd u, pdd v)
{
  return u.first * v.first + u.second * v.second;
}

double norma2(pdd v)
{
  return prodinterno(v, v);
}

double normal(pdd v)
{
  return sqrt(norma2(v));
}


// conferir
// orientacao do prod vetorial
bool mesmolado(pdd a, pdd b, pdd c, pdd d)
{
  b.first -= a.first;
  b.second -= a.second;

  c.first -= a.first;
  c.second -= a.second;
 
  d.first -= a.first;
  d.second -== a.second;

  double x = b.first * c.second - b.second * c.first;
  double y = b.first * d.second - b.second * d.first;
  return x * y > 0;
}

//verificar
bool segmentocruza(pdd a, pdd b, pdd c, pdd d)
{
  if(mesmolado(a, b, c, d) || mesmolado(c, d, a, b))
    return false;
  return true;
}

vector<pdd> p1, p2;
vector<bool> caiu;
int n;
double h;



int main()
{
  scanf(" %d %lf", &n, &h);
  p1 = vector<pdd> (n);
  p2 = vector<pdd> (n);
  caiu = vector<bool> (n, false);

  for(int i = 0; i < n; i++){
    double x, y, z, w;
    scanf(" %lf %lf %lf %lf", &x, &y, &z, &w);
    p1[i].first = x;
    p1[i].second = y;
    p2[i].first = z;
    p2[i].second = w;
  }

  vetor.first = p1[0].second - p2[0].second;
  vetor.second = -(p1[0].first - p2[0].first);



  int i = 0;
  caiu[0] = true;
  pdd vetor;

  for(int j = 0; j < n; j++){
    if(caiu[j]) continue;

  }

  return 0;
}
