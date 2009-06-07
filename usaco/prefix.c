/*
ID: gabriel9
LANG: C
TASK: prefix
*/

#include <stdio.h>
#include <string.h>


#define MAX 200000

char pref[200][11];
int npref;
int tampref[200];
char palavra[MAX];
char guarda[MAX+1];


int comecacom(char *a, char *b)
{
  int i;
  for(i=0; b[i] != '\0'; i++){
    if(a[i] != b[i])
      return 0;
  }
  return 1;
}


int existepref(int tam)
{
  int i;

  if(tam < 0)
    return 0;
  if(tam == 0)
    return 1;
  if(guarda[tam] != -1)
    return guarda[tam];

  for(i=0; i<npref; i++)
    if(existepref(tam - tampref[i]) &&
       comecacom(palavra+tam-tampref[i], pref[i])){
      guarda[tam] = 1;
      return 1;
    }
  guarda[tam] = 0;
  return 0;
}

int main()
{
  int i, j;
  char *p;
  char temp[80];
  int t;
  
  FILE *fin = fopen("prefix.in", "r");
  FILE *fout = fopen("prefix.out", "w");
  /*
  FILE *fin = stdin;
  FILE *fout = stdout;
  */

  for(i=0; i<200; i++){
    fscanf(fin, " %s", temp);
    if(temp[0] == '.')
      break;
    for(j=0; temp[j] != '\0'; j++)
      pref[i][j] = temp[j];
    pref[i][j] = '\0';
    tampref[i] = j;
  }
  
  if(i == 200)
    fscanf(fin, " %s", palavra);
  npref = i;
  
  t = 0;
  p = palavra;
  while(fscanf(fin, " %s", temp) > 0){
    for(i=0; temp[i] != '\0'; i++)
      p[i] = temp[i];
    p += i;
    t += i;
  }

  for(i=0; i<=MAX; i++)
    guarda[i] = -1;

  /*
  for(i=0; i<npref; i++)
    fprintf(stderr, "%s\n", pref[i]);

  fprintf(stderr, "%s\n", palavra);
  fprintf(stderr, "%d\n", t);
  */
  
  while(!existepref(t))
    t--;

  fprintf(fout, "%d\n", t);
  
  return 0;
}
