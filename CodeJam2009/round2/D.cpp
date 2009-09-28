#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 50
#define EPS (1.0e-7)

int n;
int x[MAX];
int y[MAX];
int r[MAX];

vector<long long> msc;


double dist(int i, int j)
{
  int dx = x[i] - x[j];
  int dy = y[i] - y[j];
  return sqrt((double)dx*dx+dy*dy);
}

double dist(double x1, double y1, double x2, double y2)
{
  double dx = x1-x2;
  double dy = y1-y2;
  return sqrt(dx*dx+dy*dy);
}

long long mascara(double cx, double cy, double R)
{
  long long resp = 0;
  for(int i = 0; i < n; i++){
    double d = dist(cx, cy, x[i], y[i]);
    if(d <= R - r[i] + EPS)
      resp |= (1LL << i);
  }
  return resp;
}

bool cobre(double R)
{
  msc.clear();

  for(int i = 0; i < n; i++){
    
    msc.push_back(mascara(x[i], y[i], R));
    for(int j = i+1; j < n; j++){
      double w = R - r[i];
      double z = R - r[j];
      double d = dist(i, j);

      
      if(d > w+z+EPS)
	continue;
      

      double cst = (d*d+w*w-z*z)/(2.0*d*w);
      double t = acos(cst);

      double alfa = atan2(y[j]-y[i], x[j]-x[i]);

      double cx, cy;

      cx = x[i] + w*cos(alfa+t);
      cy = y[i] + w*sin(alfa+t);
      msc.push_back(mascara(cx, cy, R));

      //printf("%d %d %f %f\n", i, j, cx, cy);


      cx = x[i] + w*cos(alfa-t);
      cy = y[i] + w*sin(alfa-t);
      msc.push_back(mascara(cx, cy, R));
      //printf("%d %d %f %f\n", i, j, cx, cy);
    }
  }

  long long obj = ((1LL << n) - 1LL);

  for(int i = 0; i < msc.size(); i++){
    if(msc[i] == obj) return true;
    for(int j = i+1; j < msc.size(); j++){
      if((msc[i] | msc[j]) == obj)
	return true;
    }
  }
  return false;
}


double resolve()
{
  double e = 0.0, d = 1000.0;
  for(int it = 0; it < 50; it++){
    double m = 0.5*(e+d);
    if(cobre(m))
      d = m;
    else
      e = m;
  }
  return 0.5*(e+d);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d %d %d", x+i, y+i, r+i);
    printf("Case #%d: %f\n", h, resolve());
  }
  return 0;
}
