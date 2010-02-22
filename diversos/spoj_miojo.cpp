#include <cstdio>
#include <algorithm>

using namespace std;

int vai(int t, int a, int b)
{
  int i = 0, j = 0;
  while(i <= a*b && j <= a*b){
    if(j - i == t) return j;
    if(j - i < t)
      j += b;
    else
      i += a;
  }
  return (1 << 30);
}


int main()
{
  int t, a, b;

  scanf(" %d %d %d", &t, &a, &b);

  printf("%d\n", min(vai(t, a, b), vai(t, b, a)));


  return 0;
}
