#include <cstdio>
#include <algorithm>

using namespace std;

int m1, m2, m3;
int s1, s2, s3, s4;
int total;

inline void vai(int k3, int k4)
{
  int f1, f2, f3;
  f1 = max(0, m1 - 2*k3 - 3*k4);
  f2 = max(0, m2 - 2*k3);
  f3 = max(0, m3 -   k3 - 2*k4);
  
  int k1, k2;
  k1 = max(f2, f3);
  k2 = max(f1 - k1, 0);
  
  int at = 3*k1 + k2 + 4*k3 + 5*k4;
  if(at < total){
    s1 = k1;
    s2 = k2;
    s3 = k3;
    s4 = k4;
    total = at;
  }
}

int main()
{
  total = 1<<30;
  scanf(" %d %d %d", &m1, &m2, &m3);
  for(int k4 = -1; k4 * 3 <= m1 || k4 * 2 <= m3; k4++)
    for(int k3 = -1; k4*3+k3*2 <= m1 || k3*2 <= m2 || k4*2+k3*2 <= m3; k3++)
      vai(k3+1, k4+1);      
  printf("%d %d %d %d\n", 3*s1, s2, 4*s3, 5*s4);
  return 0;
}
