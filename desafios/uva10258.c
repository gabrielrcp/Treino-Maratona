/* UVA 10258 - Contest ScoreBoard */
/* Accepted */


#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#if DEBUG
#define debug(x) x
#else
#define debug(x)
#endif

typedef struct {
  int no;
  int nores;
  char res[9];
  int penal[9];
  int tempo;
  char ligado;
}Competidor;


Competidor comp[100];


void zerar()
{
  int i, j;
  for(i=0; i<100; i++)
    {
      comp[i].no = i + 1;
      comp[i].nores = 0;
      for(j=0; j<9; j++)
	comp[i].res[j] = comp[i].penal[j] = 0;
      comp[i].tempo = 0;
      comp[i].ligado = 0;
    }
}

int compara(const void *p1, const void *p2)
{
  Competidor *a = (Competidor *)p1;
  Competidor *b = (Competidor *)p2;
  if(a->nores != b->nores)
    return (b->nores - a->nores);
  if(a->tempo != b->tempo)
    return (a->tempo - b->tempo);
  return a->no - b->no;
     
}


int main()
{
  int casos;
  char buffer[500];
  int nc, np, t;
  char l;
  int i;

  scanf(" %d", &casos);
  while(getchar() != '\n');
  while(getchar() != '\n');
  while(casos--)
    {
      
      zerar();
      while(42)
	{
	  	  
	  if(fgets(buffer, 490, stdin) == NULL)
	    break;
	  debug(printf("-%s-\n", buffer));
	  if(sscanf(buffer, " %d %d %d %c", &nc, &np, &t, &l) != 4)
	    break;


	  np--; nc--;
	  comp[nc].ligado = 1;
	  if(l == 'C' && comp[nc].res[np] == 0){
	    comp[nc].res[np] = 1;
	    comp[nc].nores++;
	    comp[nc].penal[np] += t;
	    comp[nc].tempo += comp[nc].penal[np];
	  }
	  if(l == 'I' && comp[nc].res[np] == 0)
	    comp[nc].penal[np] += 20;
	  
	}
      qsort(comp, 100, sizeof(Competidor), compara);
      for(i=0; i<100; i++)
	if(comp[i].ligado)
	  printf("%d %d %d\n", comp[i].no, comp[i].nores, comp[i].tempo);
      if(casos > 0)
	putchar('\n');	  
    }
  return 0;
}
