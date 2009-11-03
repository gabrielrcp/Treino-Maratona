#include <cstdio>

int valor(char c)
{
  switch(c){
  case 'W': return 64;
  case 'H': return 32;
  case 'Q': return 16;
  case 'E': return 8;
  case 'S': return 4;
  case 'T': return 2;
  case 'X': return 1;
  }
}

char buf[500];

int main()
{
  while(scanf(" %s", buf) && *buf != '*'){
    int r = 0, soma = 0;
    for(char *s = buf; *s; s++){
      if(*s == '/'){
	if(soma == 64) r++;
	soma = 0;
      }
      else
	soma += valor(*s);
    }
    printf("%d\n", r);
  }
  return 0;
}
