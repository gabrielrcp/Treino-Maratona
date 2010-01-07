#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define LIM 10000.0

double PI, R3;

int main()
{
  PI = acos(-1.0);
  R3 = sqrt(3.0);
  while(1){
    double u, a, d;
    scanf(" %lf %lf %lf", &u, &a, &d);
    if(u < 0.5) break;
    a = a / 180 * PI;

    double t = (a + R3*log(d))/R3;
    t = (exp(t) - d) / u;

    if(t > LIM)
      printf("God help me!\n");
    else
      printf("%.0f\n", t);

  }
  return 0;
}
