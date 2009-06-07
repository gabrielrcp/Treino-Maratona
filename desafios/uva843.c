/* Crypt Kicker */
/* UVA 843 */
/* Accepted */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  int ini;
  int tam;
} Guarda;


char dic[20][1000][20];
int n;
int num[20];

char buf[100];

Guarda palavras[100];
int numpal;

char mapa[256];
char usado[256];


char aki[100][16];

int compara(const void *a, const void *b)
{
  return ((Guarda *)b)->tam -  ((Guarda *)a)->tam;
}

int tentar(int p)
{
  int i, j, tam;
  char pode;
  char *s1, *s2;

  if(p >= numpal)
    return 1;
  tam = palavras[p].tam;

  for(j=0; j < num[tam]; j++){

    pode = 1;

    s1 = buf + palavras[p].ini;
    s2 = dic[tam][j];

    for(i=0; i<tam; i++){
      if(mapa[s1[i]] && mapa[s1[i]] != s2[i]){
	pode = 0;
	goto saida;
      }
      if(mapa[s1[i]] == 0 && usado[s2[i]]){
	pode = 0;
	goto saida;
      }

      mapa[s1[i]] = s2[i];
      usado[s2[i]] = 1;
      aki[p][i] = 1;
    }

    if(tentar(p+1))
      return 1;
    
  saida:

    for(i=0; i<tam; i++){
      if(aki[p][i]){
	mapa[s1[i]] = 0;
	usado[s2[i]] = 0;
	aki[p][i] = 0;
      }
    }
    
  }


  return 0;
}

int main()
{
  int i, j, t;
  int tamtot;

  for(i=0; i<20; i++)
    num[i] = 0;

  scanf(" %d", &n);
  for(i=0; i<n; i++){
    scanf(" %s\n", buf);
    t = strlen(buf);
    strcpy(&dic[t][num[t]][0], buf);
    num[t]++;
  }

  while(scanf("%[^\n]\n", buf) != EOF)
    {
      tamtot = strlen(buf);
      numpal = 0;
      for(i=0; i < tamtot; i++)
	if(buf[i] == ' ')
	  buf[i] = '\0';
	else{
	  palavras[numpal].ini = i;
	  for(j=i+1; 'a' <= buf[j] && buf[j] <= 'z'; j++);
	  j--;
	  palavras[numpal].tam = j - i + 1;
	  numpal++;
	  i = j;
	}

      qsort(palavras, numpal, sizeof(Guarda), compara);

      for(i='a'; i<='z'; i++){
	mapa[i] = 0;
	usado[i] = 0;
      }

      for(i=0; i < numpal; i++)
	for(j=0; j < palavras[i].tam; j++)
	  aki[i][j] = 0;


      if(!tentar(0))
	for(i=0; i < tamtot; i++)
	  if('a' <= buf[i] && buf[i] <= 'z')
	    putchar('*');
	  else
	    putchar(' ');
      else
	for(i=0; i < tamtot; i++)
	  if('a' <= buf[i] && buf[i] <= 'z')
	    putchar(mapa[(int)buf[i]]);
	  else
	    putchar(' ');

      putchar('\n');

    }
  return 0;
}
