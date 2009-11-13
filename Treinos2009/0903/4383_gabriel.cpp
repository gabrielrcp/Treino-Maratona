#include <cstdio>
#include <algorithm>

using namespace std;


#define MAX 1000010

int n, d;

int alt[MAX];
pair<int, int> predios[MAX];
char ponta[MAX];


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d", &n, &d);

    for(int i = 0; i < n; i++){
      int h;
      scanf(" %d", &h);
      predios[i] = make_pair(h, i);
      alt[i] = h;
      ponta[i] = 0;
    }
    if(n > 1){
      ponta[0] = -1;
      ponta[n-1] = 1;
    }
    else
      ponta[0] = 2; 

    sort(predios, predios+n);

    int r = 1;
    int at = 0;
    while(d--){
      int h;
      scanf(" %d", &h);
      while(at < n && predios[at].first <= h){
	int i = predios[at].second;
	switch(ponta[i]){
	case 0: //meio do intervalo
	  ponta[i-1] = (ponta[i-1] == 0 ?  1 : 2);
	  ponta[i+1] = (ponta[i+1] == 0 ? -1 : 2);
	  r++;
	  break;
	case -1: //esquerda
	  ponta[i+1] = (ponta[i+1] == 0 ? -1 : 2);
	  break;
	case 1: //direita
	  ponta[i-1] = (ponta[i-1] == 0 ? 1 : 2);
	  break;
	case 2: //unico ponto
	  r--;
	  break;
	}
	at++;
      }
      printf("%d ", r);
    }
    printf("\n");

  }
  return 0;
}
