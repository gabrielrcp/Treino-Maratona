#include <cstdio>
#include <cstring>

int ler()
{
  char buf[50], buf2[50];
  int a, b;

  scanf(" %s", buf);
  for(int i = 0; buf[i]; i++)
    if(buf[i] == '.')
      buf[i] = ' ';
  sscanf(buf, "%d %s", &a, buf2);
  sscanf(buf2, " %d", &b);

  if(strlen(buf2) == 1){
    b *= 10;
  }

  return 100 * a + b;
}

char resolve()
{
  int a, g, ra, rg;
  a = ler();
  g = ler();
  ra = ler();
  rg = ler();

  return (a*rg < g*ra ? 'A' : 'G');
}

int main()
{
  putchar(resolve());
  puts("");
  return 0;
}
