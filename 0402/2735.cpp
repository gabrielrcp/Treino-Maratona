#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int G[30][30];
int num[30];
int n, m;

int ordem[30], low[30], ant[30];
int conta;


bool dfs(int i)
{
  ordem[i] = conta++;
  low[i] = ordem[i];
  for(int k = 0; k < num[i]; k++){
    int j = G[i][k];
    if(ordem[j] == -1){
      ant[j] = i;
      if(!dfs(j))
	return false;
      if(low[j] == ordem[j])
	return false;
      low[i] = min(low[i], low[j]);
    }
    else if(ant[i] != j)
      low[i] = min(low[i], ordem[j]);
  }
  return true;
}

bool confere()
{
  for(int i = 0; i < n; i++)
    ordem[i] = low[i] = ant[30] = -1;
  conta = 1;

  if(!dfs(0))
    return false;

  for(int i = 0; i < n; i++)
    if(ordem[i] == -1)
      return false;

  return true;
}


int main()
{
  for(int caso = 1; ; caso++){
    scanf(" %d %d", &n, &m);
    if(n == m && m == 0) break;

    int a1[30], a2[30], a3[30];
    for(int i = 0; i < m; i++){
      scanf(" %d %d %d", a1+i, a2+i, a3+i);
      a1[i]--; a2[i]--;
    }

    int resposta = -1;
    for(int e = 1; e < (1 << m); e++){
      memset(num, 0, n * sizeof(int));
      int total = 0;
      for(int k = 0; k < m; k++){
	if(e & (1 << k)){
	  int i = a1[k];
	  int j = a2[k];
	  int c = a3[k];

	  G[i][num[i]] = j;
	  G[j][num[j]] = i;
	  num[i]++; num[j]++;
	  total += c;
	}
      }
      if(confere()){
	if(resposta == -1)
	  resposta = total;
	else if(resposta > total)
	  resposta = total;
      }
    }

    if(resposta == -1)
      printf("There is no reliable net possible for test case %d.\n", caso);
    else
      printf("The minimal cost for test case %d is %d.\n", caso, resposta);
  }
  return 0;
}
