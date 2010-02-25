#include <cstdio>
#include <cstring>
#include <cctype>

char buf[1010];

int main()
{
  while(1){
    char c;
    int i = 0;
    while(!isdigit(c = getchar_unlocked()));

    buf[0] = c;
    while(isdigit(c = getchar_unlocked()))
      buf[++i] = c;

    if(i == 0 && buf[0] == '0')
      break;

    printf("%s is", buf);

    int r = 0;
    for(; i >= 0; i--){
      r = r*10 + buf[i]-'0';
      r %= 11;
    }

    if(r)
      printf(" not");
    printf(" a multiple of 11.\n");

  }
}
