#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 50010

struct rua{
  int d, c, num;
  int usei;
};

vector<rua> G[MAX];

pair<int, bool>  memo[MAX];

bool falhou;
int conta;

void vai(int i)
{
  //printf("%d\n", i);
  if(falhou) return;

  int &cmin = memo[i].first;
  bool &usei = memo[i].second;

  if(cmin >= 0) return;

  cmin = 0;
  usei = false;

  for(int k = 0; k < (int)G[i].size(); k++){
    vai(G[i][k].d);
    cmin = max(cmin, G[i][k].c + memo[G[i][k].d].first);
  }

  //printf("-- %d %d\n", i, cmin);

  for(int k = 0; k < (int)G[i].size(); k++){
    int j = G[i][k].d;
    int cc = G[i][k].c + memo[j].first;
    if(cc < cmin && memo[j].second){
      falhou = true;
      return;
    }
    if(cc < cmin){
      usei = true;
      G[i][k].usei = cmin - cc;
      //printf("-- %d %d\n", G[i][k].num, cmin-cc);
      conta++;
    }
    if(memo[j].second)
      usei  = true;
  }
}
int main()
{
  int n, nr;

  for(int h = 1; scanf(" %d %d", &n, &nr) && n && nr; h++){
    for(int i = 0; i < n; i++){
      G[i].clear();
      memo[i] = make_pair(-1, false);
    }
    
    //printf("n = %d, nr = %d\n", n, nr);

    falhou = false;
    conta = 0;
    memo[n-1] = make_pair(0, false);
 
    for(int k = 1; k <= nr; k++){
      int i, j, c;
      scanf("%d %d %d", &i, &j, &c);
      i--; j--;

      G[i].push_back((rua){j, c, k, -1});
    }

    vai(0);

    printf("Case %d: ", h);
    if(falhou){
      printf("No solution\n");
    } else{
      printf("%d %d\n", conta, memo[0].first);
      for(int i = 0; i < n; i++)
	for(int k = 0; k < (int)G[i].size(); k++){
	  if(G[i][k].usei > 0)
	    printf("%d %d\n", G[i][k].num, G[i][k].usei);
	}

    }

  }
  return 0;
}
