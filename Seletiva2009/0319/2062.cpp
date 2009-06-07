#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct carta{
  int numero;
  int naipe;
  bool operator < (const carta &outra) const {
    if(numero == outra.numero)
      return naipe < outra.naipe;
    return (numero < outra.numero);
  }
};

vector<carta> adv, minha;
vector<bool> usei;
int n;


carta ler(char *c)
{
  carta r;

  if('2' <= c[0] && c[0] <= '9')
    r.numero = c[0] - '0';
  else if(c[0] == 'T')
    r.numero = 10;
  else if(c[0] == 'J')
    r.numero = 11;
  else if(c[0] == 'Q')
    r.numero = 12;
  else if(c[0] == 'K')
    r.numero = 13;
  else //ACE
    r.numero = 14;

  if(c[1] == 'C')
    r.naipe = 1;
  else if(c[1] == 'D')
    r.naipe = 2;
  else if(c[1] == 'S')
    r.naipe = 3;
  else //H
    r.naipe = 4;

  return r;
}

int escolhe(carta c)
{
  int i = 0;
  while(usei[i])
    i++;
  for(int j = i; j < n; j++)
    if(c < minha[j] && (!usei[j]))
      return j;
  return i;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d", &n);
    adv = vector<carta> (n);
    minha = vector<carta> (n);
    usei = vector<bool> (n, false);
    for(int i = 0; i < n; i++){
      char buf[5];
      scanf(" %s", buf);
      adv[i] = ler(buf);
    }
    for(int i = 0; i < n; i++){
      char buf[5];
      scanf(" %s", buf);
      minha[i] = ler(buf);
    }

    sort(minha.begin(), minha.end());
    /*    
    for(int i = 0; i < n; i++)
      printf("%d-%d ", minha[i].numero, minha[i].naipe);
    printf("\n");
    */
    int r = 0;
    for(int i = 0; i < n; i++){
      int j = escolhe(adv[i]);
      if(adv[i] < minha[j])
	r++;
      usei[j] = true;
    }
    printf("%d\n", r);
  }
  return 0;
}
