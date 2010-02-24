#include <cstdio>

char buf[1010];

int main()
{
  while(1){
    scanf(" %s", buf);
    if(buf[0] == '0' && buf[1] == '\0') break;
    int s = 0;
    for(int i = 0; buf[i]; i++)
      s += buf[i] - '0';
    int c = 1;
    while(s >= 10){
      int t = 0;
      while(s > 0){
	t += (s % 10);
	s /= 10;
      }
      s = t;
      c++;
    }
    printf("%s ", buf);
    if(s == 9)
      printf("is a multiple of 9 and has 9-degree %d.\n", c);
    else
      printf("is not a multiple of 9.\n");
  }
  return 0;
}
