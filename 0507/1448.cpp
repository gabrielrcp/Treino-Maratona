#include <cstdio>
#include <algorithm>

using namespace std;

int cubos[6][6][6];
int original[6][4];
int atual[6][4];

void ler()
{
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 36; j++){
      char c;
      do
	c = getchar();
      while(c != 'X' && c != '.');
      cubos[j/6][i][j%6] = c;
    }
}

bool interior_vazio()
{
  for(int k = 0; k < 6; k++)
    for(int i = 1; i+1 < 6; i++)
      for(int j = 1; j+1 < 6; j++)
	if(cubos[k][i][j] == '.')
	  return true;
  return false;

}

int inverte(int x)
{
  //printf("%x -> ", x);
  int y = 0;
  for(int i = 0; i < 6; i++){
    y <<= 1;
    if(x & 1)
      y |= 1;
    x >>= 1;
  }
  //printf("%x\n", y);
  return y;
}

inline bool match(int k1, int l1, int k2, int l2, bool orient)
{
  int x = atual[k1][l1];
  int y = atual[k2][l2];
  
  if(!orient)
    y = inverte(y);
  

  if((x & y) || ((x | y | 0x21) != 63)){
    /*
    if(x == 0x12 && y == 0xc)
      printf("%x %x\n", x, y);
    */
    return false;
  }
  return true;
}

void rodar(int k)
{
  int x  = atual[k][0];
  for(int j = 1; j < 4; j++)
    atual[k][j-1] = atual[k][j];
  atual[k][3] = inverte(x);
  atual[k][1] = inverte(atual[k][1]);
}


void gira(int k)
{
  for(int j = 1; j < 4; j += 2)
    atual[k][j] = inverte(atual[k][j]);
  int x = atual[k][0];
  atual[k][0] = atual[k][2];
  atual[k][2] = x;
}


bool conferecantos()
{
  int pri = 1;
  int ult = 1 << 5;
  if(!((atual[0][1] & pri) | (atual[1][0] & pri) | (atual[3][2] & pri)))
    return false;
  if(!((atual[0][1] & ult) | (atual[1][3] & ult) | (atual[2][0] & pri)))
    return false;
  if(!((atual[1][0] & ult) | (atual[3][1] & ult) | (atual[4][0] & pri)))
    return false;
  if(!((atual[1][1] & ult) | (atual[2][0] & ult) | (atual[4][3] & ult)))
    return false;
  if(!((atual[3][0] & ult) | (atual[4][0] & ult) | (atual[5][0] & pri)))
    return false;
  if(!((atual[2][2] & ult) | (atual[4][2] & ult) | (atual[5][2] & pri)))
    return false;
  if(!((atual[0][0] & pri) | (atual[3][0] & pri) | (atual[5][0] & ult)))
    return false;
  if(!((atual[0][2] & pri) | (atual[2][2] & pri) | (atual[5][2] & ult)))
    return false;

  return true;
}



bool tentarodar(int *perm)
{

  for(int j = 0; j < 4; j++)
    atual[1][j] = original[perm[0]][j];

  for(int r1 = 0; r1 < 8; r1++){
    if(r1 == 4)
      gira(1);
    rodar(1);

    if(!match(0, 1, 1, 3, true))
      continue;

    for(int j = 0; j < 4; j++)
      atual[2][j] = original[perm[1]][j];
    for(int r2 = 0; r2 < 8; r2++){
      if(r2 == 4)
	gira(2);
      rodar(2);

      if(!match(0, 2, 2, 3, false))
	continue;
      if(!match(1, 2, 2, 0, true))
	continue;


      for(int j = 0; j < 4; j++)
	atual[3][j] = original[perm[2]][j];
      for(int r3 = 0; r3 < 8; r3++){
	if(r3 == 4)
	  gira(3);
	rodar(3);

	if(!match(0, 0, 3, 3, true))
	  continue;
	if(!match(1, 0, 3, 2, true))
	  continue;

	for(int j = 0; j < 4; j++)
	  atual[4][j] = original[perm[3]][j];
	for(int r4 = 0; r4 < 8; r4++){
	  if(r4 == 4)
	    gira(4);
	  rodar(4);

	  if(!match(1, 1, 4, 3, true))
	    continue;
	  if(!match(2, 1, 4, 2, true))
	    continue;
	  if(!match(3, 1, 4, 0, false))
	    continue;

	  for(int j = 0; j < 4; j++)
	    atual[5][j] = original[perm[4]][j];
	  for(int r5 = 0; r5 < 8; r5++){
	    if(r5 == 4)
	      gira(5);
	    rodar(5);

	    if(!match(0, 3, 5, 1, true))
	      continue;
	    if(!match(2, 2, 5, 2, false))
	      continue;
	    if(!match(3, 0, 5, 0, false))
	      continue;
	    if(!match(4, 1, 5, 3, true))
	      continue;

	    if(conferecantos())
	      return true;
	  }
	}
      }
    }
  }

  return false;
}


bool resolve()
{
  
  if(interior_vazio())
    return false;
  

  for(int k = 0; k < 6; k++){
    
    original[k][0] = 0;    
    for(int j = 0; j < 6; j++)
      if(cubos[k][0][j] != '.')
	original[k][0] |= (1 << j);

    original[k][3] = 0;
    for(int i = 0; i < 6; i++)
      if(cubos[k][i][0] != '.')
	original[k][3] |= (1 << i);

    original[k][2] = 0;
    for(int j = 0; j < 6; j++)
      if(cubos[k][5][j] != '.')
	original[k][2] |= (1 << j);

    original[k][1] = 0;
    for(int i = 0; i < 6; i++)
      if(cubos[k][i][5] != '.')
	original[k][1] |= (1 << i);
  }


  int perm[5] = {1, 2, 3, 4, 5};
  for(int j = 0; j < 4; j++)
    atual[0][j] = original[0][j];

  do{
    if(tentarodar(perm))
      return true;
  }while(next_permutation(perm, perm+5));

  return false;
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("Scenario #%d:\n", h);
    ler();
    /*
    for(int k = 0; k < 6; k++){
      for(int i = 0; i < 6; i++){
	for(int j = 0; j < 6; j++)
	  printf("%c", cubos[k][i][j]);
	printf("\n");
      }
      printf("\n");
    }
    */

    if(resolve())
      printf("Yes\n\n");
    else
      printf("No\n\n");
  }
  return 0;
}
