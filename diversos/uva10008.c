#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char letra;
  int num;
} Letra;


Letra conta[30];


int compara(const void *a, const void *b)
{
  if(((Letra *)a)->num == ((Letra *)b)->num)
    return ((Letra *)a)->letra - ((Letra *)b)->letra;

  return ((Letra *)b)->num - ((Letra *)a)->num;
}

int main()
{
  int n;
  char c;
  int i;
  char buf[1000];


  gets(buf);
  sscanf(buf, " %d", &n);

  for(c='A'; c<='Z'; c++){
    conta[(int)c - 'A'].letra = c;
    conta[(int)c - 'A'].num = 0;
  }

  while(n--)
    {
      gets(buf);
      for(i=0; buf[i]; i++){
	c = buf[i];

	if(c >= 'A' && c <= 'Z')
	  conta[(int)c - 'A'].num++;
	else if(c >= 'a' && c <= 'z')
	  conta[(int)c - 'a'].num++;
      }
    }

  qsort(conta, 'Z' - 'A' + 1, sizeof(Letra), compara);

  for(i=0; i <= 'Z' - 'A'; i++)
    if(conta[i].num != 0)
      printf("%c %d\n", conta[i].letra, conta[i].num);
    else
      break;

  return 0;
}
