#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define EPS 1.0e-9
int a[55], b[55], c[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n, N;

    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", a+i);
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", b+i);
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", c+i);
    scanf(" %d", &N);


    double melhor = 1.0e100;
    int resp = -1;
    for(int i = 0; i < n; i++){
      double at = a[i] * pow((double)N, b[i]) * pow(log(N), c[i]);
      if(melhor > at + EPS){
	resp = i;
	melhor = at;
      }
    }
    printf("%d\n", resp);
    
  }
  return 0;
}

