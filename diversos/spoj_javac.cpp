#include <cstdio>
#include <cctype>
#include <cstring>

char s[1000];

int main()
{
  while(scanf(" %s", s) == 1){
    bool ej = false, ec = false;
    bool fail = false;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
      if(isupper(s[i]))
	ej = true;
      if(s[i] == '_'){
	ec = true;
	if(i == 0 || s[i-1] == '_')
	  fail = true;
      }
    }
    if(fail || (ec && ej) || isupper(s[0]) || s[n-1] == '_'){
      printf("Error!\n");
      continue;
    }

    bool up = false;
    for(int i = 0; i < n; i++){
      if(s[i] == '_'){
	up = true;
      }else if(up){
	putchar(toupper(s[i]));
	up = false;
      } else{
	if(isupper(s[i]))
	  putchar('_');
	putchar(tolower(s[i]));
      }
    }
    puts("");
  }
  return 0;
}
