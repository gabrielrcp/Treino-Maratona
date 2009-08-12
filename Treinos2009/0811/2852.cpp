#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct ponto{
  double x, y, z;
};

double pi;
ponto a, b;
ponto va, vb;


inline double distancia(ponto u, ponto v)
{
  return (u.x-v.x)*(u.x-v.x) + 
    (u.y-v.y)*(u.y-v.y) + 
    (u.z-v.z)*(u.z-v.z);
}

inline ponto somamult(ponto x, ponto v, double m)
{
  ponto ret;
  ret.x = x.x + m*v.x;
  ret.y = x.y + m*v.y;
  ret.z = x.z + m*v.z;
  return ret;
}

ponto vai(double mult)
{
  ponto at = somamult(a, va, mult);

  double e = 0.0, d = 1.0e20;
  for(int conta = 0; conta < 200; conta++){
    double m1 = (2.0*e+d)/3.0;
    double m2 = (e+2.0*d)/3.0;

    double t1 = distancia(at, somamult(b, vb, m1));
    double t2 = distancia(at, somamult(b, vb, m2));

    if(t2 > t1)
      d = m2;
    else
      e = m1;
  }
  return somamult(b, vb, e);
}


double resolve()
{
  double oa, ob;

  double e = 0.0, d = 1.0e20;
  for(int conta = 0; conta < 200; conta++){
    double m1 = (2.0*e+d)/3.0;
    double m2 = (e+2.0*d)/3.0;

    double t1 = distancia(somamult(a, va, m1), vai(m1));
    double t2 = distancia(somamult(a, va, m2), vai(m2));

    if(t2 > t1)
      d = m2;
    else
      e = m1;
  }

  oa = a.z + e * va.z;
  ob = vai(e).z;
  return 0.5*(oa+ob);
}


int main()
{
  int n;

  scanf(" %d %lf %lf", &n, &a.z, &b.z);
  a.x = a.y = 0.0;
  b.x = 100.0;
  b.y = 0.0;
  pi = acos(-1.0);

  for(int h = 1; h <= n; h++){
    double alfa, beta, gama, delta;
    scanf(" %lf %lf %lf %lf", &alfa, &beta, &gama, &delta);
    alfa *= pi / 180.0;
    beta *= pi / 180.0;
    gama *= pi / 180.0;
    delta *= pi / 180.0;

    va.x = cos(alfa)*cos(gama);
    va.y = cos(alfa)*sin(gama);
    va.z = sin(alfa);

    vb.x = cos(beta)*cos(delta);
    vb.y = cos(beta)*sin(delta);
    vb.z = sin(beta);

    double resp = resolve();
    printf("%d: %.0f\n", h, resp);
  }

  return 0;
}
