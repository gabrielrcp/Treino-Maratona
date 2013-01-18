#include <cstdio>
#include <cstring>

char tab[110][210];
int R, C, K;


double prob[110][210];


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %d", &R, &C, &K);
    C = 2*C - 1;
    K = 2*K + 1;
    memset(tab, sizeof(tab), 0);
    for(int i = 0; i < R; i++)
      for(int j = (i%2); j < C; j += 2)
	tab[i][j] = 1;
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      int r, c;
      scanf(" %d %d", &r, &c);
      if(r % 2 == 0)
	c = 2*c;
      else
	c = 2*c + 1;
      tab[r][c] = 0;
    }

    for(int j = 0; j < C; j++)
      prob[R][j] = 0.0;
    prob[R][K] = 1.0;

    for(int i = R-1; i >= 0; i--){
      prob[i][0] = ((tab[i][0]) ? prob[i+1][1] : prob[i+1][0]);
      prob[i][1] = ((tab[i][1]) ? prob[i+1][2] : prob[i+1][1]);
      prob[i][C-1] = ((tab[i][C-1]) ? prob[i+1][C-2] : prob[i+1][C-1]);
      prob[i][C-2] = ((tab[i][C-2]) ? prob[i+1][C-3] : prob[i+1][C-2]);
      for(int j = 2; j < C-2; j++){
	prob[i][j] = ((tab[i][j]) ?
		      (0.5*(prob[i+1][j-1]+prob[i+1][j+1])) : 
		      prob[i+1][j]);
      }
    }

    int r = 1;
    for(int j = 1; j < C; j+= 2)
      if(prob[0][j] > prob[0][r])
	r = j;

    printf("%d %.06f\n", r/2, prob[0][r]);
  }
  return 0;
}
