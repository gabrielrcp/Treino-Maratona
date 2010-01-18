#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 210

int vx[MAX];
int vy[MAX];
int px[MAX];
int py[MAX];

int n, k;


double dist2(double x, double y)
{
  double r = 1.0e100;
  for(int i = 0; i < k; i++){
    double dx = x-px[i];
    double dy = y-py[i];
    r = min(r, dx*dx+dy*dy);
  }
  return r;
}

int main()
{
  freopen("fire.in", "r", stdin);
  freopen("fire.out", "w", stdout);

  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    scanf(" %d %d", vx+i, vy+i);
  memset(dist, 0x3f, sizeof dist);

  scanf(" %d", &k);

  for(int i = 0; i < k;; i++)
    scanf(" %d %d", px+i, py+i);

  double rx = vx[0], ry = vy[0];
  double rd = dist(vx[0], vy[0]);
  for(int i = 1; i < n; i++){
    double t = dist(vx[i], vy[i]);
    if(t > rd){
      rx = vx[i];
      ry = vy[i];
      rd = t;
    }
  }

  int r = 0;
  for(int i = 1; i < n; i++)
    if(dist[i] > dist[r])
      r = i;
  printf("%d %d\n", vx[r], vy[r]);

  /*
  for(int i = 0; i < n; i++)
    printf("%d %d %d\n", vx[i], vy[i], dist[i]);
  */
  return 0;
}
