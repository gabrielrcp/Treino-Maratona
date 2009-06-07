/* The Decoder */
/* UVA 458 */
/* Accepted */

#include <stdio.h>

#define SOMA -7

int main()
{
  int c;
  /*printf("%d - %c\n%d - %c\n", '1', '1', '*', '*');*/
  
  while((c = getchar()) != EOF)
    {
      if(c == '\n'){
	putchar(c);
	continue;
      }
      c += SOMA;
      /*
      if(c > 126){
	c -= 126;
	c += 31;
      }
      */
      putchar(c);
    }

  return 0;
}
