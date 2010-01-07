#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

char minusc(char c)
{
  if('A' <= c && c <= 'Z')
    c = c - 'A' + 'a';
  return c;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    char ult = -1;
    bool foi = false;
    int conta = 0;
    char buf[500];
    for(int i = 0; i < n; i++){
      scanf(" %s", buf);
      char c = minusc(buf[0]);
      if(c == ult){
	if(!foi){
	  conta++;
	  foi = true;
	}
      } else{
	ult = c;
	foi = false;
      }
    }
    printf("%d\n", conta);
  }
  return 0;
}
