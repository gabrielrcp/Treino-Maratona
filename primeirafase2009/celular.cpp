#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 50
#define EPS (1.0e-9)

double pi;
int ptx[MAX];
int pty[MAX];
pair<int, int> pt[MAX];

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

pair<double, int> angs[MAX][2*MAX];
int nang[MAX];

char dentro1[MAX];
char dentro2[MAX];

void insere(double a, int i, int k)
{
  while(a < 0.0) a += 2.0*pi;
  while(a > 2.0*pi) a -= 2.0*pi;
  angs[k][nang[k]++] = make_pair(a, i);
}

bool cobrir(double r)
{
  for(int k = 0; k < n; k++){
    nang[k] = 0;
    double base, inc;
    for(int i = 0; i < n; i++){
      if(i == k ||dist2(i, k) > 4*r*r)
	continue;

      if(ptx[i] == ptx[k])
	base = (pty[i] > pty[k] ? 0.5*pi : 1.5*pi);
      else if(pty[i] == pty[k])
	base = (ptx[i] > ptx[k] ? 0.0 : pi);
      else
      base = atan2(pty[i]-pty[k], ptx[i]-ptx[k]);
      inc = acos(0.5 * sqrt(dist2(i, k)) / r);
      insere(base+inc, i, k);
      insere(base-inc, i, k);
    }
    sort(angs[k], angs[k]+nang[k]);
  }


  for(int i = 0; i < n; i++){

    pair<double, double> ini1 = make_pair(ptx[i]+r, pty[i]);
    for(int k = 0; k < n; k++)
      dentro1[k] = ((dist2(ini1, pt[k]) <= r*r + EPS) ? 1 : 0);
    
    for(int j = 0; j < n; j++){
      pair<double, double> ini2 = make_pair(ptx[j]+r, pty[j]);

      for(int k = 0; k < n; k++)
	dentro2[k] = ((dist2(ini2, pt[k]) <= r*r + EPS) ? 1 : 0);

      int conta = 0;
      for(int k = 0; k < n; k++)
	conta += (int)(dentro1[k] | dentro2[k]);

      if(conta == n) return true;

      for(int k = 0; k < nang[i]; k++){
	for(int l = 0; l < nang[j]; l++){
	  int x = angs[j][l].second;
	  if(dentro2[x]){
	    dentro2[x] = 0;
	    if(!dentro1[x]) conta--;
	  }
	  else{
	    dentro2[x] = 1;
	    if(!dentro1[x]){
	      conta++;
	      if(conta == n)
		return true;
	    }
	  }
	}
	int x = angs[i][k].second;
	if(dentro1[x]){
	  dentro1[x] = 0;
	  if(!dentro2[x]) conta--;
	}
	else{
	  dentro1[x] = 1;
	  if(!dentro2[x]){
	    conta++;
	    if(conta == n)
	      return true;
	  }
	}
      }
    }
  }
  return false;
}

double resolve()
{
  double e = 0.0, d = 1.0e4;
  while(d - e > 0.0005){
    double m = 0.5*(e+d);
    if(cobrir(m))
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
    for(int i = 0; i < n; i++){
      scanf(" %d %d", ptx+i, pty+i);
      pt[i] = make_pair(ptx[i], pty[i]);
    }
    printf("%.2f\n", resolve());
  }
  return 0;
}
