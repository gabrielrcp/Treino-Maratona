#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1010

int n;
int x1[MAX], x2[MAX], y1[MAX], y2[MAX];




long long vai(int a, int b, int c, int d)
{
  long long x, y;
  x = abs(c-a);
  y = abs(d-b);

  long long resp = 0;
  for(int j = 0; j < min(x,y); j++)
    resp += (x-j) * (y-j);
  return resp;  
}



long long conta(int i)
{
  return vai(x1[i], y1[i], x2[i], y2[i]);
}

long long conta(int a, int b)
{
  if(x2[a] == x1[b] && (!(  y2[b] <= y1[a] || y1[b] >= y2[a] ))){
    int ye = max(y1[a], y1[b]) + 1;
    int yd = min(y2[a], y2[b]) - 1;
    
    if(ye >= yd)
      return 0;

    long long resp = 0;
    resp = vai(x1[a], ye, x2[b], yd);
    resp -= vai(x1[a], ye, x2[a], yd);
    resp -= vai(x1[b], ye, x2[b], yd);
    return resp;
  }


  if(y2[a] == y1[b] && (!(  x2[b] <= x1[a] || x1[b] >= x2[a] ))){
    int xe = max(x1[a], x1[b]) + 1;
    int xd = min(x2[a], x2[b]) - 1;
    
    if(xe >= xd)
      return 0;

    long long resp = 0;
    resp = vai(y1[a], xe, y2[b], xd);
    resp -= vai(y1[a], xe, y2[a], xd);
    resp -= vai(y1[b], xe, y2[b], xd);
    return resp;
  }
  return 0;
}


int main()
{
  for(int h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0)
      break;

    for(int i = 0; i < n; i++){
      int a, b, c, d;
      scanf("%d %d %d %d", &a, &b, &c, &d);
      x1[i] = min(a, c);
      x2[i] = max(a, c);
      y1[i] = min(b, d);
      y2[i] = max(b, d);
    }

    long long resp = 0;
    for(int i = 0; i < n; i++){
      resp += conta(i);
      for(int j = 0; j < n; j++)
	if(i != j)
	  resp += conta(i, j);
    }

    printf("Case %d: %lld\n", h, resp);

  }
  return 0;
}
