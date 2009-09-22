// TLE!!! :(


#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 50

double pi;
int ptx[MAX];
int pty[MAX];

int n;

int dist2(int i, int j)
{
  int dx = ptx[i] - ptx[j];
  int dy = pty[i] - pty[j];
  return dx*dx+dy*dy;
}

double dist2(pair<double, double> p1, pair<double, double> p2)
{
  double dx = p1.first - p2.first;
  double dy = p1.second - p2.second;
  return dx*dx + dy*dy;
}

pair<double, double> acha_centro(int i, int j, double r)
{
  double mx = 0.5 * (ptx[i] + ptx[j]);
  double my = 0.5 * (pty[i] + pty[j]);

  double vx =  pty[i] - pty[j];
  double vy = -ptx[i] + ptx[j];
  double nrv = sqrt(vx*vx + vy*vy);

  double d2 = 0.25 * dist2(i, j);
  double h = sqrt(r*r - d2);

  return make_pair(mx + vx*h/nrv, my + vy*h/nrv);
}

bool dentro[MAX];
bool dentro1[MAX];
pair<double, int> angs[2*MAX];
int nang;

void insere(double a, int i)
{
  while(a < 0.0) a += 2.0*pi;
  while(a > 2.0*pi) a -= 2.0*pi;
  angs[nang++] = make_pair(a, i);
}


bool pivota(int k, double r)
{
  dentro[k] = true;

  nang = 0;
  double base, inc;
  for(int i = 0; i < n; i++){
    if(dentro[i])
      continue;
    if(dist2(i, k) > 4.0*r*r)
      return false;
    if(ptx[i] == ptx[k])
      base = (pty[i] > pty[k] ? 0.5*pi : 1.5*pi);
    else if(pty[i] == pty[k])
      base = (ptx[i] > ptx[k] ? 0.0 : pi);
    else
      base = atan2(pty[i]-pty[k], ptx[i]-ptx[k]);
    inc = acos(0.5 * sqrt(dist2(i, k)) / r);
    insere(base+inc, i);
    insere(base-inc, i);
  }

  sort(angs, angs+nang);

  pair<double, double> inicio = make_pair(ptx[k] + r, pty[k]);
  int conta = 0;
  for(int i = 0; i < n; i++){
    if(dentro[i])
      conta++;
    else{
      if(dist2(inicio, make_pair(ptx[i], pty[i])) < r*r){
	dentro[i] = true;
	conta++;
      }
    }
  }

  if(conta == n)
    return true;

  for(int i = 0; i < nang; i++){
    if(dentro[angs[i].second]){
      conta--;
      dentro[angs[i].second] = false;
    }
    else{
      conta++;
      if(conta == n) return true;
      dentro[angs[i].second] = true;
    }
  }    
  return false;
}

bool cobrir1(pair<double, double> c1, double r)
{
  for(int i = 0; i < n; i++)
    dentro1[i] = (dist2(c1, make_pair(ptx[i], pty[i])) <= r*r + 1.0E-9);

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++)
      dentro[i] = dentro1[i];      
    if(pivota(k, r))
      return true;
  }
  return false;
}

bool cobrir2(double r)
{
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(dist2(i, j) > 4*r*r)
	continue;

      if(cobrir1(acha_centro(i, j, r), r) || cobrir1(acha_centro(j, i, r), r))
	return true;
    }
  }

  return false;
}

double resolve()
{
  double e = 0.0, d = 1.0e4;
  while(d - e > 0.005){
    double m = 0.5*(e+d);
    if(cobrir2(m))
      d = m;
    else
      e = m;
  }
  return 0.5*(e+d);
}


int main()
{
  pi = acos(-1.0);
  while(scanf(" %d", &n) && n){
    for(int i = 0; i < n; i++)
      scanf(" %d %d", ptx+i, pty+i);
    printf("%.2f\n", resolve());
  }

  /*  
  n = 3;
  ptx[0] = 0; pty[0] = 0;
  ptx[1] = 1; pty[1] = 0;
  ptx[2] = 0; pty[2] = 4;

  for(int  i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      printf("%f ", sqrt(dist2(i, j)));
    puts("");
  }
  */  
  //printf("%d\n", (cobrir1(make_pair(0.50, 0.0), 0.50001) ? 1 : 0));
  //printf("%d\n", (cobrir2(1.225) ? 1 : 0));
  return 0;
}
