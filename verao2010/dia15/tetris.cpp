#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 55

char mat[MAX][MAX];
int a, b;

bool livre(int i, int x1, int x2)
{
  for(int j = x1; j < x2; j++)
    if(mat[i][j])
      return false;
  return true;
}

bool tenta(int w, int h, char c, int x)
{
  int r = 0;
  if(x + w > a) return false;
  while(r < b && livre(r, x, x+w))
    r++;
  r--;
  if(r < h-1) return false;

  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      mat[r-i][x+j] = c;
  return true;
}

bool cheia(int i)
{
  for(int j = 0; j < a; j++)
    if(mat[i][j] == 0)
      return false;
  return true;
}

void elimina()
{
  for(int i = 0; i < b; i++){
    if(cheia(i)){
      for(int j = i-1; j >= 0; j--){
	for(int k = 0; k < a; k++)
	  mat[j+1][k] = mat[j][k];
      }
      for(int k = 0; k < a; k++)
	mat[0][k] = 0;
    }
  }
}

int main()
{
  freopen("tetris.in", "r", stdin);
  freopen("tetris.out", "w", stdout);

  while(1){
    scanf(" %d %d", &a, &b);
    if(a == b && b == 0) break;

    memset(mat, 0, sizeof mat);
  
    bool fail = false;
    while(1){
      int w, h, c, x;
      scanf(" %d %d %d %d", &w, &h, &c, &x);
      if(w == h && h == c && c == x && x == 0)
	break;
      x--;
      if(!fail){
	if(tenta(w, h, c, x))
	  elimina();
	else
	  fail = true;
      }
    }

    if(fail){
      printf("GAME OVER\n");
    } else{
      for(int i = 0; i < b; i++){
	for(int j = 0; j < a; j++)
	  printf("%d", mat[i][j]);
	printf("\n");
      }
    }
    printf("-\n");
    
  }
  return 0;
}
