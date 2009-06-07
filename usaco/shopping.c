/*
ID: gabriel9
LANG: C
TASK: shopping
*/

#include <stdio.h>

typedef struct {
  int n;
  int cod[5];
  int qtde[5];
  int preco;
} Oferta;

int s;
Oferta oferta[100];


int b;
int cod[5];
int qtde[5];
int preco[5];

int minimo[6][6][6][6][6];


int cabe(int k)
{
  int i, j;
  for(i = 0; i < oferta[k].n; i++){
    for(j = 0; j < b; j++){
      if(cod[j] == oferta[k].cod[i]){
	if(oferta[k].qtde[i] <= qtde[j])
	  break;
	else
	  return 0;
      }
      if(j == b)
	return 0;
    }
  }
  return 1;
}

void ordena()
{

  int i, j;
  int t;

  for(i=b; i > 0; i--){
    for(j=1; j < i; j++){
      if(cod[j-1] > cod[j]){
	t = cod[j];
	cod[j] = cod[j-1];
	cod[j-1] = t;

	t = preco[j];
	preco[j] = preco[j-1];
	preco[j-1] = t;

	t = qtde[j];
	qtde[j] = qtde[j-1];
	qtde[j-1] = t;
      }
    }
  }
}

int compara(const void *a, const void *b)
{
  return ((Oferta *)a)->cod - ((Oferta *)b)->cod
}


int main()
{

  int i, j, k;
  int i1, i2, i3, i4, i5;
  Oferta temp;
  FILE *fin = fopen("shopping.in", "r");
  FILE *fout = fopen("shopping.out", "w");

  fscanf(fin, " %d", &s);

  for(i=0; i<s; i++)
    {
      fscanf(fin, " %d", &oferta[i].n);
      for(j=0; j < oferta[i].n; j++)
	fscanf(fin, " %d %d", &oferta[i].cod, &oferta[i].qtde);
      fscanf(fin, " %d", &oferta[i].preco);

    }

  fscanf(fin, " %d", &b);

  for(i=0; i<b; i++)
    fscanf(" %d %d %d", cod+i, qtde+i, preco+i);


  i = j = 0;
  while(i < s && !cabe(i))
    i++;
  while(i < s){
    temp = oferta[i];
    oferta[i] = oferta[j];
    oferta[j] = temp;
    j++;
    i++;
    while(i < s && !cabe(i))
      i++;
  }
  s = j;



  for(k = 0; k < s; k++)
    for(i=0; i<oferta[k].n; i++)
      for(j=0; j<b; j++)
	if(oferta[k].cod[i] == cod[j]){
	  oferta[k].cod[i] = j;
	  break;
	}

  ordena();

  qsort(oferta, s, 


  for(i1=0; i1 <= qtde[0]; i1++)
    for(i2=0; i2 <= qtde[1]; i2++)
      for(i3=0; i3 <= qtde[2]; i3++)
	for(i4=0; i4 <= qtde[3]; i4++)
	  for(i5=0; i5 <= qtde[4]; i5++)
	    minimo[i1][i2][i3][i4][i5] = preco[0]*i1 + preco[1]*i2 
	      + preco[2]*i3 + preco[3]*i4 + preco[4]*i5;

  for(k=0; k < s; k++)
    for(i1=0; i1 <= qtde[0]; i1++)
      for(i2=0; i2 <= qtde[1]; i2++)
	for(i3=0; i3 <= qtde[2]; i3++)
	  for(i4=0; i4 <= qtde[3]; i4++)
	    for(i5=0; i5 <= qtde[4]; i5++)
	      {
		if(minimo[
	      }
	      
  return 0;
}
