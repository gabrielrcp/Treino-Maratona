#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;

pdd v1[20], v2[20];


pdd intersecta(pdd c1, pdd c2)
{
  double cx = c2.first - c1.first;
  double cy = c2.second - c1.second;

  double t = cx*cx + cy*cy;
  double a = 4.0 * t;
  double b = - 4.0 *cy * t;

  double c = t*t - 16.0 * cx*cx;

  double y = (-b + sqrt(b*b - 4.0*a*c)) / (2.0 * a);
  double x = (cy*cy + cx*cx - 2.0*y*cy) / (2.0 * cx);

  return make_pair(x + c1.first, y + c1.second);

}


pdd vai(pdd *v, pdd *prox, int n)
{
  if(n == 1)
    return v[0];
  for(int i = 0; i + 1 < n; i++)
    prox[i] = intersecta(v[i], v[i+1]);
  return vai(prox, v, n-1);      
}


int main()
{
  int casos;
  int n;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %lf", &(v1[i].first));
      v1[i].second = 1.0;
    }
    sort(v1, v1+n);
    pdd resp = vai(v1, v2, n);
    printf("%d: %.4lf %.4lf\n", h, resp.first, resp.second);
  }
  return 0;
}
