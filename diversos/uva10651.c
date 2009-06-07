#include <stdio.h>

/* 2^12 */
#define MAX 4096

char tab[12];
char minimo[MAX];


int codigo()
{
  int s = 0;
  int i;
  for(i=0; i<12; i++){
    s  = s << 1;
    s += tab[i];
  }
  return s;
}


int minjog()
{
  int jog = codigo();
  int i;
  int min, at;

  if(minimo[jog] != -1)
    return minimo[jog];

  min = 0;
  for(i=0; i<12; i++)
    min += tab[i];

  for(i=0; i<10; i++){
    if(tab[i] == 1 && tab[i+1] == 1 && tab[i+2] == 0){
      tab[i] = 0;
      tab[i+1] = 0;
      tab[i+2] = 1;
      at = minjog();
      if(at < min)
	min = at;
      tab[i] = 1;
      tab[i+1] = 1;
      tab[i+2] = 0;
    }

    if(tab[i] == 0 && tab[i+1] == 1 && tab[i+2] == 1){
      tab[i] = 1;
      tab[i+1] = 0;
      tab[i+2] = 0;
      at = minjog();
      if(at < min)
	min = at;
      tab[i] = 0;
      tab[i+1] = 1;
      tab[i+2] = 1;
    }

  }

  minimo[jog] = min;
  return min;
}


int main()
{
  int n;
  int i;
  char c;
  scanf(" %d", &n);

  for(i=0; i<MAX; i++)
    minimo[i] = -1;

  while(n--)
    {
      for(i=0; i<12; i++){
	do{
	  c = getchar();
	}while(c != 'o' && c != '-');
	tab[i] = ((c == 'o') ? 1 : 0);
      }
      printf("%d\n", minjog());
    }
  return 0;
}
