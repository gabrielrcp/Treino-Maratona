#include <cstdio>

#define MAX 5000

char dif[MAX];


int confere(int n)
{
  for(int i = 1; i < n; i++)
    if(!dif[i])
      return 0;
  return 1;
}

int main()
{
  int n;
  while(!feof(stdin) && scanf(" %d", &n) > 0){
    long long ant, at, d;
    for(int i = 1; i < n; i++)
      dif[i] = 0;
    scanf(" %lld", &ant);
    for(int i = 1; i < n; i++){
      scanf(" %lld", &at);
      d = at - ant;
      if(d < 0) d = -d;
      if(d < n && d > 0)
	dif[d] = 1;
      ant = at;
    }
    if(!confere(n))
      printf("Not jolly\n");
    else
      printf("Jolly\n");
  }
  return 0;
}
