#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cctype>
#include <map>
#include <cstring>

using namespace std;

char buf[20000];

vector<string> lerautores()
{
  vector<string> resp;
  gets(buf);
  char *s = buf;
  while(1){
    if(s[0] == '\0')
      break;
    if(s[0] == ' ')
      s++;
    
    int i = 3;
    while(s[i] != ',' && s[i] != '.')
      i++;
    s[i] = '\0';
    resp.push_back(s);
    s += i+1;
  }
  return resp;
}

#define MAXV 10010

map<string, int> indice;
vector<int> G[MAXV];
int n;
int dist[MAXV];

string autores[MAXV];

bool compara(string a, string b)
{
  int l = min(a.size(), b.size());
  for(int i = 3; i < l; i++)
    if(a[i] != b[i])
      return a[i] < b[i];
  if(a.size() != b.size())
    return a.size() < b.size();
  return a[0] < b[0];
}

int main()
{
  int a;
  for(int h = 1; scanf(" %d\n", &a) && a; h++){
    indice.clear();
    indice["P. Erdos"] = 0;
    G[0].clear();
    n = 1;

    while(a--){
      vector<string> v = lerautores();
      for(int i = 0; i < (int)v.size(); i++){
	if(indice.find(v[i]) == indice.end()){
	  indice[v[i]] = n;
	  G[n].clear();
	  autores[n-1] = v[i];
	  n++;
	}
      }
      for(int i = 0; i < (int)v.size(); i++){
	int a = indice[v[i]];
	for(int j = i+1; j < (int)v.size(); j++){
	  if(i == j) continue;
	  int b = indice[v[j]];
	  G[a].push_back(b);
	  G[b].push_back(a);
	}
      }
      
    }
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
      int i = Q.front();
      Q.pop();
      int d = dist[i];
      for(int k = 0; k < (int)G[i].size(); k++){
	int j = G[i][k];
	if(dist[j] == -1){
	  dist[j] = d + 1;
	  Q.push(j);
	}
      }
    }

    printf("Teste %d\n", h);
    sort(autores, autores + n-1, compara);
    for(int i = 0; i+1 < n; i++){
      int d = dist[indice[autores[i]]];
      if(d == 0) continue;
      printf("%s: ", autores[i].c_str());
      if(d == -1)
	printf("infinito\n");
      else
	printf("%d\n", d);
    }
    printf("\n");

  }
  return 0;
}
