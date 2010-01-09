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
    int a, b, c;
    scanf(" %d", &c);
    b = c / 12;
    c = c % 12;
    a = b / 20;
    b = b % 20;
    printf("3\n%d\n%d\n%d\n", a, b, c);
  }
  return 0;
}

