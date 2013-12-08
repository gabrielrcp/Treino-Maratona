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
 
typedef long long ll;
typedef pair<int, int> pii;

int ages[25];
int primes[] = {2, 3, 5, 7,
		11, 13, 17, 19, 23,
		29, 31, 37, 41, 43,
		47, 53, 59, 61, 67,
		71, 73, 79, 83, 89,
		97, 101, 103, 107, 109,
		113, 127, 131, 137, 139,
		149, 151, 157, 163, 167,
		173, 179, 181, 191, 193,
		197, 199, 211, 223, 227};

int N, K;
int memo[20][32][25];

int go(int i, int used, int last)
{
  if(i == N)
    return 0;
  int &r = memo[i][used][last];
  if(r != -1) return r;

  r = (1<<30);
  for(int k = 0; k < 5; k++){
    if((1 << k) & used)
      continue;
    int x = primes[k];
    while(K*x < ages[i]){
      x *= primes[k];
    }
    x *= K;
    r = min(r, go(i+1, used | (1<<k), last) + x - ages[i]);
  }
  while(K*primes[last] < ages[i])
    last++;
  
  r = min(r, K*primes[last]-ages[i] + go(i+1, used, last+1));

  return r;
}


int solve()
{
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++)
    scanf(" %d", ages+i);
  sort(ages, ages+N);

  if(ages[N-1] <= K){
    int resp = K * N;
    if(ages[0] == 0)
      resp -= K;
    for(int i = 0; i < N; i++)
      resp -= ages[i];
    return resp;
  }

  int resp = 0;
  int start = 0;
  for(int i = 0; i < N; i++){
    if(ages[i] <= K){
      resp += K - ages[i];
      start++;
    }
  }

  memset(memo, -1, sizeof memo);
  return resp + go(start, 0, 5);
}
 
int main()
{
  int cases;
  scanf(" %d", &cases);
  for(int h = 1; h <= cases; h++){
    printf("Case #%d: %d\n", h, solve());
  }
  return 0;
}
