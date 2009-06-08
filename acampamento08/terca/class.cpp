#include <cstdio>
#include <algorithm>

using namespace std;


int r, c, n;

int raiz(int x)
{
  for(int i = 1; ;i++)
    if(i*i > x)
      return i-1;
}

char mat[105][105];

void imprimemesmo()
{
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++)
      putchar(mat[i][j]);
    putchar('\n');
  }
}

void imprime(int h)
{
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      mat[i][j] = '.';

  for(int i = 0; i < h; i++)
    mat[i][0] = '#';
  for(int j = 0; j < h; j++)
    mat[0][j] = '#';

  int x = n - (2*h - 1);
   if(x == 0){
    imprimemesmo();
    return;
  }
  //printf("-%d\n", x);
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if(mat[i][j] == '.'){
	mat[i][j] = '#';
	x--;
	if(x == 0){
	  imprimemesmo();
	  return;
	}
      }
}

int main()
{
  while(scanf(" %d %d %d", &n, &r, &c) == 3){
    int h = min(min((n+1)/2, r), c);
    printf("%d\n", h);
    imprime(h);
  }
  return 0;
}
