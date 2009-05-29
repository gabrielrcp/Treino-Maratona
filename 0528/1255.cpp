#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 110

int n;
pair <int, int> c1[MAX], c2[MAX];


bool podex(int x, int y1, int y2)
{
  for(int i = 0; i < n; i++)
    if(y1 <= c1[i].second && c2[i].second <= y2)
      if(c1[i].first < x && x < c2[i].first)
	return false;
  return true;      
}

bool podey(int y, int x1, int x2)
{
  for(int i = 0; i < n; i++)
    if(x1 <= c1[i].first && c2[i].first <= x2)
      if(c1[i].second < y && y < c2[i].second)
	return false;
  return true;      
}

int resolve(int x1, int y1, int x2, int y2)
{

  for(int x = x1 + 1; x < x2; x++){
    if(podex(x, y1, y2)){
      int a = resolve(x1, y1, x, y2);
      int b = resolve(x, y1, x2, y2);
      return max(a, b);
    }
  }

  for(int y = y1+1; y < y2; y++){
    if(podey(y, x1, x2)){
      int a = resolve(x1, y1, x2, y);
      int b = resolve(x1, y, x2, y2);
      return max(a, b);
    }
  }

  /*
  for(int i = 0; i < n; i++){
    if(x1 <= c1[i].first && c2[i].first <= x2 &&
       y1 <= c1[i].second && c2[i].second <= y2){         
      if(c1[i].first == x1 && c2[i].first == x2){
	int a = (c2[i].first - c1[i].first)*(c2[i].second - c1[i].second);
	int b = resolve(x1, y1, x2, c1[i].second);
	int c = resolve(x1, c2[i].second, x2, y2);
	return max(max(a, b), c);
      }
      else if(c1[i].second == y1 && c2[i].second == y2){
	int a = (c2[i].first - c1[i].first)*(c2[i].second - c1[i].second);
	int b = resolve(x1, y1, c1[i].first, y2);
	int c = resolve(c2[i].first, y1, x2, y2);
	return max(max(a, b), c);
      }
    }
  }
  */
  return (x2 - x1) * (y2 - y1);
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int w, h;
    scanf(" %d %d %d", &w, &h, &n);

    for(int i = 0; i < n; i++)
      scanf(" %d %d %d %d", &(c1[i].first), &(c1[i].second),
	    &(c2[i].first), &(c2[i].second));
    printf("%d\n", resolve(0, 0, w, h));
  }
  return 0;
}
