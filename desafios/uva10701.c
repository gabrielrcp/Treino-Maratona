/* Pre, in and Post */
/* UVA 10701 */
/* Accepted */

#include <stdio.h>

#define MAX 60

void imprime(int n, char *s1, char *s2)
{
  int i;
  char r;

  if(n == 1)
    putchar(*s1);

  if(n <= 1)
    return;

  r = *s1;
  for(i = 0; i < n; i++)
    if(s2[i] == r)
      break;

  imprime(i, s1+1, s2);
  imprime(n-1-i, s1+i+1, s2+i+1);
  putchar(r);

}

int main()
{
  int c, n;
  char s1[MAX], s2[MAX];

  scanf(" %d", &c);
  while(c--)
    {
      scanf(" %d %s %s", &n, s1, s2);
      imprime(n, s1, s2);
      putchar('\n');
    }
  return 0;
}
