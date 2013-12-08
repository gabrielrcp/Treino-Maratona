#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define MAX (510)

char mat[MAX][MAX];
int lis[MAX][MAX];
int lis1[MAX][MAX], lis2[MAX][MAX];
int N, M;
 
int main()
{
  int cases;
  scanf(" %d", &cases);
  for(int h = 1; h <= cases; h++){
    scanf(" %d %d", &N, &M);
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	scanf(" %c", &mat[i][j]);

    for(int i = 0; i <= N; i++)
      lis[i][M] = lis1[i][M] = lis2[i][M] = 0;
    for(int j = 0; j <= M; j++)
      lis[N][j] = lis1[N][j] = lis2[N][j] = 0;

    for(int i = N-1; i >= 0; i--){
      for(int j = M-1; j >= 0; j--){
	lis[i][j] = 0;
	if(mat[i][j] == '.')
	  lis[i][j] = 1 + max(lis[i+1][j], lis[i][j+1]);
      }
    }

    for(int i = N-1; i >= 0; i--){
      for(int j = M-1; j >= 0; j--){
	lis1[i][j] = lis[i][j];
	lis2[i][j] = lis[i][j];
	if(mat[i][j] == '#')
	  continue;
	lis1[i][j] = max(lis1[i][j], 1+lis1[i][j+1]);
	lis1[i][j] = max(lis1[i][j], 1+lis2[i+1][j]);

	lis2[i][j] = max(lis2[i][j], 1+lis1[i][j+1]);
	lis2[i][j] = max(lis2[i][j], 1+lis2[i+1][j]);


	for(int k = 1; k <= i; k++){
	  if(mat[i-k][j] == '#')
	    break;
	  lis1[i][j] = max(lis1[i][j], k+1+lis[i-k][j+1]);
	}

	for(int k = 1; k <= j; k++){
	  if(mat[i][j-k] == '#')
	    break;
	  lis2[i][j] = max(lis2[i][j], k+1+lis[i+1][j-k]);
	}
      }
    }

    printf("Case #%d: %d\n", h, max(lis1[0][0], lis2[0][0]));

  }
  return 0;
}
