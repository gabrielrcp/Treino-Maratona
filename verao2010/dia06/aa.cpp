#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(getchar() != '\n');
  while(casos--){
    bool up = true;
    char c;
    while((c = getchar()) != '\n'){
      if(c == ' ')
	putchar(c);
      else if(up)
	putchar(toupper(c));
      else
	putchar(tolower(c));
      up = (!up);
    }
    printf("\n");
  }
  return 0;
}

