#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

char buf[200];

int main()
{
  int casos;
  scanf("%d\n", &casos);
  while(casos--){
    gets(buf);
    stack<char> P;
    for(int i = 0; buf[i]; i++){
      switch(buf[i]){
      case '_':
	if(P.empty() || P.top() != '_'){
	  printf("<i>");
	  P.push('_');
	} else{
	  P.pop();
	  printf("</i>");
	}
	break;
      case '*':
	if(P.empty() || P.top() != '*'){
	  printf("<b>");
	  P.push('*');
	} else{
	  P.pop();
	  printf("</b>");
	}
	break;
      default:
	putchar(buf[i]);
	break;
      }
    }
    putchar('\n');
  }
  return 0;
}
