#include <cstdio>
#include <cstring>

int z, n;
char codifica[300];

int posicoes[21];

bool valida()
{
  return false;
}

bool tenta(int pat, int ini)
{
  if(pat+1 == z)
    return valida();

  for(int i = ini; codifica[i] != '\0'; i++){
    posicoes[pat] = i;
    if(tenta(pat+1, i))
      return true;
  }
  return false;
}


void resolve()
{
  tenta(0, 0);

  printf("0->");
  for(int j = 0; j < posicoes[0]; j++)
    printf("%c", codifica[j]);
  printf("\n");


  posicoes[z-1] = strlen(codifica);
  for(int i = 1; i < z; i++){
    printf("%d->", i);
    for(int j = posicoes[i-1]; j < posicoes[i]; j++)
      printf("%c", codifica[j]);
    printf("\n");
  }
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %s", &z,&n, codifica);
    resolve();
  }
  return 0;
}
