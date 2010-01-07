#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

char s[200];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %s", s);
    int i = strlen(s) - 1;

    while(i >= 0){
      if(s[i] == '1')
	s[i] = '0';
      else{
	s[i] = '1';
	break;
      }
      i--;
    }
    if(i < 0) printf("1");
    printf("%s\n", s);
  }
  return 0;
}
