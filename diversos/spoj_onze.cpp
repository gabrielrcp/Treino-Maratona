#include <cstdio>
#include <cstring>

int big[500];
int tam;

char buf[1010];

int resto(int x)
{
  int r = 0;
  for(int i = tam - 1; i >= 0; i--){
    r = r*1000 + big[i];
    r %= x;
  }
  return r;
}

int main()
{
  while(1){
    scanf(" %s", buf);
    if(buf[0] == '0' && buf[1] == '\0')
      break;

    printf("%s is", buf);
    tam = 0;
    for(int i = strlen(buf)-1; i >= 0; i -= 3){
      big[tam] = 0;
      int p = 1;
      for(int j = 0; j < 3 && i-j >= 0; j++){
	big[tam] += p*(buf[i-j] - '0');
	p *= 10;
      }
      tam++;
    }
    if(resto(11) != 0)
      printf(" not");
    printf(" a multiple of 11.\n");

  }
}
