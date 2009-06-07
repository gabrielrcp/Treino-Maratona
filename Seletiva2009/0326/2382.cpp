#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define EPS 1.0e-9

struct circ{
  double x, y, r;
};

double R;
int n;
circ v[20];
double pi;

double distancia2(double x0, double x1, double y0, double y1)
{
  return (x0-y0)*(x0-y0) + (x1-y1)*(x1-y1);
}

double distancia(double x0, double x1, double y0, double y1)
{
  return sqrt(distancia2(x0, x1, y0, y1));
}

bool confere(int i)
{
  for(int j = 0; j < n; j++)
    if((1 << j) & i)
      for(int k = j + 1; k < n; k++)
	if((1 << k) & i)
	  if(distancia(v[j].x, v[j].y, v[k].x, v[k].y) < v[j].r + v[k].r)
	    return false;
  return true;
}

double area(int e)
{
  double resp = pi * R * R;
  //printf("--%lf\n", resp);
  for(int i = 0; i < n; i++){
    if((1 << i) & e){
      double r = v[i].r;
      double d2 = distancia2(v[i].x, v[i].y, 0.0, 0.0);
      double d = sqrt(d2);

      resp += pi * r * r;

      double cost = (R*R + d2 - r*r) / (2.0 * R * d);
      double t = acos(cost);
      double sent = sin(t);
      resp -= R * R * t;
      resp += R * R * sent * cost;


      cost = (d2 + r*r - R*R) / (2.0 * r * d);
      t = acos(cost);
      sent = sin(t);
      resp -= r * r * t;
      resp += r * r * sent * cost;


      //printf("--%lf\n", acos((d2 + r*r - R*R) / (2.0 * r * d)));
      //printf("++%lf\n", acos((R*R + d2 - r*r) / (2.0 * R * d)));
    }
  }
  //printf("|%lf|\n", resp);

  return resp;
}

int main()
{
  double x0, y0;
  pi = acos(-1.0);
  while(1){
    if(feof(stdin)) break;
    if(scanf(" %d", &n) != 1) break;
    scanf(" %lf %lf %lf", &x0, &y0, &R);
    for(int i = 0; i < n; i++){
      scanf(" %lf %lf %lf", &(v[i].x), &(v[i].y), &(v[i].r));
      v[i].x -= x0;
      v[i].y -= y0;
      if(distancia(v[i].x, v[i].y, 0.0, 0.0) + v[i].r < R){
	i--; n--;
      }
    }
    /*
    for(int i = 0; i < n; i++)
      printf("%lf %lf %lf\n", v[i].x, v[i].y, v[i].r);
    */
    double resp = pi * R * R;
    for(int i = 1; i < (1 << n); i++){
      if(!confere(i)) continue;
      resp = max(resp, area(i));
    }
    printf("%lf\n", resp);
    //printf("%lf\n", 400.0 * pi / 3.0);
  }
  return 0;
}
