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
 
#define MAX 510

char buf[MAX];

bool solve()
{
  int s = 0, opt = 0;
  for(int i = 0; buf[i]; i++){
    if(buf[i] == '('){
      if(i > 0 && buf[i-1] == ':'){
	opt++;
      } else {
	s++;
      }
    } else if(buf[i] == ')'){
      s--;
      if(i > 0 && buf[i-1] == ':')
	opt++;
    }
    if(s < 0){ // s == -1
      if(opt == 0) return false;
      opt--;
      s++;
    }
  }
  return (s == 0);
}

int main()
{
  int casos;
  fgets(buf, 505, stdin);
  sscanf(buf, " %d", &casos);
  for(int h = 1; h <= casos; h++){
    fgets(buf, 505, stdin);
    printf("Case #%d: %s\n", h, (solve() ? "YES" : "NO"));
  }
  return 0;
}
