#include <stdio.h>
#include <string.h>


int cima(char *t, char *r, int tam)
{
  int i;
  if(tam == 1){
    return 0;
  }
  switch(t[tam-1]){
    case 'r':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 'q';
      r[tam] = '\0';
      return 1;
    case 's':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 'p';
      r[tam] = '\0';
      return 1;
    case 'p':
      if(cima(t, r, tam-1)){
	r[tam-1] = 's';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
    case 'q':
      if(cima(t, r, tam-1)){
	r[tam-1] = 'r';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
  }
  return 0;
}


int baixo(char *t, char *r, int tam)
{
  int i;
  if(tam == 1){
    return 0;
  }
  switch(t[tam-1]){
    case 'q':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 'r';
      r[tam] = '\0';
      return 1;
    case 'p':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 's';
      r[tam] = '\0';
      return 1;
    case 's':
      if(baixo(t, r, tam-1)){
	r[tam-1] = 'p';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
    case 'r':
      if(baixo(t, r, tam-1)){
	r[tam-1] = 'q';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
  }
  return 0;
}

int esq(char *t, char *r, int tam)
{
  int i;
  if(tam == 1){
    return 0;
  }
  switch(t[tam-1]){
    case 'q':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 'p';
      r[tam] = '\0';
      return 1;
    case 'r':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 's';
      r[tam] = '\0';
      return 1;
    case 'p':
      if(esq(t, r, tam-1)){
	r[tam-1] = 'q';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
    case 's':
      if(esq(t, r, tam-1)){
	r[tam-1] = 'r';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
  }
  return 0;
}


int dir(char *t, char *r, int tam)
{
  int i;
  if(tam == 1){
    return 0;
  }
  switch(t[tam-1]){
    case 'p':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 'q';
      r[tam] = '\0';
      return 1;
    case 's':
      for(i=0; i<tam; i++)
	r[i] = t[i];
      r[tam-1] = 'r';
      r[tam] = '\0';
      return 1;
    case 'q':
      if(dir(t, r, tam-1)){
	r[tam-1] = 'p';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
    case 'r':
      if(dir(t, r, tam-1)){
	r[tam-1] = 's';
	r[tam] = '\0';
	return 1;
      }
      else
	return 0;
  }
  return 0;
}


int main()
{
  int n;
  char local[5010];
  char temp[5010];
  int tam;

  scanf(" %d", &n);
  while(n--)
    {
      scanf("%s", local);
      tam = strlen(local);

      if(cima(local, temp, tam))
	printf("%s ", temp);
      else
	printf("<none> ");

      if(baixo(local, temp, tam))
	printf("%s ", temp);
      else
	printf("<none> ");

      if(esq(local, temp, tam))
	printf("%s ", temp);
      else
	printf("<none> ");

      if(dir(local, temp, tam))
	printf("%s\n", temp);
      else
	printf("<none>\n");
    }

  return 0;
}
