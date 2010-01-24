#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

#define INF (1<<30)

#define MAX 210

int mat[MAX][MAX];
int n;

int esq[MAX][MAX];
int dir[MAX][MAX];
int cima[MAX][MAX];
int baixo[MAX][MAX];

int resp(int i, int j)
{
  if(mat[i][j] > 0)
    return mat[i][j];

 
  int r = INF;
  int c = 3;
  int at = 0;

  for(int k = 0; k <= r; k++){
    if(j + k >= n) break;
    if(cima[i][j+k] >= 0 && cima[i][j+k] < n){
      int d = k + abs(i-cima[i][j+k]);
      if(d == r)
	c++;
      else if(d < r){
	r = d;
	c = 1;
	at = mat[cima[i][j+k]][j+k];
      }
    }
    if(cima[i][j+k] == i) continue;
    if(baixo[i][j+k] >= 0 && baixo[i][j+k] < n){
      int d = k + abs(baixo[i][j+k]-i);
      if(d == r)
	c++;
      else if(d < r){
	r = d;
	c = 1;
	at = mat[baixo[i][j+k]][j+k];
      }
    }
  }


  for(int k = 1; k <= r; k++){
    if(j - k < 0) break;
    if(cima[i][j-k] >= 0 && cima[i][j-k] < n){
      int d = k + abs(i-cima[i][j-k]);
      if(d == r)
	c++;
      else if(d < r){
	r = d;
	c = 1;
	at = mat[cima[i][j-k]][j-k];
      }
    }
    if(cima[i][j-k] == i) continue;
    if(baixo[i][j-k] >= 0 && baixo[i][j-k] < n){
      int d = k + abs(baixo[i][j-k]-i);
      if(d == r)
	c++;
      else if(d < r){
	r = d;
	c = 1;
	at = mat[baixo[i][j-k]][j-k];
      }
    }
  }
  if(r > 3*n || c != 1)
    return 0;
  return at;
}

int main()
{
#ifndef LOCAL
  freopen("nearnum.in", "r", stdin);
  freopen("nearnum.out", "w", stdout);
#endif

  scanf(" %d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf(" %d", &mat[i][j]);


  for(int i = 0; i < n; i++){
    int ult = -INF;
    for(int j = 0; j < n; j++){
      if(mat[i][j] != 0)
	ult = j;
      esq[i][j] = ult;
    }
  }
  for(int i = 0; i < n; i++){
    int ult = INF;
    for(int j = n-1; j >= 0; j--){
      if(mat[i][j] != 0)
	ult = j;
      dir[i][j] = ult;
    }
  }
  for(int j = 0; j < n; j++){
    int ult = -INF;
    for(int i = 0; i < n; i++){
      if(mat[i][j] > 0)
	ult = i;
      cima[i][j] = ult;
    }
  }
  for(int j = 0; j < n; j++){
    int ult = INF;
    for(int i = n-1; i >= 0; i--){
      if(mat[i][j] > 0)
	ult = i;
      baixo[i][j] = ult;
    }
  }

  for(int i = 0; i < n; i++){
    printf("%d", resp(i, 0));
    for(int j = 1; j < n; j++)
      printf(" %d", resp(i, j));
    printf("\n");
  }


  return 0;
}

