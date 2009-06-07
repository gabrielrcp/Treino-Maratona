#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define MAX 101000


struct no{
  char letra;
  int cumarv;
  struct no *pai;
  struct no *filhos[26];
};

no _nos[MAX];
int contanos;

no *v1[1010], *v2[1010];


string numeros[10] = {"",
		      "", "abc","def",
		      "ghi", "jkl","mno",
		      "pqrs", "tuv", "wxyz"};




inline no *novo_no(no *pai, char letra)
{
  no *r = &_nos[contanos];

  r->letra = letra;
  for(int i = 0; i < 26; i++)
    r->filhos[i] = NULL;
  r->pai = pai;
  r->cumarv = 0;
  contanos++;
  return r;
}

void insere(no *arv, string pal, int prob)
{
  //cout << pal << " - " << pal.size() << endl;
  arv->cumarv += prob;
  if(pal.size() == 0)
    return;
  
  int l = pal[0]-'a';
  if(arv->filhos[l] == NULL)
    arv->filhos[l] = novo_no(arv, pal[0]);
  insere(arv->filhos[l], pal.substr(1, pal.size()-1), prob);
}

void imprime(no *folha)
{
  if(folha == NULL)
    printf("MANUALLY");
  else if(folha->pai != NULL){
    imprime(folha->pai);
    putchar(folha->letra);
  }
}

void resolve(string s, no *arv)
{
  no **pode, **temp, **temp2;
  pode = v1; temp = v2;

  int numpode = 1, numtemp = 0;
  pode[0] = arv;

  for(int i = 0; i+1 < s.size(); i++){


    no *melhor = NULL;
    int mprob = 0;
    
    numtemp = 0;
    for(int j = 0; j < numpode; j++){
      for(int k = 0; k < numeros[s[i]-'0'].size(); k++){
	temp[numtemp] = pode[j]->filhos[numeros[s[i]-'0'][k] - 'a'];
	if(temp[numtemp] != NULL){
	  if(mprob < temp[numtemp]->cumarv){
	    melhor = temp[numtemp];
	    mprob = melhor->cumarv;
	  }
	  numtemp++;
	}
      }
    }

    temp2 = pode;
    pode = temp;
    temp = temp2;
    numpode = numtemp;
    
    imprime(melhor);
    putchar('\n');
  }

}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){

    int numpal;
    char buf[110];
    contanos = 0;
    no *arv = novo_no(NULL, ' ');

    scanf(" %d", &numpal);
    while(numpal--){
      int p;
      scanf(" %s %d", buf, &p);
      insere(arv, buf, p);
    }
    
    printf("Scenario #%d:\n", h);
    scanf(" %d", &numpal);
    while(numpal--){
      scanf(" %s", buf);
      resolve(buf, arv);
      printf("\n");
    }
    printf("\n");

  }



  return 0;
}
