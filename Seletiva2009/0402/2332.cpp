#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 55
#define INF (1 << 30)

char matriz[MAX][MAX];
int soma2[MAX][MAX];
int soma1[MAX][MAX];
int tot2;

int n, m;


void ler()
{

  scanf(" %d %d", &n, &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      scanf(" %c", &matriz[i][j]);

  soma1[0][0] = (matriz[0][0] == '1' ? 1 : 0);
  soma2[0][0] = (matriz[0][0] == '2' ? 1 : 0);
  for(int i = 1; i < n; i++){
    soma1[i][0] = soma1[i-1][0] + (matriz[i][0] == '1' ? 1 : 0);
    soma2[i][0] = soma2[i-1][0] + (matriz[i][0] == '2' ? 1 : 0);
  }
  for(int j = 1; j < m; j++){
    soma1[0][j] = soma1[0][j-1] + (matriz[0][j] == '1' ? 1 : 0);
    soma2[0][j] = soma2[0][j-1] + (matriz[0][j] == '2' ? 1 : 0);
  }


  for(int i = 1; i < n; i++)
    for(int j = 1; j < m; j++){
      soma1[i][j] = soma1[i-1][j] + soma1[i][j-1] - soma1[i-1][j-1];
      if(matriz[i][j] == '1')
	soma1[i][j]++;
      soma2[i][j] = soma2[i-1][j] + soma2[i][j-1] - soma2[i-1][j-1];
      if(matriz[i][j] == '2')
	soma2[i][j]++;
    }
  
  tot2 = soma2[n-1][m-1];
}


inline int qtddentro2(int x1, int y1, int x2, int y2)
{
  int r = soma2[x2][y2];

  if(x1 > x2 || y1 > y2)
    return 0;
 
  if(x1 != 0)
    r -= soma2[x1-1][y2] ;
  if(y1 != 0)
    r -= soma2[x2][y1-1];
  if(x1 != 0 && y1 != 0)
    r += soma2[x1-1][y1-1];
  return r;
}

inline int qtddentro1(int x1, int y1, int x2, int y2)
{
  int r = soma1[x2][y2];

  if(x1 > x2 || y1 > y2)
    return 0;
 
  if(x1 != 0)
    r -= soma1[x1-1][y2] ;
  if(y1 != 0)
    r -= soma1[x2][y1-1];
  if(x1 != 0 && y1 != 0)
    r += soma1[x1-1][y1-1];
  return r;
}


int confere(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  int r = (x2-x1+1) * (y2-y1+1) + (x4-x3+1)*(y4-y3+1);
  if(max(x1, x3) <= min(x2,x4) && max(y1,y3) <= min(y2,y4))
    r -= (min(x2, x4)-max(x1,x3)+1) * (min(y2,y4)-max(y1,y3)+1);
  
  if(qtddentro1(x1,y1,x2,y2) != 0 || qtddentro1(x3,y3,x4,y4) != 0)
    return INF;
  return r;
}


int resolve()
{
  int resp = INF;
  int x1, y1, x2, y2;
  int x3, y3, x4, y4;
  
  if(tot2 == 0)
    return 0;
  
  x1 = 0;
  while(soma2[x1][m-1] == 0)
    x1++;

  for(x2 = x1; x2 < n; x2++){
    for(y1 = 0; y1 < m; y1++){
      for(y2 = y1; y2 < m; y2++){

	if(qtddentro1(x1,y1,x2,y2) != 0)
	  continue;

	if(qtddentro2(x1,y1,x2,y2) == tot2){
	  resp = min(resp, (x2-x1+1)*(y2-y1+1));
	  continue;
	}

	x3 = 0;
	while(x3 < n && soma2[x3][m-1]-qtddentro2(x1, y1, min(x2, x3), y2) <= 0)
	  x3++;
	x4 = x3;
	while(x4 < n && soma2[x4][m-1]+qtddentro2(max(x1,x4+1), y1, x2, y2)<tot2)
	  x4++;

	y3 = 0;
	while(y3 < m && soma2[n-1][y3]-qtddentro2(x1, y1, x2, min(y2,y3)) <= 0)
	  y3++;
	y4 = y3;
	while(y4 < m && soma2[n-1][y4]+qtddentro2(x1, max(y1,y4+1), x2, y2)<tot2)
	  y4++;

	int t = confere(x1,y1, x2,y2, x3,y3, x4,y4);
	//printf("%d %d %d %d %d %d %d %d -- %d\n", x1,y1,x2,y2,x3,y3,x4,y4, t);
	resp = min(resp, t);
      }
    }
  }

  if(resp == INF)
    return -1;
  return resp;
}


int main()
{
  ler();
  /*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      printf("%d ", soma2[i][j]);
    printf("\n");
  }
  */
  printf("%d\n", resolve());
  return 0;
}
