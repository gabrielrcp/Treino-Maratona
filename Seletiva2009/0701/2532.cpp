#include <cstdio>
#include <string>


using namespace std;

string meses[12] = {".JANUARY.........",
		    ".FEBRUARY........",
		    ".MARCH...........",
		    ".APRIL...........",
		    ".MAY.............",
		    ".JUNE............",
		    ".JULY............",
		    ".AUGUST..........",
		    ".SEPTEMBER.......",
		    ".OCTOBER.........",
		    ".NOVEMBER........",
		    ".DECEMBER........"};
int dias_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool bissexto(int ano)
{
  if(ano % 400 == 0)
    return true;
  if(ano % 100 == 0)
    return false;
  if(ano % 4 == 0)
    return true;
  return false;
}

int inicio_semana(int ano, int mes)
{
  int at = 0;
  for(int i = 1900; i < ano; i++)
    if(bissexto(i))
      at += 2;
    else
      at++;
  at %= 7;
  for(int i = 0; i < mes; i++){
    if(dias_mes[i] == 31)
      at += 3;
    else if(dias_mes[i] == 30)
      at += 2;
    else if(bissexto(ano))
      at++;
  }
  return (at%7);
}

int dura_mes(int ano, int mes)
{
  if(mes == 1)
    return (bissexto(ano) ? 29 : 28);
  return dias_mes[mes];
}

char tempmes[8][17];

void imprimemes(int ano, int mes)
{
  for(int i = 0; i < 17; i++)
    tempmes[0][i] = meses[mes][i];

  for(int i = 1; i < 8; i++)
    for(int j = 0; j < 17; j++)
      tempmes[i][j] = '.';


  int at = inicio_semana(ano, mes);

  int diaat = 1;
  int dura = dura_mes(ano, mes);
  for(int j = 0; j < 8; j++)
    for(int i = 0; i < 7; i++){
      if(j != 0) tempmes[i+1][3*j-1] = '.';
      if(i < at)
	tempmes[i+1][3*j] = tempmes[i+1][3*j+1] = '.';
      else if(i == at)
	at = -1;
      if(at != -1) continue;

      if(diaat < 10)
	tempmes[i+1][3*j] = '.';
      else
	tempmes[i+1][3*j] = diaat/10 + '0';
      tempmes[i+1][3*j+1] = (diaat%10) + '0';
      diaat++;
      if(diaat > dura)
	return;
    }
}

char calend[28][73];


void imprimeano(int ano)
{
  int i = 0, j = 0;

  for(int i = 0; i < 28; i++)
    for(int j = 0; j < 73; j++)
      calend[i][j] = '.';


  for(int mes = 0; mes < 12; mes++){
    imprimemes(ano, mes);
    for(int k = 0; k < 8; k++)
      for(int l = 0; l < 17; l++)
	calend[9*i+k+1][18*j+l+1] = tempmes[k][l];
    j++;
    if(j == 4){
      i++;
      j = 0;
    }
  }
}

int n, m;
char agulha[15][15];
// 28 e 73

bool bate(int x, int y)
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(agulha[i][j] != calend[x+i][y+j])
	return false;
  return true;
}


bool vai()
{
  for(int i = 0; i + n <= 28; i++){
    for(int j = 0; j + m < 73; j++){
      if(bate(i, j)){
	//printf("%d %d\n", i, j);
	return true;
      }
    }
  }
  return false;
}


int main()
{
  
  scanf(" %d %d", &m, &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      scanf(" %c", &agulha[i][j]);
  /*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      putchar(agulha[i][j]);
    putchar('\n');
  }
  */

  int conta = 0;
  for(int ano = 1900; ano <= 2100; ano++){
    imprimeano(ano);
    if(vai()){
      printf("%d\n", ano);
      conta++;
    }
  }

  if(conta == 0)
    printf("0\n");

  /*
  imprimeano(2009);
  for(int i = 0; i < 28; i++){
    for(int j = 0; j < 73; j++)
      putchar(calend[i][j]);
    putchar('\n');
  }
  */

  return 0;
}
