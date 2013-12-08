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

int K;
double ps, pr;
double pi, pu, pw, pd, pl;

//double *****memo;
double memo[100][100][100][100][3];

double solve(int a, int b, int inc, int dec, int s)
{
  if(a == K)
    return 1.0;
  if(b == K)
    return 0.0;
  double &r = memo[a][b][inc][dec][s];
  if(r > -0.5)
    return r;

  double p;
  if(s == 0)
    p = pi;
  else if(s == 1)
    p = 0.0;
  else
    p = 1.0;
  p += pu*inc - pd*dec;

  if(p >= 1.0 || p <= 0.0){
    inc = dec = 0;
    if(p <= 0.0){
      p = 0.0;
      s = 1;
    } else{
      s = 2;
      p = 1.0;
    }
  }


  r =    p    *    ps    *    pw    * solve(a+1,   b, inc+1,   dec, s)
    +    p    *    ps    * (1.0-pw) * solve(a+1,   b,   inc,   dec, s)
    +    p    * (1.0-ps) *    pl    * solve(  a, b+1,   inc, dec+1, s)
    +    p    * (1.0-ps) * (1.0-pl) * solve(  a, b+1,   inc,   dec, s)
    + (1-0-p) *    pr    *    pw    * solve(a+1,   b, inc+1,   dec, s)
    + (1.0-p) *    pr    * (1.0-pw) * solve(a+1,   b,   inc,   dec, s)
    + (1.0-p) * (1.0-pr) *    pl    * solve(  a, b+1,   inc, dec+1, s)
    + (1.0-p) * (1.0-pr) * (1.0-pl) * solve(  a, b+1,   inc,   dec, s);
  return r;
}

int main()
{
  int cases;
  scanf(" %d", &cases);

  /*
  memo = (double*****)malloc(101*sizeof(double****));
  for(int a = 0; a <= 100; a++){
    memo[a] = (double****)malloc(101*sizeof(double***));
    for(int b = 0; b <= 100; b++){
      memo[a][b] = (double***)malloc(101*sizeof(double**));
      for(int inc = 0; inc <= 100; inc++){
	memo[a][b][inc] =  (double**)malloc(101*sizeof(double*));
	for(int dec = 0; dec <= 100; dec++){
	  memo[a][b][inc][dec] =  (double*)malloc(3*sizeof(double));
	}
      }
    }
  }
  */

  for(int h = 1; h <= cases; h++){
    scanf(" %d", &K);
    scanf(" %lf %lf", &ps, &pr);
    scanf(" %lf %lf %lf %lf %lf", &pi, &pu, &pw, &pd, &pl);
    for(int a = 0; a < K; a++)
      for(int b = 0; b < K; b++)
	for(int inc = 0; inc < K; inc++)
	  for(int dec = 0; dec < K; dec++)
	    for(int s = 0; s < 3; s++)
	      memo[a][b][inc][dec][s] = -1.0;
    printf("Case #%d: %.6f\n", h, solve(0, 0, 0, 0, 0));
  }
  return 0;
}
