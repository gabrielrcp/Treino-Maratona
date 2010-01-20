#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 5010

int n, a, b, p;


int vai(int i)
{
  if(i == n) return 0;
  int c = ((a*i+b)%p);
  c %= (n - i + 1);
  int m = vai(i+1);
  if(m >= c)
    m++;
  return m;
}



int main()
{
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  while(1){
    scanf(" %d %d %d %d", &n, &a, &b, &p);
    if(n == a && a == b && b == p && p == 0)
      break;

    printf("The winner is %d.\n", vai(1)+1);
  }
  return 0;
}
