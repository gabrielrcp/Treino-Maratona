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


int go(int n, int k, int c)
{
  int t = k/n;
  int resp = c;
  
  c = max(c - n * t, 0);
  k -= n*t;
  if(c > 0)
    resp += n-k;
  return resp;
}
 
int main()
{
  int cases;
  scanf(" %d", &cases);
  for(int h = 1; h <= cases; h++){
    int n, k, c;
    scanf(" %d %d %d", &n, &k, &c);

    int resp = c + n;
    for(int t = 1; t <= n; t++){
      resp = min(resp, go(t, k, c) + n-t);
    }

    printf("Case #%d: %d\n", h, resp);
  }
  return 0;
}
