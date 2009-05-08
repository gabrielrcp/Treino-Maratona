#include <cstdio>
#include <algorithm>

using namespace std;

char original[6][6][6];
char cubo[6][6][6];

void ler()
{
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 36; j++){
      char c;
      do
	c = getchar();
      while(c != 'X' && c != '.');
      cubo[j%6][i][j] = c;
    }
}

bool interior_vazio()
{
  for(int k = 0; k < 6; k++)
    for(int i = 1; i+1 < 6; i++)
      for(int j = 1; j+1 < 6; j++)
	if(cubo[k][i][j] == '.')
	  return true;
  return false;

}

void girar(int k)
{
  char temp[6][6];
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
      temp[5-j][5-i] = original[k][i][j];

  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
      cubo[k][i][j] = temp[i][j];
}


void trocar(int *perm, int *orient)
{
  for(int i = 1; i < 6; i++)
    for(int j = 0; j < 6; j++)
      for(int k = 0; k < 6; k++)
	cubo[i][j][k] = original[perm[i-1]][j][k];

  for(int i = 0; i < 6; i++)
    for(int j = 0; j < orient[i]; j++)
      girar(i);
}

bool montagem()
{
  for(int k = 0; k <= 3; k++){
    int kl = (k+1) % 4;
    for(int i = 0; i < 6; i++)
      if(cubo[k][i][5] == cubo[kl][i][0])
	return false;
  }

  for(int i = 0; i < 6; i++){
    
  }

  return true;
}


bool resolve()
{
  if(interior_vazio())
    return false;


  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
      for(int k = 0; k < 6; k++)
	original[i][j][k] = cubo[i][j][k];

  int perm[5] = {1, 2, 3, 4, 5};
  int orientacao[6];
  
  do{
    for(int a0 = 0; a0 < 4; a0++)
      for(int a1 = 0; a1 < 4; a1++)
	for(int a2 = 0; a2 < 4; a2++)
	  for(int a3 = 0; a3 < 4; a3++)
	    for(int a4 = 0; a4 < 4; a4++)
	      for(int a5 = 0; a5 < 4; a5++){
		orientacao[0] = a0;
		orientacao[1] = a1;
		orientacao[2] = a2;
		orientacao[3] = a3;
		orientacao[4] = a4;
		orientacao[5] = a5;
	      }

    trocar(perm, orientacao);

    if(montagem())
      return true;

  }while(next_permutation(perm, perm+5));
  
  return false;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("Scenario #%d\n", h);
    ler();
    
    if(resolve())
      printf("Yes\n\n");
    else
      printf("No\n\n");
  }
  return 0;
}
