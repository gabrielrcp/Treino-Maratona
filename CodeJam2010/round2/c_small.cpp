#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define LIM (110)

char M[LIM][LIM];
char novo[LIM][LIM];


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    int R;
    scanf(" %d", &R);
    memset(M, 0, sizeof M);
    memset(novo, 0, sizeof novo);

    while(R--){
      int x1, y1, x2,y2;
      scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
      for(int x = x1; x <= x2; x++){
	for(int y = y1; y <= y2; y++){
	  M[x][y] = 1;
	}
      }
    }


    int t = 0;
    bool vazio = false;
    while(!vazio){
      vazio = true;

      for(int x = 1; x < LIM; x++){
	for(int y = 1; y < LIM; y++){
	  if(M[x][y] == 1){
	    if(M[x-1][y] == 1 || M[x][y-1] == 1)
	      novo[x][y] = 1;
	    else
	      novo[x][y] = 0;
	  } else{
	    if(M[x-1][y] == 1 && M[x][y-1] == 1)
	      novo[x][y] = 1;
	    else
	      novo[x][y] = 0;
	  }
	  if(novo[x][y] == 1) vazio = false;
	}
      }
      memcpy(M, novo, sizeof M);
      t++;
    }

    printf("Case #%d: %d\n", h, t);

  }
  return 0;
}
