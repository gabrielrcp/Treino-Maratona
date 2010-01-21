#include <cstdio>
#include <set>

using namespace std;

#define MAX 1000000

char str[MAX];

int main()
{
  freopen("words.in", "r", stdin);
  freopen("words.out", "w", stdout);

  for(int h = 1; ; h++){
    if(scanf(" %s", str) != 1) break;

    set<char> S;
    for(int i = 0; str[i]; i++)
      S.insert(str[i]);

    int total = S.size();
    S.clear();
    int resp = 0;
    for(int i = 0; str[i]; i++){
      S.insert(str[i]);
      if((int)S.size() == total){
	S.clear();
	resp++;
      }
    }
    printf("String %d: %d\n", h, resp);
  }
  return 0;
}
