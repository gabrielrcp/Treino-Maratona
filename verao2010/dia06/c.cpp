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

char s[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %s %d", s, &n);
    for(int i = 0; s[i]; i++){
      s[i] = s[i] - 'A';
      s[i] -= n;
      if(s[i] < 0) s[i] += 26;
      s[i] += 'A';
    }
    printf("%s\n", s);
  }
  return 0;
}

