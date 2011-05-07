#include <cstdio>
#include <vector>

using namespace std;



int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    vector<int> bot[2];
    vector<int> ord;
    int N;
    scanf(" %d", &N);
    for(int k = 0; k < N; k++){
      char c; int p;
      scanf(" %c %d", &c, &p);
      if(c == 'O'){
	bot[0].push_back(p);
	ord.push_back(0);
      } else{
	bot[1].push_back(p);
	ord.push_back(1);
      }
    }

    int i = 0, j = 0, k = 0, t = 0;
    int x = 1, y = 1;
    while(k < N){
      char apertei = 0;
      //printf("%d: %d %d\n", t, x, y);
      if(ord[k] == 0 && x == bot[0][i]){
	k++; i++;
	apertei = 1;
      } else if(i < (int)bot[0].size()){
	if(x < bot[0][i])
	  x++;
	else if(x > bot[0][i])
	  x--;
      }

      if((!apertei) && ord[k] == 1 && y == bot[1][j]){
	k++; j++;
      } else if(j < (int)bot[1].size()){
	if(y < bot[1][j])
	  y++;
	else if(y > bot[1][j])
	  y--;
      }
      t++;
    }
    printf("Case #%d: %d\n", h, t);
  }
  return 0;
}
