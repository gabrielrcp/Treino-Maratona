#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

char b[55];
vector<string> linhas;

bool match(string x, string y)
{
  if(x.size() < y.size()) return false;
  for(int i = 0; i < (int)y.size(); i++){
    if(x[i] != y[i])
      return false;
  }
  return true;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    for(int i = 0; i < n; i++){
      gets(b);
      linhas.push_back(b);
    }
    gets(b);
    int r = strlen(b);
    b[r] = ':'; b[r+1] = '\0';

    int s = 0;
    for(int i = 0; i < n; i++){
      if(match(linhas[i], b))
	s++;
    }
    printf("%d\n", s);
  }
  return 0;
}

