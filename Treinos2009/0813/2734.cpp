#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> rainhas[110]; int nrainhas;
pair<int, int> cavalos[110]; int ncavalos;
bool ocupado[1010][1010];
bool atacado[1010][1010];
int n, m;

int rx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int ry[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void atacarainha(int x, int y)
{
  for(int k = 0; k < 8; k++){
    int nx = x;
    int ny = y;
    while(1){
      nx += rx[k];
      ny += ry[k];
      if(nx < 0 || nx >= n)
	 break;
      if(ny < 0 || ny >= m)
	break;
      if(ocupado[nx][ny])
	break;
      atacado[nx][ny] = true;
    }
  }
}

int cx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int cy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

void atacacavalo(int x, int y)
{
  for(int k = 0; k < 8; k++){
    int i = x + cx[k];
    int j = y + cy[k];
    atacado[i][j] = true;
  }
}

int main()
{
  for(int h = 1;; h++){
    scanf(" %d %d", &n, &m);

    if(n == 0 && m == 0)
      break;
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	ocupado[i][j] = atacado[i][j] = false;

    scanf(" %d", &nrainhas);
    for(int k = 0; k < nrainhas; k++){
      scanf(" %d %d", &rainhas[k].first, &rainhas[k].second);
      rainhas[k].first--;
      rainhas[k].second--;
      ocupado[rainhas[k].first][rainhas[k].second] = true;
    }
    scanf(" %d", &ncavalos);
    for(int k = 0; k < ncavalos; k++){
      scanf(" %d %d", &cavalos[k].first, &cavalos[k].second);
      cavalos[k].first--;
      cavalos[k].second--;
      ocupado[cavalos[k].first][cavalos[k].second] = true;
    }
    int npeoes;
    scanf(" %d", &npeoes);
    while(npeoes--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      ocupado[i][j] = true;
    }

    for(int k = 0; k < nrainhas; k++)
      atacarainha(rainhas[k].first, rainhas[k].second);
    for(int k = 0; k < ncavalos; k++)
      atacacavalo(cavalos[k].first, cavalos[k].second);

    int conta = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	if((!ocupado[i][j]) && (!atacado[i][j]))
	  conta++;
    /*
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
	if((!ocupado[i][j]) && (!atacado[i][j]))
	  printf("1");
	else
	  printf("0");
      printf("\n");
    }
    */

    printf("Board %d has %d safe squares.\n", h, conta);

  }
  return 0;
}
