#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

int n;

void imprime(vector <int> &v)
{
  //printf("%d\n", QSort(v, 0, n-1));
}

int main()
{
#ifndef LOCAL
  freopen("antiqs.in", "r", stdin);
  freopen("antiqs.out", "w", stdout);
#endif
  
  scanf(" %d", &n);

  vector<int> v (n, -1);


  if(n == 1){
    v[0] = 1;
  } else if(n == 2){
    v[0] = 1; v[1] = 2;
  }else{
    stack<int> P;
    P.push(n);
    while(!P.empty()){
      int i = P.top(); P.pop();
      if(i == 3){
	v[0] = 1; v[1] = 3; v[2] = 2;
      } else if(v[i-1] == -1){
	v[i-1] = i;
	P.push(i);
	P.push(i-1);
	continue;
      } else{		       
	int m = (i-1)/2;
	swap(v[i-1], v[m]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  
  return 0;
}

