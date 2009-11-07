#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define MAXN 110
#define MAXM 10010

int n, m, lim;

int comp[MAXN][MAXM];
int feli[MAXN][MAXM];

int table[MAXN][MAXM];

int felicum[MAXM];

inline int total(int i, int j, int k)
{
  if(j <= k)
    return felicum[k] - felicum[j] + table[i+1][k];
  return felicum[j] - felicum[k] + table[i+1][k];
    
}

int main()
{
  while(scanf(" %d %d %d", &n, &m, &lim) && n){
    for(int i = n; i >= 0; i--)
      for(int j = 0; j < m; j++)
	scanf(" %d", &feli[i][j]);

    for(int i = n; i >= 0; i--)
      for(int j = 0; j < m; j++)
	scanf(" %d", &comp[i][j]);

    for(int j = 0; j <= m; j++)
      table[n+1][j] = 0;

    for(int i = n; i >= 0; i--){

      felicum[0] = 0;
      for(int j = 0; j < m; j++)
	felicum[j+1] = felicum[j] + feli[i][j];

      int scomp = 0, k = 0;
      set< pair<int, int> > S;
      S.insert(make_pair(-table[i+1][0], 0));

      for(int j = 0; j < m; j++){

	while(k < m){
	  scomp += comp[i][k];
	  k++;
	  if(scomp > lim){
	    k--;
	    scomp -= comp[i][k];
	    break;
	  }
	  S.insert(make_pair(-(felicum[k] + table[i+1][k]), k));
	}

	int t;
	while(1){
	  set< pair<int, int> >::iterator it = S.begin();
	  t = it->second;
	  if(t >= j)
	    break;
	  S.erase(it);
	}
		  
	table[i][j] = total(i, j, t);
	scomp -= comp[i][j];
      }
              
      scomp = 0; k = m;
      S.clear();
      S.insert(make_pair(-table[i+1][m], m));

      for(int j = m; j > 0; j--){

	while(k > 0){
	  scomp += comp[i][k-1];
	  k--;
	  if(scomp > lim){
	    k++;
	    scomp -= comp[i][k-1];
	    break;
	  }
	  S.insert(make_pair(-(felicum[m] - felicum[k] + table[i+1][k]), k));
	}

	int t;
	while(1){
	  set< pair<int, int> >::iterator it = S.begin();
	  t = it->second;
	  if(t <= j)
	    break;
	  S.erase(it);
	}

	if(j == m)
	  table[i][j] = total(i, j, t);
	else
	  table[i][j] = max(table[i][j], total(i, j, t));
	scomp -= comp[i][j-1];
      }

    }
    /*    
    for(int i = n; i >= 0; i--){
      for(int j = 0; j <= m; j++)
	printf("%d ", table[i][j]);
      puts("");
    }
    */

    int resp = table[0][0];
    for(int j = 1; j <= m; j++)
      resp = max(resp, table[0][j]);

    printf("%d\n", resp);
    
  }
  return 0;
}
