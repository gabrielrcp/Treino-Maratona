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

int area[55];
char cor[55];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
      scanf(" %d", area+i);

    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      int x;
      scanf(" %d", &x);
      area[i] *= x;
    }
    scanf(" %s", cor);


    int r = 0, g = 0, b = 0;


  }
  return 0;
}

