#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define LIM 1500
#define MAX 1000100

int v[LIM];
char num[MAX];

int resto(int m)
{
  int r = 0;
  for(int i = 0; num[i]; i++){
    r = 10*r + num[i]-'0';
    r %= m;
  }
  return r;
}

int main()
{
  v[0] = v[1] = 1;

  for(int i = 2; i < LIM; i++){
    v[i] = ((v[i-2] + v[i-1])%1000);
  }
  
  int casos;
  scanf(" %d", &casos);

  while(casos--){
    scanf(" %s", num);
    int r = resto(LIM);
    r = ((r+LIM-1)%LIM);
    printf("%03d\n", v[r]);
  }
  
  return 0;
}
