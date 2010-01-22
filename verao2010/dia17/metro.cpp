#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, T;
int demora[55];
char saidir[55][222];
char saiesq[55][222];

int proxdir[55][222];
int proxesq[55][222];

int memo[55][222];

#define INF (1<<30)

int resolve(int i, int t)
{
  if(t > T) return INF;

  int &r = memo[i][t];
  if(r != -1) return r;

  r = INF;
  if(i == N-1) r = T - t;
  if(proxdir[i][t] != -1)
    r = min(r, resolve(i+1, proxdir[i][t]+demora[i+1]) + proxdir[i][t] - t);
  if(proxesq[i][t] != -1)
    r = min(r, resolve(i-1, proxesq[i][t]+demora[i]) + proxesq[i][t] - t);
  return r;
}


int main()
{
  freopen("metro.in", "r", stdin);
  freopen("metro.out", "w", stdout);

  for(int h = 1; scanf(" %d", &N) && N != 0; h++){
    scanf(" %d", &T);
    for(int i = 1; i < N; i++)
      scanf(" %d", demora+i);
    memset(saidir, 0, sizeof saidir);
    memset(saiesq, 0, sizeof saiesq);

    int m;
    scanf(" %d", &m);
    while(m--){
      int d;
      scanf(" %d", &d);
      int p = 0;
      while(d <= T && p < N-1){
	saidir[p][d] = 1;
	d += demora[p+1];
	p++;
      }
    }

    scanf(" %d", &m);
    while(m--){
      int d;
      scanf(" %d", &d);
      int p = N-1;
      while(d <= T && p > 0){
	saiesq[p][d] = 1;
	d += demora[p];
	p--;
      }
    }

    for(int i = 0; i < N; i++){
      int ult = -1;
      int t = T;
      while(t >= 0){
	if(saiesq[i][t]){
	  ult = t;
	}
	proxesq[i][t] = ult;
	t--;
      }
    }
    for(int i = 0; i < N; i++){
      int ult = -1;
      int t = T;
      while(t >= 0){
	if(saidir[i][t]){
	  ult = t;
	  //printf("%d %d\n", i, t);
	}
	proxdir[i][t] = ult;
	t--;
      }
    }

    memset(memo, -1, sizeof memo);
    int r = resolve(0, 0);
    printf("Case Number %d: ", h);
    if(r == INF)
      printf("impossible\n");
    else
    printf("%d\n", r);

  }
  return 0;
}
