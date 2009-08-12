#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

char tab[10][10];
char memo[10][10][10][10];

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dist(int xk, int yk, int xp, int yp)
{
  return max(abs(xk-xp), abs(yk-yp));
}

bool pode(int xk, int yk, int xp, int yp)
{
  if(tab[xk][yk] != '.')
    return false;
  if(abs(yk-yp) == 1 && xk == xp+1)
    return false;
  return true;
}

char vai(int xk, int yk, int xp, int yp)
{
  if(dist(xk, yk, xp, yp) == 1 && tab[xp][yp] == '.')
    return 1;
  if(xp == 8)
    return 0;

  int possiveis = 0;
  for(int k = 0; k < 8; k++)
    if(pode(xk+dx[k], yk+dy[k], xp, yp))
      possiveis++;
  if(possiveis == 0)
    return 0;

  if(tab[xp+1][yp] == 'F')
    return 1;
  if(dist(xk, yk, xp+1, yp) == 1 && pode(xp+1, yp, xp, yp))
    return 1;


  char &r = memo[xk][yk][xp][yp];
  if(r != -1)
    return r;

  r = 0;
  for(int k = 0; k < 8; k++)
    if(pode(xk+dx[k], yk+dy[k], xp, yp))
      if(vai(xk+dx[k], yk+dy[k], xp+1, yp)){
	r = 1;
	break;
      }
  return r;
}


int main()
{
  int casos;
  scanf(" %d", &casos);

  for(int i = 0; i < 10; i++)
    tab[i][0] = tab[i][9] = tab[0][i] = tab[9][i] = 'F';

  while(casos--){
    for(int i = 1; i <= 8; i++)
      for(int j = 1; j <= 8; j++)
	scanf(" %c", &tab[i][j]);

    int xk, yk, xp, yp;
    scanf(" %d %d %d %d", &yk, &xk, &yp, &xp);
    xk = 9 - xk;
    xp = 9 - xp;

    for(int a = 1; a <= 8; a++)
      for(int b = 1; b <= 8; b++)
	for(int c = 1; c <= 8; c++)
	  for(int d = 1; d <= 8; d++)
	    memo[a][b][c][d] = -1;
    
    if(vai(xk, yk, xp, yp))
      printf("White\n");
    else
      printf("Black\n");    

  }
  return 0;
}
