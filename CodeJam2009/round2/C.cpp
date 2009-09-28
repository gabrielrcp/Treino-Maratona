#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 110

int graf[MAX][30];
int n, k;

vector<int> G[MAX];

bool emcima(int i, int j)
{
  for(int l = 0; l < k; l++)
    if(graf[i][l] <= graf[j][l])
      return false;
  return true;
}

bool coberto[MAX];
int emp[MAX];
int ant[2*MAX];

void mudar_emp(int j)
{
  int i = ant[j];
  emp[j-n] = i;
  coberto[i] = true;
  if(ant[i] != -1)
    mudar_emp(ant[i]);
}

bool aumenta()
{
  queue<int> Q;
  for(int i = 0; i < 2*n; i++)
    ant[i] = -1;
  for(int i = 0; i < n; i++)
    if(!coberto[i])
      Q.push(i);

  while(!Q.empty()){
    int i = Q.front(); Q.pop();
    if(i >= n){
      ant[emp[i-n]] = i;
      Q.push(emp[i-n]);
    }
    else{
      for(int l = 0; l < G[i].size(); l++){
	int j = G[i][l];
	if(ant[j] != -1 || emp[j-n] == i) continue;
	ant[j] = i;
	if(emp[j-n] == -1){
	  mudar_emp(j);
	  return true;
	}
	else
	  Q.push(j);
      }
    }
  }
  return false; 
}

int emp_maximo()
{
  for(int i = 0; i < n; i++){
    emp[i] = -1;
    coberto[i] = false;
  }
  int r = 0;
  while(aumenta())
    r++;
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){

    scanf(" %d %d", &n, &k);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < k; j++)
	scanf(" %d", &graf[i][j]);

    for(int i = 0; i < n; i++){
      G[i].clear();
      for(int j = 0; j < n; j++)
	if(emcima(i, j))
	  G[i].push_back(j+n);
    }
    printf("Case #%d: %d\n", h, n - emp_maximo());
  }
  return 0;
}
