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
    int n;
    scanf("%d\n", &n);
    bool para = false;
    int a = 0;
    for(int i = 0; i < n; i++){
      gets(buf);
      int x;
      if(!para){
	switch(buf[0]){
	case 'H':
	  para = true;
	  break;
	case 'T':
	  a += 180;
	  break;
	case 'L':
	  x = 90;
	  sscanf(buf, "LEFT %d", &x);
	  a -= x;
	  break;
	case 'R':
	  x = 90;
	  sscanf(buf, "RIGHT %d", &x);
	  a += x;
	  break;
	}
      }
    }
    a = (((a % 360) + 360)%360);
    printf("%d\n", a);
  }
  return 0;
}
