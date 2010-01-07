#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 20

int n;
double raio;

struct pt{
  double x, y;
};

pt P[MAX];
double memo[1<<10];
double pi;

vector<pt> fecho;

double prod(int i, int j, int k)
{
  double ax = P[j].x - P[i].x;
  double ay = P[j].y - P[i].y;
  double bx = P[k].x - P[i].x;
  double by = P[k].y - P[i].y;
  return ax*by - bx*ay;
}

double dist(int i, int j)
{
  double dx = P[i].x - P[j].x;
  double dy = P[i].y - P[j].y;
  return dx*dx + dy*dy;
}

#define EPS 1.0e-9
void fecho_convexo(int m)
{
  int ini = 0;
  while(!((1<<ini) & m)) ini++;
  for(int i = ini+1; i < n; i++)
    if(m & (1<<i)){
      if(P[i].x - P[ini].x < -EPS)
	ini = i;
      else if(-EPS < P[i].x - P[ini].x && P[i].x-P[ini].x < EPS 
	      && P[i].y < P[ini].y)
	ini = i;
    }
  
  int at = ini;
  fecho.clear();
  do{
    fecho.push_back(P[at]);
    int i = 0;
    while((!((1<<i) & m)) || i == at) i++;
    for(int j = i+1; j < n; j++){
      if(j == at) continue;
      if((m & (1<<j)) && prod(at, i, j) < EPS){
	if(prod(at, i, j) < -EPS)
	  i = j;
	else if(dist(at, i) < dist(at, j))
	  i = j;
      }
    }
    at = i;
  }while(at != ini);
}

double resolve(int m)
{
  if(m == 0) return 0;

  double resp = 2.0*pi*raio;
  if(!((m-1) & m)) return resp;

  fecho_convexo(m);
  for(int i = 1; i < (int)fecho.size(); i++){
    double dx = fecho[i-1].x - fecho[i].x;
    double dy = fecho[i-1].y - fecho[i].y;
    resp += sqrt(dx*dx + dy*dy);
  }
  int i = 0, j = fecho.size()-1;
  double dx = fecho[j].x - fecho[i].x;
  double dy = fecho[j].y - fecho[i].y;
  resp += sqrt(dx*dx + dy*dy);

  //printf("%d %f\n", m, resp);
  return resp;
}

double vai(int mask)
{
  double &resp = memo[mask];
  if(resp > -0.5) return resp;

  resp = resolve(mask);
  for(int m = ((mask-1) & mask); m > 0; m = ((m-1) & mask)){
    resp = min(resp, vai(m) + vai(m ^ mask));
  }
  //printf("-- %d %f\n", mask, resp);

  return resp;
}

int main()
{
  pi = acos(-1.0);
  for(int h = 1; scanf(" %d %lf", &n, &raio) && n; h++){
    for(int i = 0; i < n; i++)
      scanf(" %lf %lf", &P[i].x, &P[i].y);
    for(int i = 0; i < (1 << n); i++)
      memo[i] = -1.0;
    printf("Case %d: length = %.2f\n", h, vai((1<<n)-1));
  }
  return 0;
}
