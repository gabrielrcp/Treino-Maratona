#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct estado{
  pair<int, int> p[5];
  int nc;

  const operator < (const estado &outro) const{
    for(int k = 0; k < nc; k++){
      if(p[k] < outro.p[k])
	return true;
      if(p[k] > outro.p[k])
	return false;
    }
    return false;
  }
  const operator == (const estado &outro) const{
    for(int k = 0; k < nc; k++){
      if(p[k] != outro.p[k])
	return false;
    }
    return true;
  }
};


estado ini, fim;
char mapa[15][15];
int n, m;

void ler()
{
  scanf(" %d %d", &n, &m);
  ini.nc = 0;
  fim.nc = 0;

  for(int i = 0; i <= n+1; i++)
    mapa[i][0] = mapa[i][m+1] = 0;
  for(int j = 0; j <= m+1; j++)
    mapa[0][j] = mapa[n+1][j] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char c;
      scanf(" %c", &c);
      mapa[i][j] = ((c == '#') ? 0 : 1);
      
      if(c == 'x' || c == 'w'){
	fim.p[fim.nc] = make_pair(i, j);
	fim.nc++;
      }

      if(c == 'o' || c == 'w'){
	ini.p[ini.nc] = make_pair(i, j);
	ini.nc++;
      }
    }
  }
  sort(fim.p, fim.p+fim.nc);
}

bool livre(int i, int j, estado &at)
{
  if(!mapa[i][j]) return false;
  for(int k = 0; k < at.nc; k++)
    if(at.p[k].first == i && at.p[k].second == j)
      return false;
  return true;
}

bool  move(int i, int j, int dx, int dy, estado &at)
{
  return (livre(i+dx, j+dy, at) && livre(i-dx, j-dy, at));
}

bool perigo(int i, int j, estado &at, int ig)
{
  for(int k = 0; k < at.nc; k++)
    if(k != ig)
      if(abs(i-at.p[k].first) + abs(j-at.p[k].second) == 1)
	return false;
  return true;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int resolve()
{
  queue<estado> Q;
  map< estado, int > S;

  Q.push(ini);
  S[ini] = 0;

  while(!Q.empty()){
    estado at = Q.front(); Q.pop();
    int d = S[at];

    for(int k = 0; k < at.nc; k++){
      estado tmp = at;
      for(int l = 0; l < 4; l++){
	if(!move(at.p[k].first, at.p[k].second, dx[l], dy[l]))
	  continue;
	tmp.p[k].first += dx[l];
	tmp.p[k].second += dy[l];

	if(!perigo(temp.p[k].first, temp.p[k].second, at, k)){
	  sort(tmp.p, temp.p+temp.nc);

	  if(temp == fim) return d+1;

	  if(S.find(temp) != S.end())
	    continue;

	  S[temp] = d+1;
	}

      }
    }

  }o
  return -1;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    ler();
    printf("Case #%d: %d\n", h, resolve()); 
  }
  return 0;
}
