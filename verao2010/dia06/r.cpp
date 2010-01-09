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
    int maxAdd, goal, next;
    scanf(" %d %d %d", &maxAdd, &goal, &next);

    if(goal < next + maxAdd){
      printf("%d\n", goal - next);
    }
    else{
      int perde = goal;
      while(perde >= next)
	perde -= (maxAdd +1);
      perde += maxAdd + 1;
      if(perde == next)
	printf("%d\n", -1);
      else
	printf("%d\n", perde - next+1);
    }
  }
  return 0;
}

