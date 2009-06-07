/*
ID: gabriel9
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

char nomes[5000][15];

FILE *fin;
FILE *fout;
int n;

int achou = 0;


int achanome(char *nome)
{
  int a=0, b=n-1, c=0;
  int v;
  if(strcmp(nome, nomes[a]) == 0)
    return 1;
  if(strcmp(nome, nomes[b]) == 0)
    return 1;
  while(a < b-1){
    c = (a+b)/2;
    v = strcmp(nome, nomes[c]);
    if(v == 0)
      return 1;
    else if (v < 0)
      b = c;
    else
      a = c;
    /*
    printf("a=%d b=%d\n",a,b);
    */
  }
  if(strcmp(nome, nomes[c]) == 0)
    return 1;
  return 0;
}

void imprimenomes(char *cod, int ini)
{
  char at = cod[ini];

  switch(at){
    case '\0':
      if(achanome(cod)){
	fprintf(fout, "%s\n", cod);
	achou = 1;
      }
      return;
    case '2':
      cod[ini] = 'A';
      imprimenomes(cod, ini+1);

      cod[ini] = 'B';
      imprimenomes(cod, ini+1);

      cod[ini] = 'C';
      imprimenomes(cod, ini+1);
      break;
    case '3':
      cod[ini] = 'D';
      imprimenomes(cod, ini+1);

      cod[ini] = 'E';
      imprimenomes(cod, ini+1);

      cod[ini] = 'F';
      imprimenomes(cod, ini+1);
      break;
    case '4':
      cod[ini] = 'G';
      imprimenomes(cod, ini+1);

      cod[ini] = 'H';
      imprimenomes(cod, ini+1);

      cod[ini] = 'I';
      imprimenomes(cod, ini+1);
      break;
    case '5':
      cod[ini] = 'J';
      imprimenomes(cod, ini+1);

      cod[ini] = 'K';
      imprimenomes(cod, ini+1);

      cod[ini] = 'L';
      imprimenomes(cod, ini+1);
      break;
    case '6':
      cod[ini] = 'M';
      imprimenomes(cod, ini+1);

      cod[ini] = 'N';
      imprimenomes(cod, ini+1);

      cod[ini] = 'O';
      imprimenomes(cod, ini+1);
      break;
    case '7':
      cod[ini] = 'P';
      imprimenomes(cod, ini+1);

      cod[ini] = 'R';
      imprimenomes(cod, ini+1);

      cod[ini] = 'S';
      imprimenomes(cod, ini+1);
      break;
    case '8':
      cod[ini] = 'T';
      imprimenomes(cod, ini+1);

      cod[ini] = 'U';
      imprimenomes(cod, ini+1);

      cod[ini] = 'V';
      imprimenomes(cod, ini+1);
      break;
    case '9':
      cod[ini] = 'W';
      imprimenomes(cod, ini+1);

      cod[ini] = 'X';
      imprimenomes(cod, ini+1);

      cod[ini] = 'Y';
      imprimenomes(cod, ini+1);
      break;
  }
  cod[ini] = at;
}


int main()
{
  FILE *fdic = fopen("dict.txt", "r");
  char cod[15];

  
  fin = fopen("namenum.in", "r");
  fout = fopen("namenum.out", "w");
  /*
  fin = stdin;
  fout = stdout;
  */
  n=0;
  while(fscanf(fdic, "%s", nomes[n]) > 0)
    n++;
  fclose(fdic);

  fscanf(fin, "%s", cod);

  imprimenomes(cod, 0);
  if(achou == 0)
    fprintf(fout, "NONE\n");
  return 0;
}
