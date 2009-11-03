#include <cstdio>

#define MAX 110

int mat[MAX][MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{

  int R, C;
  int N, K;

  while(scanf(" %d %d %d %d", &N, &R, &C, &K) && N){
    for(int i = 0; i < R; i++)
      for(int j = 0; j < C; j++)
	scanf(" %d", &mat[0][i][j]);


    for(int k = 1; k <= K; k++){

      for(int i = 0; i < R; i++)
	for(int j = 0; j < C; j++)
	  mat[k][i][j] = mat[k-1][i][j];

      for(int i = 0; i < R; i++)
	for(int j = 0; j < C; j++)
	  for(int l = 0; l < 4; l++){
	    int x = i + dx[l];
	    int y = j + dy[l];
	    if(x < 0 || x >= R || y < 0 || y >= C)
	      continue;
	    if(mat[k-1][x][y] == ((mat[k-1][i][j] + 1)%N))
	      mat[k][x][y] = mat[k-1][i][j];
	  }
    }

    for(int i = 0; i < R; i++){
      printf("%d", mat[K][i][0]);
      for(int j = 1; j < C; j++)
	printf(" %d", mat[K][i][j]);
      printf("\n");
    }

  }
  return 0;
}

