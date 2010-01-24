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

int mat[110][110];
int n;

int main()
{
#ifndef LOCAL
  freopen("error.in", "r", stdin);
  freopen("error.out", "w", stdout);
#endif

  while(scanf(" %d", &n) && n > 0){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf(" %d", &mat[i][j]);
  
    bool fail = false;
    int l = -1, c = -1;

    for(int i = 0; i < n; i++){
      int s = 0;
      for(int j = 0; j < n; j++)
	s += mat[i][j];
      if(s % 2 == 1){
	if(l == -1)
	  l = i;
	else
	  fail = true;
      }
    }

    for(int j = 0; j < n; j++){
      int s = 0;
      for(int i = 0; i < n; i++)
	s += mat[i][j];
      if(s % 2 == 1){
	if(c == -1)
	  c = j;
	else
	  fail = true;
      }

    }

    if(l == -1 && c == -1)
      printf("OK\n");
    else if(l != -1 && c != -1 && (!fail))
      printf("Change bit (%d,%d)\n", l+1, c+1);
    else
      printf("Corrupt\n");
  }
  return 0;
}

