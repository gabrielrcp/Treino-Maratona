#include <stdio.h>
#include <math.h>

#define MAX 110

int n;

typedef struct{
  int x;
  int y;
}Ponto;

double memoriza[MAX][MAX];
Ponto pt[MAX];


double dist(int i, int j)
{
  double d;

  if((i + 1) % n == j || (j + 1) % n == i)
    return 0.0;

  d  = (double)(pt[i].x - pt[j].x)*(pt[i].x - pt[j].x);
  d += (double)(pt[i].y - pt[j].y)*(pt[i].y - pt[j].y);
  return sqrt(d);
}

double minimo(int a, int b)
{
  int i;
  double r, t;

  if(memoriza[a][b] >= 0)
    return memoriza[a][b];

  if(a == b || (a + 1) % n == b || (a+2) % n == b)
    return 0.0;

  r = 1000000.0; /*infi*/

  for(i = (a+1)%n; i != b; i = (i+1)%n){
    t = minimo(a, i) + minimo(i, b) + dist(a, i) + dist(i, b);
    if(t < r)
      r = t;
  }
  memoriza[a][b] = r;
  return r;
}

int main()
{
  int h;
  int i, j;
  double m, t;
  for(h = 1; ; h++){
    scanf(" %d", &n);
    if(n == 0)
      break;

    for(i = 0; i < n; i++)
      scanf(" %d %d", &pt[i].x, &pt[i].y);

    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
	memoriza[i][j] = -1.0;

    m = minimo(1, n-1) + dist(1, n-1);
    for(i = 1; i < n; i++){
      t = minimo((i + 1)%n, i - 1) + dist((i+1)%n, i-1);
      if(t < m)
	m = t;
    }

    printf("Instancia %d\n", h);
    printf("%.2f\n\n", m);
  }
  return 0;
}
