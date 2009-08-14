#include <cstdio>
#include <set>
#include <string>

using namespace std;

int a, b, c;
int dura[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool bissexto(int ano)
{
  if(ano % 400 == 0)
    return true;
  if(ano % 100 == 0)
    return false;
  if(ano % 4 == 0)
    return true;
  return false;
}

void proximo(int &dia, int &mes, int &ano)
{
  if(bissexto(ano))
    dura[2] = 29;
  else
    dura[2] = 28;

  dia++;
  if(dia > dura[mes]){
    dia = 1;
    mes++;
  }
  if(mes > 12){
    mes = 1;
    ano++;
  }
}

bool verifica(int dia, int mes, int ano)
{
  if(c >= 100){
    if(ano != c) return false;
    if(dia == a && mes == b) return true;
    if(dia == b && mes == a) return true;
    return false;
  }
  ano = ano%100;
  if(dia == a && mes == b && ano == c)
    return true;
  if(dia == a && mes == c && ano == b)
    return true;
  if(dia == b && mes == a && ano == c)
    return true;
  if(dia == b && mes == c && ano == a)
    return true;
  if(dia == c && mes == a && ano == b)
    return true;
  if(dia == c && mes == b && ano == a)
    return true;
  return false;
}

set<int> possiveis;

void resolve()
{

  //printf("-- %d %d %d\n", a, b, c);

  int dia=1, mes=1, ano=1700;
  int atual = -(110007 + 238);
  
  while(ano < 2300){
    if(verifica(dia, mes, ano))
      possiveis.insert(atual);
    atual++;
    proximo(dia, mes, ano);
  }
}

int v[3] = {1, 2, 4};


bool separadores(string s)
{
  for(int i = 0; i < s.size(); i++)
    if(s[i] < '0' || s[i] > '9')
      return true;
  return false;
}

void bt(string s)
{
  possiveis.clear();

  if(separadores(s)){
    for(int i = 0; i < s.size(); i++)
      if(s[i] < '0' || s[i] > '9')
	s[i] = ' ';
    
    sscanf(s.c_str(), " %d %d %d", &a, &b, &c);

    if(a >= 100)
      swap(a, c);
    if(b >= 100)
      swap(b, c);
    if(a < 100 && b < 100)
      resolve();
    return;
  }

  int n = s.size();
  //printf("-- %d %s\n", s.c_str());
  for(int k1 = 0; k1 < 3; k1++)
    for(int k2 = 0; k2 < 3; k2++)
      for(int k3 = 0; k3 < 3; k3++){
	if(v[k1] + v[k2] + v[k3] != n)
	  continue;
	sscanf(s.substr(0, v[k1]).c_str(), " %d", &a);
	sscanf(s.substr(v[k1], v[k2]).c_str(), " %d", &b);
	sscanf(s.substr(v[k1]+v[k2], v[k3]).c_str(), " %d", &c);

 	//printf("%d %d %d\n", a, b, c);

	if(v[k1] == 4 && a < 1700)
	  continue;
	if(v[k2] == 4 && b < 1700)
	  continue;
	if(v[k3] == 4 && c < 1700)
	  continue;

	if(a >= 100)
	  swap(a, c);
	if(b >= 100)
	  swap(b, c);

	if(c >= 100 && c < 1700)
	  continue;
	if(a >= 100 || b >= 100)
	  continue;

	if(a == 0 || b == 0 || c == 0)
	  continue;
	resolve();
      }
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("Scenario #%d:\n", h);

    char buf[20];
    scanf(" ");
    gets(buf);

    bt(buf);
    for(set<int>::iterator it = possiveis.begin(); it != possiveis.end(); it++)
      printf("%d\n", *it);
    if(possiveis.size() == 0)
      printf("Illegal date\n");
    printf("\n");
  }
}
