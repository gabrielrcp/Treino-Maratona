#include <cstring>
#include <cstdio>

char buf[300], buf2[300];

int main()
{
  int n;
  scanf(" %d", &n);
  char *s = buf;
  char *ant = buf2;

  scanf(" %s", ant);
  int resp = strlen(ant);
  for(int i = 1; i < n; i++){
    scanf(" %s", s);
    int j = 0;
    for(j = 0; s[j] != '\0' && ant[j] != '\0'; j++)
      if(s[j] != ant[j])
	break;
    resp += strlen(s) - j + 1;
    char *t = ant;
    ant = s;
    s = t;
  }

  printf("%d\n", resp);


  return 0;
}
