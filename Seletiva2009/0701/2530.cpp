#include <cstdio>

int n;
char matriz[55][25];

bool vazio()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 20; j++)
      if(matriz[i][j] != '.')
	return false;
  return true;
}


bool pode(char c)
{
  bool achei = false;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 20; j++){
      if(matriz[i][j] != c) continue;
      achei = true;
      for(int k = i+1; k < n; k++){
	if(matriz[k][j] != c && matriz[k][j] != '.')
	  return false;
      }
    }
  return achei;
}

void remover(char c)
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 20; j++)
      if(matriz[i][j] == c)
	matriz[i][j] = '.';
}


char tira()
{
  if(vazio())
    return '.';
  for(char c = 'A'; c <= 'Z'; c++){
    if(pode(c)){
      remover(c);
      return c;
    }
  }
}


int main()
{
  scanf(" %d", &n);
  for(int i = 0; i  < n; i++)
    for(int j = 0; j < 20; j++)
      scanf(" %c", &matriz[i][j]);
  
  while(1){
    char c = tira();
    if(c == '.')
      break;
    printf("%c", c);
  }
  printf("\n");
  return 0;
}
