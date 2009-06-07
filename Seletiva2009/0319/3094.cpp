#include <cstdio>


char buf[500];

int main()
{
  while(1){
    gets(buf);
    if(buf[0] == '#')
      break;
    int s = 0;
    int i = 0;
    while(buf[i] != '\0'){
      if(buf[i] != ' ')
	s += ((int)(buf[i] - 'A' + 1)) * (i + 1);
      i++;
    }
    printf("%d\n", s);
  }
  return 0;
}
