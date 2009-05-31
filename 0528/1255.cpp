#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define MAX 110

int n;
pair <int, int> c1[MAX], c2[MAX];
vector<int> allX, allY;

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

int busca(int x, vector<int> &v)
{
  int e = 0, d = v.size()-1;
  while(e <= d){
    int m = (e+d)/2;
    if(v[m] == x)
      return m;
    if(v[m] > x)
      d = m - 1;
    else
      e = m + 1;
  }
  return -1;
}

int resolve(int x1, int y1, int x2, int y2)
{
  
  for(int i = busca(x1, allX)+1; i < allX.size() && allX[i] < x2; i++){
    int x = allX[i];
    if(podex(x, y1, y2)){
      int a = resolve(x1, y1, x, y2);
      int b = resolve(x, y1, x2, y2);
      return max(a, b);
    }
  }
   
  for(int j = busca(y1, allY)+1; j < allY.size() && allY[j] < y2; j++){
    int y = allY[j];
    if(podey(y, x1, x2)){
      int a = resolve(x1, y1, x2, y);
      int b = resolve(x1, y, x2, y2);
      return max(a, b);
    }
  }
  
  return (x2 - x1) * (y2 - y1);
}


void imprime(vector <int> &v)
{
  for(int i = 0; i < v.size(); i++)
    printf("%d ", v[i]);
  printf("\n");
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int w, h;
    scanf(" %d %d %d", &w, &h, &n);

    set<int> _allX, _allY;
    for(int i = 0; i < n; i++){
      scanf(" %d %d %d %d", &(c1[i].first), &(c1[i].second),
	    &(c2[i].first), &(c2[i].second));
      _allX.insert(c1[i].first);
      _allX.insert(c2[i].first);
      _allY.insert(c1[i].second);
      _allY.insert(c2[i].second);
    }

    allX = vector<int> (_allX.begin(), _allX.end());
    allY = vector<int> (_allY.begin(), _allY.end());

    printf("%d\n", resolve(0, 0, w, h));
  }
  return 0;
}
