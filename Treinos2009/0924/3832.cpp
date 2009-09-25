#include <cstdio>
#include <cstring>

int tamlinha()
{
  int r = 0;
  char c;
  while(c = getchar()){
    if(c == EOF)
      return -1;
    if(c == '\n')
      return r;
    r++;
  }
}

int main()
{
  while(1){
    int r = tamlinha();
    if(r == -1)
      break;
    if(r > 20) while(1);
  }
  return 0;
}
