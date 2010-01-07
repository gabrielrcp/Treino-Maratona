#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

vector<string> resp;
vector<string> nomes;
char buf[500];

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    resp.clear();
    nomes.clear();

    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %s", buf);
      nomes.push_back(buf);
    }
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
      scanf(" %s", buf);
      int s=0, t=0;
      for(int j = 0; buf[j]; j++){
	if(buf[j] == 'A')
	  t++;
	else if(buf[j] == 'P'){
	  s++; t++;
	}
      }
      if(100*s < 75*t)
	resp.push_back(nomes[i]);
    }

    printf("%u\n", resp.size());
    for(int i = 0; i < (int)resp.size(); i++)
      printf("%s\n", resp[i].c_str());
  }
  return 0;
}
