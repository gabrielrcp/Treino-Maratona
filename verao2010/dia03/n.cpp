#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

char buf[200];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int s;
    scanf(" %d %s", &s, buf);

    int at = 1;
    for(int i = 0; buf[i]; i++){
      if(buf[i] == 'W'){
	s += at;
	at = 1;
      } else{
	s -= at;
	at *= 2;
	if(at > s) break;
      }
    }
    printf("%d\n", s);
  }
  return 0;
}
