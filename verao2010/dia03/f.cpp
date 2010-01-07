#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n, s = 0;
    scanf(" %d", &n);
    char buf[200];
    for(int i = 0; i < n; i++){
      scanf(" %s", buf);
      for(int j = 0; buf[j]; j++){
	s += i + j + buf[j]-'A';
      }
    }
    printf("%d\n", s);
  }
  return 0;
}
