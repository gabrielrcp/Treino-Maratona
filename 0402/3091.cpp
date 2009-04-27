#include <cstdio>

#define MAX 1010

int n;
int resposta;

bool livre1[MAX];
bool livre2[MAX];
bool livre3[MAX];

bool bt(int i, int j, int tot)
{
  if(tot == resposta)
    return true;

  if(i == n)
    return false;
  if(i + j == n)
    return bt(i+1, 0, tot);
      
  int k = n-1-i-j;
  if(livre1[i] && livre2[j] && livre3[k]){
    livre1[i] = false;
    livre2[j] = false;
    livre3[k] = false;
    if(bt(i, j+1, tot+1))
      return true;
    livre1[i] = true;
    livre2[j] = true;
    livre3[k] = true;
  }
  return bt(i, j+1, tot);
}


void resolve()
{
  resposta = (2 * n + 1) / 3;
  for(int i = 0; i <= n; i++)
    livre1[i] = livre2[i] = livre3[i] = true;
  if(bt(0, 0, 0))
    printf("ok!\n");
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    resolve();
  }
  return 0;
}
