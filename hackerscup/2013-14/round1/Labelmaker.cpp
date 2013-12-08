/* WA */
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> pii;


char leters[30];
ll N, num;
ll pot[70];

void imprime(int size)
{
  if(size == 0) return;
  size--;
  int i = (N-1) / pot[size];
  putchar(leters[i]);
  N -= i * pot[size];
  imprime(size);
}

int main()
{
  int cases;
  scanf(" %d", &cases);
  for(int h = 1; h <= cases; h++){
    scanf(" %s %lld", leters, &N);
    pot[0] = 1;
    num = (ll)strlen(leters);
    pot[1] = num;
    int size = 1;
    while(pot[size] < N && pot[size] > 0){
      pot[size+1] = num * pot[size];
      N -= pot[size];
      size++;
    }

    printf("Case #%d: ", h);
    imprime(size);
    printf("\n");
  }
  return 0;
}
