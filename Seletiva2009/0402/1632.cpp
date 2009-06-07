#include <cstdio>

#define MAX 36

int ns[MAX];
char mat[MAX][MAX];

bool comum[MAX];

bool vai(int ats, int nus, int k)
{
  if(nus == k)
    return true;

  if(ats == MAX)
    return false;

  bool ant[MAX];
  if(ns[ats] >= k){
    int c = 0;
    for(int i = 0; i < MAX; i++){
      ant[i] = comum[i];
      comum[i] = comum[i] && mat[ats][i];
	if(comum[i])
	  c++;
    }
    if(c >= k && vai(ats+1, nus+1, k))
      return true;
    for(int i = 0; i < MAX; i++)
      comum[i] = ant[i];
  }
  return vai(ats+1, nus, k);
}


bool tenta(int k)
{
  for(int i = 0; i < MAX; i++)
    comum[i] = true;
  return vai(0, 0, k);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int m;
    scanf(" %d", &m);

    for(int i = 0; i < MAX; i++){
      for(int j = 0; j < MAX; j++)
	mat[i][j] = 0;
      ns[i] = 0;
    }

    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      mat[i][j] = 1;
    }

    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++)
	if(mat[i][j])
	  ns[i]++;

    for(int k = 10; k >= 1; k--)
      if(tenta(k)){
	printf("%d\n", k);
	break;
      }

  }
  return 0;
}
