#include <stdio.h>

/*int conta;*/
int ler()
{
  int wl, dl, wr, dr;

  scanf(" %d %d %d %d", &wl, &dl, &wr, &dr);
  /*conta++;*/
  if(wl == 0)
    wl = ler();
  if(wr == 0)
    wr = ler();

  if(wl == 0 || wr == 0)
    return 0;

  if(wr * dr == wl * dl)
    return (wr + wl);
  return 0;
}

int main()
{
  int n, h;
  scanf(" %d", &n);
  /*conta = 0;*/
  for(h=0; h < n; h++)
    {
      if(h)
	putchar('\n');
      if(ler() == 0)
	printf("NO\n");
      else
	printf("YES\n");
    }
  /*printf("%d\n", conta);*/
  return 0;
}
