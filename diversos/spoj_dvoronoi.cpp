#include <cstdio>
#include <cmath>

struct ponto{
  double x, y, z;
};

double norma(ponto p)
{
  return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

ponto prod_vet(ponto a, ponto b)
{
  ponto p;
  p.x = a.y*b.z - a.z*b.y;
  p.y = a.z*b.x - a.x*b.z;
  p.z = a.x*b.y - a.y*b.x;
  return p;
}

double prod_inter(ponto a, ponto b)
{
  return a.x*b.x + a.y*b.y + a.z*b.z;
}

ponto ler(ponto a)
{
  ponto p;
  scanf(" %lf %lf %lf", &p.x, &p.y, &p.z);
  p.x -= a.x;
  p.y -= a.y;
  p.z -= a.z;
  return p;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    ponto a = ler((ponto){0.0,0.0,0.0});
    ponto b = ler(a);
    ponto c = ler(a);
    ponto d = ler(a);

    ponto v = prod_vet(b, c);
    double base = norma(v);
    double h;
    if(base > 1.0e-9)
      h = prod_inter(d, v) / base;
    else
      h = 0;
    if(h < 0.0) h = -h;

    printf("%.6f\n", base*h/6.0); 
  }
  return 0;
}
