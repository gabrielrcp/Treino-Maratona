#include <cstdio>
#include <cstring>
#include <cctype>

char buf[1010];

int main()
{
  while(1){
    char c;
    int n = 1;
    while(!isdigit(c = getchar_unlocked()));

    buf[0] = c;
    while(isdigit(c = getchar_unlocked()))
      buf[n++] = c;
    buf[n] = '\0';

    if(n == 1 && buf[0] == '0')
      break;

    printf("%s is", buf);

    int r = 0;
    for(int i = 0; i < n; i++){
      r = r*10 + buf[i]-'0';
      r %= 11;
    }

    if(r)
      printf(" not");
    printf(" a multiple of 11.\n");

  }
}
