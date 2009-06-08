#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
char tab[20][20];
char M[20][20];

int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, -1, 0, 1};

void muda(int i, int j){
  for(int k = 0; k < 5; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if(0 <= x && x < n && 0 <= y && y < m)
      M[x][y] = 1 - M[x][y];
  }
}

int vai()
{
  int r = 0;
  for(int j = 1; j < m; j++){
    for(int i = 0; i < n; i++){
      if(M[i][j-1] == 1){
	muda(i, j);
	r++;
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(M[i][j] == 1){
	return (1 << 30);
      }
    }
  }
  return r;
}

int main()
{
  while(1){
    scanf(" %d %d", &n, &m);
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	char c;
	scanf(" %c", &c);
	if(c == 'X')
	  c = 1;
	else
	  c = 0;
	if(n <= m)
	  tab[i][j] = c;
	else
	  tab[j][i] = c;
      }
    
    if(n > m){
      int t = n;
      n = m;
      m = t;
    }

    int r = 1 << 30;
    for(int e = 0; e < (1 << n); e++){
      for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	  M[i][j] = tab[i][j];

      int t = 0;
      for(int i = 0; i < n; i++)
	if(e & (1 << i)){
	  muda(i, 0);
	  t++;
	}
      t += vai();
      r = min(r, t);
    }
    if(r == (1 << 30))
      printf("Damaged billboard.\n");
    else
      printf("You have to tap %d tiles.\n", r);
  }
  return 0;
}
