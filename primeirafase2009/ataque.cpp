#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double pi;

double xc, yc, r;
double ang, angab;

typedef pair<double, double> ponto;

double dist2(ponto a, ponto b)
{
  double dx = a.first - b.first;
  double dy = a.second - b.second;
  return dx*dx+dy*dy;
}

bool ler()
{
  int x, y;
  scanf(" %d %d %lf", &x, &y, &r);
  if(x == y && y == 0 && r < 0.5)
    return false;

  int p, q, a, t;
  scanf(" %d %d %d %d", &p, &q, &a, &t);
  xc = p - x;
  yc = q - y;

  if(a > 180) a -= 360;
  ang = (double)a * pi / 180.0;
  angab = (double)t * pi / 360.0;
  return true;
}

void rodar()
{
  if(yc < -0.5){
    yc = -yc;
    ang = -ang;
  }
  if(xc < -0.5){
    xc = -xc;
    if(ang > -1.0e-9){
      ang = pi - ang;
    }
    else{
      ang = -ang;
      ang = pi - ang;
      ang = -ang;
    }
  }

  if(-0.5 < xc && xc < 0.5){
    xc = yc;
    yc = 0.0;
    ang -= 0.5*pi;
  }

  else if(!(-0.5 < yc && yc < 0.5)){
    ang -=  atan(yc/xc);
    xc = sqrt(xc*xc+yc*yc);
    yc = 0.0;
  }
  ang = abs(ang);
}

double encontra_ang(double alfa)
{
  double teta = pi - alfa;
  ponto p1, p2;
  double b, c, delta;
  double z1, z2;
  b = -2.0 * xc*cos(teta);
  c = xc*xc-r*r;

  //printf("-- %f\n", delta);
  delta = b*b-4.0*c;
  z1 = 0.5*(-b + sqrt(delta));
  z2 = 0.5*(-b - sqrt(delta));


  p1 = p2 = make_pair(cos(alfa), sin(alfa));
  p1.first *= z1; p1.second *= z1;
  p2.first *= z2; p2.second *= z2;
  p1.first += xc; p2.first += xc;


  double d2 = dist2(p1, p2);
  double t = acos(1.0 - 0.5*d2/(r*r));

  if(p2.second < 0.0)
    t = 2.0*pi - t;
  return t;
}


double areaarco(double t)
{
  t *= 0.5;
  return abs(t)*r*r - sin(t)*cos(t)*r*r;
}


double resolve()
{
  double z = sqrt(xc*xc-r*r);
  double cric = acos(-0.5* (r*r-z*z-xc*xc) / (z*xc));
  double resp = pi*r*r;
  ponto a, b;

  if(ang + angab < pi - cric)
    return 0.0;
  if(ang+angab < pi + cric){
    double t = 2.0*pi - encontra_ang(ang+angab);
    resp -= areaarco(t);
  }

  if(ang - angab < pi - cric)
    return resp;
  if(ang - angab > pi + cric)
    return 0.0;

  double t = encontra_ang(ang - angab);
  resp -= areaarco(t);
  return resp;
}

int main()
{
  pi = acos(-1.0);
  while(ler()){
    rodar();
    printf("%.1f\n", resolve());
  }
  return 0;
}
