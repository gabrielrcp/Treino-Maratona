#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

char orig[200][200];
int ko;
char mapa[200][200];

int tam(int l, int k)
{
  if(l < k)
    return l+1;
  else if(l < 2*k-1)
    return 2*k-1-l;
  else
    return 0;
}

bool diferente(char a, char b)
{
  if(a == 0 || b == 0)
    return false;
  return (a != b);
}

bool confere(int x, int y, int k)
{
  memset(mapa, 0, sizeof mapa);
  //printf("%d %d %d\n", x, y, k);

  for(int l = 0; l < 2*ko-1; l++){
    if(l != 0){
      int a = (tam(l, ko) - tam(l-1,ko));
      int b = (tam(x+l, k)-tam(x+l-1,k));
      y += b - a;
    }
    if(y < 0 || y + tam(l, ko) > tam(x+l, k))
      return false;
    for(int c = 0; c < tam(l, ko); c++)
      mapa[l+x][c+y] = orig[l][c];
  }
  for(int l = 0; l < 2*k-1; l++){
    for(int c = 0; c < tam(l, k); c++){
      if(diferente(mapa[l][c], mapa[2*k-1-l-1][c]))
	return false;
      if(diferente(mapa[l][c], mapa[l][tam(l,k)-c-1]))
	return false;
    }
  }
  return true;
}

bool vai(int k)
{
  for(int x = 0; tam(x+ko-1, k) >= ko ; x++){
    for(int y = 0; y <= 2*(k-ko); y++){
      if(confere(x, y, k))
	return true;
    }
  }
  return false;
}

int calcula(int k)
{
  int r = 0;
  for(int l = 0; l < 2*k-1; l++)
    r += tam(l, k) - tam(l, ko);
  return r;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &ko);
    for(int l = 0; l < 2*ko-1; l++){
      for(int c = 0; c < tam(l, ko); c++){
	scanf(" %c", &orig[l][c]);
      }
    }

    int k = ko;
    while(!vai(k)){
      k++;
    }
    printf("Case #%d: %d\n", h, calcula(k));
  }
  return 0;
}
