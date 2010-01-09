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

char buf[10];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %s", buf);
    if('0' <= buf[0] && buf[0] <= '9'){
      int x;
      sscanf(buf, "%d", &x);
      x--;
      int l = (x%8);
      int num = (x / 8);
      printf("%c%d\n", l+'a', num+1);
    }
    else{
      char c; int a, b;
      sscanf(buf, "%c%d", &c, &b);
      a = c - 'a';
      b--;
      printf("%d\n", 8*b + a + 1);
    }
  }
  return 0;
}

