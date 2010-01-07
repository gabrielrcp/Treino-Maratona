#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int muda(int n)
{
  int x = (n%10) + (n/10);
  return (10 * (n%10)) + (x%10);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int ini, n;
    scanf(" %d", &n);
    ini = n;
    int conta = 0;
    do{
      n = muda(n);
      conta++;
    }while(n != ini);
    printf("%d\n", conta);
  }
  return 0;
}
