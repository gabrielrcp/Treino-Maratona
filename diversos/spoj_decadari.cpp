#include <cstdio>

int ler()
{
  char buf[20];
  if(feof(stdin))
    return -1;
  if(scanf(" %s", buf) != 1)
    return -1;
  for(int i = 0; buf[i]; i++)
    buf[i] -= '0';
  
  int h = buf[0]*10+ buf[1];
  int m = buf[2]*10+ buf[3];
  int s = buf[4]*10+ buf[5];
  int c = buf[6]*10+ buf[7];

  return c + 100*s + 100*60*m + 100*60*60*h;
}

int chao(double x)
{
  return (int)(x+1.0e-9);
}

int main()
{
  while(1){
    int x = ler();
    if(x == -1) break;

    //printf("%d %d\n", x,  (100*60*60*24));

    double hp = (double)x / (100*60*60*24);
    hp *= 10;

    int h = chao(hp);
    hp -= h;

    hp *= 100;
    int m = chao(hp);
    hp -= m;

    hp *= 100;
    int s = chao(hp);
    hp -= s;

    hp *= 100;
    int c = chao(hp);

    printf("%d%02d%02d%02d\n", h, m, s, c);
  }
  return 0;
}
