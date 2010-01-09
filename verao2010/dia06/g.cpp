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

int c[10] = {6,2,5,5,4,5,6,3,7,6};

char buf[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %s", buf);
    int s = 0;
    for(int i = 0; buf[i]; i++){
      s += c[buf[i]-'0'];
    }
    printf("%d\n", s);
  }
  return 0;
}

