#include <cstdio>
#include <algorithm>

using namespace std;

#define INF (1<<29)

int n;
int w, h;

int x1[110], x2[110];
int y1[110], y2[110];

bool overlap()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      if(i == j) continue;

      if(max(x1[i], x1[j]) < min(x2[i], x2[j]) &&
	 max(y1[i], y1[j]) < min(y2[i], y2[j]))
	return true;
    }
  return false;
}

bool contido()
{
  int mix = INF, mx = -INF;
  int miy = INF, my = -INF;
  for(int i = 0; i < n; i++){
    mix = min(mix, x1[i]);
    mx = max(mx, x2[i]);
    miy = min(miy, y1[i]);
    my = max(my, y2[i]);
  }

  //printf("%d %d %d %d\n", mx, mix, my, miy);
  //return (mx - mix <= w &&  my - miy <= h);

  return (mx <= w && mix >= 0 && my <= h && mix >= 0);
}

bool cobre()
{
  long long a = 0;
  long long t = (long long) w * h;
  for(int i = 0; i < n; i++)
    a += (long long) (x2[i] - x1[i]) * (y2[i] - y1[i]);
  return a == t;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %d", &w, &h, &n);
    for(int i = 0; i < n; i++)
      scanf(" %d %d %d %d", x1+i, y1+i, x2+i, y2+i);
    
    if(overlap())
      printf("NONDISJOINT\n");
    else if(!contido())
      printf("NONCONTAINED\n");
    else if(!cobre())
      printf("NONCOVERING\n");
    else
      printf("OK\n");
  }
}
