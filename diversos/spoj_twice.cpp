#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 200010
#define LMAX 20

char S[MAX];
int n;

pair< pair<int, int> , int> v[MAX];
int P[LMAX][MAX];
int lim;


void monta()
{
  for(int i = 0; i < n; i++)
    P[0][i] = S[i] - 'a' + 1;


  int pot = 1;
  bool para = false;
  int cnt = 30;
  for(lim = 1; !para; lim++){
    
    for(int i = 0; i < n; i++){
      v[i].first.first = P[lim-1][i];
      v[i].first.second = ((i+pot>= n) ? 0 : P[lim-1][i+pot]);
      v[i].second = i; 
    }

    sort(v, v+n);

    int i = 0;
    cnt = 1;
    para = true;
    while(i < n){
      int j = i;
      while(j < n && v[i].first == v[j].first){
	P[lim][v[j].second] = cnt;
	j++;
      }
      if(j > i+1)
	para = false;
      i = j;
      cnt++;
    }
    pot <<= 1;
  }
}

int iguais(int i, int j)
{
  int k = lim - 1;
  int r = 0;
  while(k >= 0 && i < n && j < n){
    if(P[k][i] == P[k][j]){
      r += (1 << k);
      i += (1 << k);
      j += (1 << k);
    }
    k--;
  }
  return r;
}

int resolve()
{
  int r = 0;
  for(int i = 1; i < n; i++)
    r = max(r, iguais(v[i-1].second, v[i].second));
  return r;
}

int main()
{
  scanf(" %d %s", &n, S);

  monta();
  /*
  for(int i = 0; i < n; i++){
    printf("%s ", S+sarray[i]);
    if(i > 0)
      printf("%d", iguais(sarray[i-1], sarray[i]));
    printf("\n");
  }
  */

  printf("%d\n", resolve());
  return 0;
}
