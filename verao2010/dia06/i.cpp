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

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int r, c;
    scanf(" %d %d", &r, &c);
    bool ini = (r % 2 == 1);

    printf("%d\n", r);

    for(int i = 0; i < r; i++){
      bool at = ini;
      for(int j = 0; j < c; j++){
	printf("%c", (at ? '.' : 'X'));
	at = (!at);
      }
      printf("\n");
      ini = (!ini);
    }
  }
  return 0;
}

