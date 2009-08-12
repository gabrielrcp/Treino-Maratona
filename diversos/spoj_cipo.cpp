#include <vector>
#include <cstdio>

using namespace std;


#define MAX 1010

typedef pair<int, int> pii;

vector<pii> art[3];
int cor[MAX];

int custo[3] = { 1235, 8977, 10923};

int main()
{
  for(int h = 1; ; h++){
    int n, m;
    if(feof(stdin))
      break;
    if(scanf(" %d %d", &n, &m) == 0)
      break;
    if(feof(stdin))
      break;

    for(int i = 0; i < n; i++)
      cor[i] = i;
    for(int i = 0; i < 3; i++)
      art[i].clear();

    while(m--){
      int i, j, c;
      scanf(" %d %d %d", &i, &j, &c);
      i--; j--;
      switch(c){
      case 1235:
	art[0].push_back(make_pair(i, j));
	break;
      case 8977:
	art[1].push_back(make_pair(i, j));
	break;
      case 10923:
	art[2].push_back(make_pair(i, j));
	break;
      }
    }
    
    int resp = 0;
    for(int l = 0; l < 3; l++){
      for(int k = 0; k < art[l].size(); k++){
	int i = art[l][k].first;
	int j = art[l][k].second;
	if(cor[i] != cor[j]){
	  resp += custo[l];
	  int c = cor[j];
	  for(int p = 0; p < n; p++){
	    if(cor[p] == c)
	      cor[p] = cor[i];
	  }
	}
      }
    }
    printf("Instancia %d\n%d\n\n", h, resp);
  }

  return 0;
}
