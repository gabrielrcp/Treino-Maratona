#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct mapa{
  int i;
  int x1, x2, y1, y2;
  int a;
  int cx, cy;
  bool operator < (const mapa &outro) const{
    if(outro.a == a)
      return i < outro.i;
    return a < outro.a;
  }
};

vector<mapa> mapas;
vector<int> allX, allY;
vector< vector<int> > mx;
vector< vector<int> > my;

vector<int> inter(vector<int> v, vector<int> w)
{
  int i = 0, j = 0;
  vector<int> r;
  while(i < v.size() && j < w.size()){
    if(v[i] == w[j]){
      r.push_back(v[i]);
      i++; j++;
    }
    else if(mapas[v[i]] < mapas[w[j]])
      i++;
    else
      j++;
  }
  return r;
}


inline int dist(int i, int x, int y)
{
  int dx = mapas[i].cx - 2*x;
  int dy = mapas[i].cy - 2*y;

  return dx*dx + dy*dy;  
}


bool melhor(int i, int j, int x, int y)
{
  if(mapas[i].a != mapas[j].a)
    return mapas[i].a < mapas[j].a;
  int d1 = dist(i, x, y);
  int d2 = dist(j, x, y);
  if(d1 != d2)
    return d1 < d2;
  return mapas[i].i < mapas[j].i;
}

int vai(int x, int y)
{
  int i = 0, j = 0;
  while(i < allX.size() && allX[i] <= x) i++;
  i--;
  if(i == -1 || (i+1 == allX.size() && allX[i] != x))
    return 0;
  
  while(j < allY.size() && allY[j] <= y) j++;
  j--;
  if(j == -1 || (j+1 == allY.size() && allY[j] != y))
    return 0;

  vector<int> v = inter(mx[i], my[j]);
  if(allX[i] != x)
    v = inter(v, mx[i+1]);
  if(allY[j] != y)
    v = inter(v, my[j+1]);
  
  if(v.size() == 0)
    return 0;

  int r = 0;
  for(int k = 1; k < v.size(); k++){
    if(mapas[v[k]].a > mapas[v[r]].a)
      break;
    if(melhor(v[k], v[r], x, y))
      r = k;
  }
  return mapas[v[r]].i;
}


int main()
{
  int m, r;
  for(int h = 1; ; h++){
    scanf(" %d %d", &m, &r);
    if(m == 0 && r ==0)
      break;
    mapas.clear();
    set<int> _allX , _allY;


    for(int i = 0; i < m; i++){
      int j, x1, x2, y1, y2;
      mapa x;
      scanf(" %d %d %d %d %d", &j, &x1, &y1, &x2, &y2);
      x.i = j;
      x.x1 = x1;
      x.x2 = x2;
      x.y1 = y1;
      x.y2 = y2;
      x.a = abs(x1-x2)*abs(y1-y2);
      x.cx = x1 + x2;
      x.cy = y1 + y2;
      _allX.insert(x1);
      _allX.insert(x2);
      _allY.insert(y1);
      _allY.insert(y2);
      mapas.push_back(x);
    }
    sort(mapas.begin(), mapas.end());
    allX = vector<int> (_allX.begin(), _allX.end());
    allY = vector<int> (_allY.begin(), _allY.end());

    mx = vector < vector<int> > (allX.size(), vector<int>());
    my = vector < vector<int> > (allY.size(), vector<int>());

    for(int i = 0; i < allX.size(); i++)
      for(int j = 0; j < m; j++)
	if(mapas[j].x1 <= allX[i] && allX[i] <= mapas[j].x2)
	  mx[i].push_back(j);

    for(int i = 0; i < allY.size(); i++)
      for(int j = 0; j < m; j++)
	if(mapas[j].y1 <= allY[i] && allY[i] <= mapas[j].y2)
	  my[i].push_back(j);
    
    printf("Teste %d\n", h);
    while(r--){
      int x, y;
      scanf(" %d %d", &x, &y);
      printf("%d\n", vai(x, y));
    }
    printf("\n");
  }
  return 0;
}
