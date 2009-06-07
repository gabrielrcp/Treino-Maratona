#include <stdio.h>

#define MAX 100000

int main()
{
  char palavra[MAX];
  int i, j;

  while(42){

    i = -1;
    do{
      i++;
      palavra[i] = getchar();
    }while(palavra[i] != EOF && palavra[i] != '\n' && palavra[i] != ' ');

    for(j=i-1; j>=0; j--)
      putchar(palavra[j]);

    if(palavra[i] == EOF)
      break;
    putchar(palavra[i]);
  }
  return 0;
}
