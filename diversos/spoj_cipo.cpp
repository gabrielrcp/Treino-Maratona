#include <vector>
#include <cstdio>

using namespace std;


#define MAX 1010

typedef pair<int, int> pii;

vector<pii> art[3];

int custo[3] = { 1235, 8977, 10923};

int pai[MAX];

int find(int x)
{
  if(x == pai[x])
    return x;
  pai[x] = find(pai[x]);
  return pai[x];
}



int main()
{
  for(int h = 1; ; h++){
    int n, m;
    if(feof(stdin))
      break;
    if(scanf(" %d %d", &n, &m) == 0)
      break;
    if(feof(stdin))
      break;

    for(int i = 0; i < n; i++)
      pai[i] = i;
    for(int i = 0; i < 3; i++)
      art[i].clear();

    while(m--){
      int i, j, c;
      scanf(" %d %d %d", &i, &j, &c);
      i--; j--;
      switch(c){
      case 1235:
	art[0].push_back(make_pair(i, j));
	break;
      case 8977:
	art[1].push_back(make_pair(i, j));
	break;
      case 10923:
	art[2].push_back(make_pair(i, j));
	break;
      }
    }
    
    int resp = 0;
    for(int l = 0; l < 3; l++){
      for(int k = 0; k < art[l].size(); k++){
	int i = art[l][k].first;
	int j = art[l][k].second;
	int pi = find(i);
	int pj = find(j);
	if(pi != pj){
	  resp += custo[l];
	  pai[pi] = pj;
	}
      }
    }
    
    printf("Instancia %d\n%d\n\n", h, resp);
  }

  return 0;
}
