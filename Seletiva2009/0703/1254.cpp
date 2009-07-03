#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define EPS 1.0e-12

double pi;

struct equa{
  double a, b, c;
};


equa acha_coef(double x0, double y0, int d)
{
  double alfa = (double) d / 180.0 * pi;
  double sa = sin(alfa);
  double ca = cos(alfa);
  equa resp;

  if(d != 0 && d != 180){
    double m = cos(alfa) / sin(alfa);
    resp.a = -m;
    resp.b = 1.0;
    resp.c = y0 - m*x0;
    //printf("-- %lf %lf %lf\n", resp.a, resp.b, resp.c);
    return resp;
  }
  resp.a = 1.0;
  resp.b = 0.0;
  resp.c = x0;
  //printf("--- %lf %lf %lf\n", resp.a, resp.b, resp.c);

  return resp;
}

pair<double, double> resolve(equa eq1, equa eq2)
{
  double y = eq1.c*eq2.a - eq2.c*eq1.a;
  y /= eq1.b*eq2.a - eq1.a*eq2.b;
  double x;
  if(-EPS < eq1.a && eq1.a < EPS)
    x = (eq2.c - eq2.b*y) / eq2.a;
  else
    x = (eq1.c - eq1.b*y) / eq1.a;
  return make_pair(x, y);
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  pi = acos(-1.0);

  while(casos--){
    equa eq1, eq2;
    int x, y, d;
    scanf(" %d %d %d", &x, &y, &d);
    eq1 = acha_coef((double)x, (double)y, d);
    scanf(" %d %d %d", &x, &y, &d);
    eq2 = acha_coef((double)x, (double)y, d);

    pair<double, double> resp = resolve(eq1, eq2);

    printf("%.4lf %.4lf\n", resp.first, resp.second);

  }

  return 0;
}
