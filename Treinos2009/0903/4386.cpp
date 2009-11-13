#include <cstdio>

char muda[30][200];
int n;

bool cte[30];
bool vis[30];

int ult[30];
int at;

bool vai(int i)
{
  if(vis[i]){
    cte[i] = false;
    return false;
  }

  vis[i] = true;
  if(muda[i][0] == i + 'a'){
    if(muda[i][1] != '\0')
      at = muda[i][1] - 'a';
    ult[i] = at;
    cte[i] = true;
    return true;
  }
  if(vai(muda[i][0] - 'a')){
    cte[i] = true;
    ult[i] = at;
    return true;
  }
  cte[i] = false;
  return false;
}


bool parei()
{
  for(int i = 0; i < n; i++)
    vis[i] = false;

  int i = 0;
  while(1){
    if(vis[i])
      return false;
    if(!cte[i])
      return true;
    vis[i] = true;
    i = ult[i];
  }
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %s", muda[i]);

    for(int i = 0; i < n; i++)
      vis[i] = false;

    for(int i = 0; i < n; i++)
      if(!vis[i]){
	at = -1;
	vai(i);
      }

    if(parei())
      printf("YES\n");
    else
      printf("NO\n");
    
  }
  return 0;
}
