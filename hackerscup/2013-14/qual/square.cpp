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


int N;
char mat[50][50];

bool solve(pii a, pii b)
{
  if(b.first-a.first != b.second - a.second)
    return false;
  for(int i  = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(a.first <= i && i <= b.first &&
	 a.second <= j && j <= b.second){
	if(mat[i][j] == '.')
	  return false;
      } else {
	if(mat[i][j] == '#')
	  return false;
      }
    }
  }
  return true;
}

int main()
{
  int cases;
  scanf(" %d", &cases);
  for(int h = 1; h <= cases; h++){
    scanf(" %d", &N);
    pii a = make_pair(N+1, N+1);
    pii b = make_pair(-1, -1);
    for(int i = 0; i < N; i++){
      scanf(" %s", mat[i]);
      for(int j = 0; j < N; j++){
	if(mat[i][j] == '#'){
	  a = min(a, make_pair(i, j));
	  b = max(b, make_pair(i, j));
	}
      }
    }
    printf("Case #%d: %s\n", h, (solve(a, b) ? "YES" : "NO"));
  }
  return 0;
}
