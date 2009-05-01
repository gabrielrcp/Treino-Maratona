#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define MAX 101000

vector<string> palavras;
vector<int> probabi;

struct no{
  char letra;
  int maxarv;
  int cumarv;
  struct no *pai;
  struct no *filhos[30];
  int fimpal;
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
  for(int i = 0; i < 30; i++)
    r->filhos[i] = NULL;
  r->pai = pai;
  r->maxarv = r->cumarv = 0;
  r->fimpal = -1;
  contanos++;
  return r;
}

void insere(no *arv, int i, string pal, int prob)
{
  //cout << pal << " - " << pal.size() << endl;
  arv->maxarv = max(arv->maxarv, prob);
  arv->cumarv += prob;

  if(pal.size() == 0){
    arv->fimpal = i;
    return;
    
  }
  int l = pal[0]-'a';
  if(arv->filhos[l] == NULL)
    arv->filhos[l] = novo_no(arv, pal[0]);
  insere(arv->filhos[l], i, pal.substr(1, pal.size()-1), prob);
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
    scanf(" %d", &numpal);
    palavras.clear();
    probabi.clear();
    while(numpal--){
      int p;
      scanf(" %s %d", buf, &p);
      palavras.push_back(buf);
      probabi.push_back(p);
    }

    contanos = 0;
    
    no *arv = novo_no(NULL, ' ');
    for(int i = 0; i < palavras.size(); i++){
      insere(arv, i, palavras[i], probabi[i]);
      //cout << palavras[i] << " " << probabi[i] << endl;
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
