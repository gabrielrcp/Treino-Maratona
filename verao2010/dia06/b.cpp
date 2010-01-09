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
    int n;
    scanf(" %d", &n);

    set<int> S;
    for(int i = 0; i < n; i++){
      int x;
      scanf(" %d", &x);
      S.insert(x);
    }

    if(S.size() < 3)
      printf("-1\n");
    else{
      set<int>::iterator it = S.begin();
      it++; it++;
      printf("%d\n", *it);
    }
  }
  return 0;
}

