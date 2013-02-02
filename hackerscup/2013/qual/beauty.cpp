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

#define MAX (10000)

char buf[MAX+10];
int conta[30];

int main()
{
  int casos;
  fgets(buf, MAX, stdin);
  sscanf(buf," %d", &casos);

  for(int h = 1; h <= casos; h++){
    fgets(buf, MAX, stdin);
    memset(conta, 0, sizeof conta);
    for(char *p = buf; *p; p++){
      if('A' <= *p && *p <= 'Z'){
	*p = *p - 'A' + 'a';
      }
      if('a' <= *p && *p <= 'z'){
	conta[(int)(*p - 'a')]++;
      }
    }
    sort(conta, conta+26);
    int resp = 0;
    for(int i = 25; i >= 0; i--){
      resp += conta[i] * (i+1);
    }
    printf("Case #%d: %d\n", h, resp);
  }

  return 0;
}
