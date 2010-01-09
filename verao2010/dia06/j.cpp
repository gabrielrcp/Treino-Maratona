#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[55], b[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %s %s", a, b);
    int i = 0, j = 0;
    while(a[i] && b[j]){
      if(a[i] >= b[j] ){
	putchar(a[i]);
	i++;
      } else{
	putchar(b[j]);
	j++;
      }
    }
    while(a[i]){
      putchar(a[i]);
      i++;
    }
    while(b[j]){
      putchar(b[j]);
      j++;
    }
    putchar('\n');
  }
  return 0;
}

