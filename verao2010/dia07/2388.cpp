#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char mat[70][2][10];
int n;

int perm[4];

int liga[26];

int liga_tmp1[26];
int liga_tmp2[26];

bool confere()
{
  /*  
  for(int j = 0; j < 4; j++)
    printf("%d ", perm[j]);
  printf("\n");
  */

  memset(liga_tmp1, -1, sizeof liga_tmp1);
  memset(liga_tmp2, -1, sizeof liga_tmp2);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++){
      int a = mat[i][0][j];
      int b = mat[i][1][perm[j]];
      if(liga_tmp1[a] != b && liga_tmp1[a] != -1)
	return false;
      if(liga_tmp2[b] != a && liga_tmp2[b] != -1)
	return false;
      liga_tmp1[a] = b;
      liga_tmp2[b] = a;
    }
  }

  return true;
}

void ajusta()
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++){
      int a = mat[i][0][j];
      int b = mat[i][1][perm[j]];
      if(liga[a] == -1 || liga[a] == b){
	liga[a] = b;
      }
      else{
	liga[a] = -2;
      }
    }
  }
}


int main()
{
  for(int h = 1; scanf(" %d", &n) && n > 0; h++){

    for(int j = 0; j < 2; j++)
      for(int i = 0; i < n; i++){
	scanf(" %s", mat[i][j]);
	for(int k = 0; k < 4; k++)
	  mat[i][j][k] -= (j == 0 ? 'A' : 'a');
      }

    memset(liga, -1, sizeof liga);

    for(int i = 0; i < 4; i++)
      perm[i] = i;
    do{
      if(confere()){
	//printf("a\n");
	ajusta();
      }
    }while(next_permutation(perm, perm+4));


    for(int i = 0; i < 4; i++){
      int c = 0, s = 0, g, ult;
      for(int j = 0; j < 5; j++){
	int k = 5*i+j;
	if(liga[k] >= 0){
	  s += (liga[k]%5);
	  g = (liga[k]/5);
	} else{
	  c++;
	  ult = k;
	}
      }
      if(c == 1){
	liga[ult] = 10 - s + g*5;
      }
    }

    printf("Test #%d:\n", h);
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 5; j++){
	if(j != 0) printf(" ");
	int k = 5*i+j;
	printf("%c-%c", k+'A', (liga[k] < 0 ? '?' : liga[k]+'a'));
      }
      printf("\n");
    }
  }
  return 0;
}
