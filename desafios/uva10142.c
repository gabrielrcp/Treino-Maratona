/* Autralian Voting */
/* UVA 10142 */
/* Accepted */

#include <stdio.h>

#define DEBUG 0
#if DEBUG
#define debug(x) x
#else
#define debug(x)
#endif


char candidatos[20][82];
int votos[1000][20];
int eleitores;
int preferido[1000];
int n;

char buffer[105];


int total[20];
char eliminado[20];



int ler()
{
  char *c;
  int i;
  if(fgets(buffer, 100, stdin) == NULL)
    return 0;
  
  debug(printf("buffer=|%s|\n", buffer);)
  c = buffer;
  while(*c == ' ')
    c++;

  if(*c == '\n' || c == '\0')
    return 0;

  sscanf(c, " %d", &votos[eleitores][0]);
  votos[eleitores][0]--;
  for(i=1; i<n; i++){
    while(*c >= '0' && *c <= '9')
      c++;
    while(*c == ' ')
      c++;
    sscanf(c, " %d", &votos[eleitores][i]);
    votos[eleitores][i]--;
  }
  eleitores++;
  return 1;
}


int main()
{
  int casos;
  int i, j;
  int max, min;


  scanf(" %d", &casos);
  debug(printf("Casos=%d\n", casos);)
  while(casos--)
    {
      scanf(" %d", &n);
      while(getchar() != '\n');
      for(i=0; i<n; i++){
	fgets(candidatos[i], 81, stdin);
	for(j=0; candidatos[i][j] != '\0'; j++)
	  if(candidatos[i][j] == '\n')
	    candidatos[i][j] = '\0';
	eliminado[i] = 0;
      }

      eleitores = 0;
      while(ler());

      for(i = 0; i < eleitores; i++)
	preferido[i] = 0;


#if DEBUG

      printf("Candidatos\n");
      for(i=0; i<n; i++)
	printf("|%s|", candidatos[i]);


      printf("\nEleitores=%d\n", eleitores);
      for(i=0; i<eleitores; i++){
	for(j=0; j<n; j++)
	  printf("%d ", votos[i][j]);
	putchar('\n');
      }
#endif

      while(42)
	{

	  for(i=0; i<n; i++)
	    total[i] = 0;

	  for(i = 0; i < eleitores; i++)
	    total[votos[i][preferido[i]]]++;

	  max = 0;
	  while(eliminado[max])
	    max++;
	  min = max;

	  for(i=0; i<n; i++){
	    if(eliminado[i])
	      continue;
	    if(total[i] > total[max])
	      max = i;
	    if(total[i] < total[min])
	      min = i;
	  }

	  if(2 * total[max] > eleitores){
	    printf("%s\n", candidatos[max]);
	    break;
	  }

	  if(max == min){
	    for(i=0; i<n; i++)
	      if(!eliminado[i])
		printf("%s\n", candidatos[i]);
	    break;
	  }

	  for(i=0; i<n; i++)
	    if(!eliminado[i] && total[i] == total[min])
	      eliminado[i] = 1;

	  for(i=0; i<eleitores; i++)
	    while(eliminado[votos[i][preferido[i]]])
	      preferido[i]++;

	}

      if(casos > 0)
	putchar('\n');
    }
  return 0;
}
