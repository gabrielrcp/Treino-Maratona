#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char mapa[250][250];
int n, m;

bool fim()
{
  for(int i = 0; mapa[n][i] != '\0'; i++){
    if(mapa[n][i] != '*')
      return false;
  }
  return true;
}

int main()
{
  m = 0;
  while(1){
    for(n = 0; ;n++){
      gets(mapa[n]);
      int t = strlen(mapa[n]);
      m = max(m, t);
      if(fim())
	break;
    }
    if(n == 0) break;

    for(int i = 0; i < n; i++){
      int j = 0;
      while(mapa[i][j] != '\0') j++;

    int saidas[30];
    for(int i = 0; i < 30; i++)
      saidas[i] = 0;

    for(int i = 0; i < n; i++)
      for(int j = 0; mapa[i][j] != '\0'; j++){
	if('A' <= mapa[i][j] && mapa[i][j] <= 'Z')
	  saidas[mapas[i][j] - 'A'] = vai(i, j);
      }

    for(int i = 0; i < 30; i++){
      if(saidas[i] != -1)
	printf("%c=%d\n", i + 'A', saidas[i]);
    }
    printf("\n");
  }
  return 0;
}
