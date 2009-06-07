/* Tex Quotes */
/* UVA Problema 272   */
/* Accepted */

#include <stdio.h>


int main()
{
  int c, aberto;

  aberto = 0;
  while((c = getchar()) != EOF)
    {
      if(c == '"')
	{
	  if(aberto)
	    printf("''");
	  else
	    printf("``");
	  aberto = 1 - aberto;
	}
      else
	putchar(c);
    }
  return 0;
}
