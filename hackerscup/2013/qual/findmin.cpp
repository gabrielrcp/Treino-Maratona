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

#define MAX (100010)

int m[MAX];
int ult[MAX];

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int n, k;
    ll a, b, c, r;
    scanf(" %d %d", &n, &k);
    scanf("%lld %lld %lld %lld", &a, &b, &c, &r);

    m[0] = a;
    memset(ult, -1, sizeof ult);
    if(a <= k) ult[a] = 0;
    for(int i = 1; i < k; i++){
      ll prox =  (b * a + c) % r;
      a = prox;
      m[i] = prox;
      if(prox <= k)
	ult[prox] = i;
    }

    m[k] = k;
    for(int i = 0; i < k; i++){
      if(ult[i] == -1){
	m[k] = i;
	ult[i] = k;
	break;
      }
    }
    if(m[k] == k) ult[k] = k;

    if(n-1 != k){
      priority_queue<int, vector<int>, greater<int> > Q;
      for(int i = 0; i <= k; i++)
	if(ult[i] == -1)
	  Q.push(i);
      
      for(int i = 0; i <= k; i++){
	if(m[i] <= k && ult[m[i]] == i)
	  Q.push(m[i]);
	m[i] = Q.top();
	Q.pop();
      }
    }
    

    printf("Case #%d: %d\n", h, m[(n-1)%(k+1)]);
  }
  return 0;
}
