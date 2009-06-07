#include <cstdio>
#include <cstring>
#include <string>


#define TAM 32768

unsigned char vetor[TAM];
unsigned char *pont;


char buf[128010];

char prog[128010];
int tamprog;

char imp[128010];
int cimp;


int proximo(int p)
{
  int s = 0;
  do{
    if(prog[p] == '[')
      s++;
    else if(prog[p] == ']')
      s--;
    p++;
  }while(s > 0);
  p--;
  return p;
}

int anterior(int p)
{
  int s = 0;
  do{
    if(prog[p] == '[')
      s--;
    else if(prog[p] == ']')
      s++;
    p--;
  }while(s > 0);
  p++;
  return p;
  
}


void roda()
{
  int p = 0;
  pont = vetor;
  for(int i = 0; i < TAM; i++)
    vetor[i] = 0;

  while(1){
    if(p == tamprog)
      return;
    switch(prog[p]){
    case '<':
      if(pont == vetor)
	pont = vetor + TAM;
      pont--;
      break;
    case '>':
      pont++;
      if(pont == vetor + TAM)
	pont = vetor;
      break;
    case '+':
      (*pont)++;
      break;
    case '-':
      (*pont)--;
      break;
    case '.':
      printf("%c", *pont);
      break;
    case '[':
      if(*pont == 0)
	p = proximo(p);
      break;
    case ']':
      if(*pont != 0)
	p = anterior(p);
      break;
    }
    p++;
  }
}

int confere()
{
  int s = 0;
  for(int i = 0; i < tamprog; i++){
    if(prog[i] == '[')
      s++;
    else if(prog[i] == ']'){
      s--;
      if(s < 0) return 0;
    }
  }
  return (s == 0);
}

int main()
{
  int ncasos;
  scanf(" %d\n", &ncasos);
  for(int caso = 1; caso <= ncasos; caso++){
    printf("PROGRAM #%d:\n", caso);
    tamprog = 0;
    while(1){
      gets(buf);
      //printf("-*-|%s|-*-\n", buf);
      if(strcmp(buf, "end") == 0)
	break;
      for(int i = 0; buf[i] != '\0'; i++){
	if(buf[i] == '%')
	  break;
	switch(buf[i]){
	case '<': case '>': case '+': case '-': case '.': case '[': case ']':
	  prog[tamprog++] = buf[i];
	  //putchar(buf[i]);
	}
      }
      //putchar('\n');
    }

    /*
    for(int i = 0; i < tamprog; i++)
      putchar(prog[i]);
    putchar('\n');
    */

    if(!confere()){
      printf("COMPILE ERROR\n");
    }   
    else{
      roda();
      printf("\n");
    }
  }
  //printf("%d\n", 'A');
  return 0;
}
