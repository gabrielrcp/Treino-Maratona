#include <stdio.h>

int num[256];
char disp[100];
int ndisp;
char saida[1000];
int tam;

void geracombi(int ini)
{
  int i;
  if(ini == tam){
    printf("%s\n", saida);
    return;
  }

  for(i=0; i<ndisp; i++)
    if(num[(int)disp[i]] > 0){
      saida[ini] = disp[i];
      num[(int)disp[i]]--;
      geracombi(ini+1);
      num[(int)disp[i]]++;
    }
}

int main()
{
  int n;
  char buf[1000];
  int i;

  scanf(" %d", &n);
  while(n--)
    {
      scanf(" %s", buf);
      for(i=0; i<256; i++)
	num[i] = 0;
      ndisp = 0;

      for(i=0; buf[i] != '\0'; i++)
	num[(int)buf[i]]++;
      tam = i;

      for(i = 'A'; i <= 'Z'; i++){
	if(num[i] > 0)
	  disp[ndisp++] = (char)i;
	if(num[i-'A'+'a'] > 0)
	  disp[ndisp++] = (char)i-'A'+'a';
      }

      saida[tam] = '\0';
      geracombi(0);
    }
  return 0;
}
