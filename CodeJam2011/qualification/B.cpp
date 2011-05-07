#include <cstdio>
#include <vector>

using namespace std;

int C, D, N;
char comb[50][10];
char dest[50][10];

int tam;
char resp[100];


char iguais(char a, char b, char c, char d)
{
  if(a == c && b == d) return 1;
  return (a == d && b == c);
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf(" %d", &C);
    for(int i = 0; i < C; i++){
      scanf(" %s", comb[i]);
    }
   scanf(" %d", &D);
    for(int i = 0; i < D; i++){
      scanf(" %s", dest[i]);
    }
    
    tam = 0;
    scanf(" %d", &N);
    for(int i = 0; i < N; i++){
      scanf(" %c", resp+tam);
      if(tam >= 1){
	for(int j = 0; j < C; j++){
	  if(iguais(resp[tam], resp[tam-1], comb[j][0], comb[j][1])){
	    resp[--tam] = comb[j][2];
	    break;
	  }
	}
      }

      if(tam >= 1){
	for(int j = 0; j < D; j++){
	  char ap0 = 0, ap1 = 0;
	  for(int k = 0; k <= tam; k++){
	    if(resp[k] == dest[j][0])
	      ap0 = 1;
	    if(resp[k] == dest[j][1])
	      ap1 = 1;
	  }
	  if(ap0 && ap1){
	    tam = -1;
	    break;
	  }
	}
      }
      tam++;
    }

    printf("Case #%d: [", h);
    for(int i = 0; i < tam; i++){
      if(i != 0) printf(", ");
      printf("%c", resp[i]);
    }
    printf("]\n");
  }
  return 0;
}
