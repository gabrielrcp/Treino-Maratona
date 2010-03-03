// Vetor de sufixos

// tam maximo do vetor de sufixos
// tome MAX maior que o tamanho do alfabeto
#define MAX 200010
//log do numero anterior
#define LMAX 20

char S[MAX]; //string que vai gerar o vetor
int n; // n = strlen(S);

int P[LMAX][MAX]; // P[j][i] eh o "balde" onde o sufixo comecado em i
                  // estarah quando estivermos considerando tam 2^j
int lim; //variavel interna
int sar[MAX]; // o vetor de sufixos

// struct usado numa lista ligada interna
struct node{
  int v;
  node *prox;
};

// lista livre
node buf[3*MAX];
int bufp;

node *lista[2][MAX];


inline int insere(int k, int i, int v)
{
  node *novo = &buf[bufp++];
  novo->v = v;
  novo->prox = lista[k][i];
  lista[k][i] = novo;
}

void monta()
{
  // mudar isso se o seu alfabeto for diferente
  for(int i = 0; i < n; i++)
    P[0][i] = S[i] - 'a' + 1;

  int pot = 1;
  bool para = false;
  int cnt = 30; //aqui so comecamos com as letras minusculas
  for(lim = 1; !para; lim++){
    
    for(int i = 0; i <= cnt; i++)
      lista[0][i] = lista[1][i] = NULL;
    bufp = 0;

    for(int i = 0; i < n; i++){
      if(i + pot >= n)
	insere(0, 0, i);
      else
	insere(0, P[lim-1][i+pot], i);
    }

    for(int i = cnt; i >= 0; i--)
      for(node *it = lista[0][i]; it != NULL; it = it->prox)
	insere(1, P[lim-1][it->v], it->v);
	     
    para = true;
    int ncnt = 0;
    for(int i = 0; i <= cnt; i++){
      int ult = -1;
      for(node *it = lista[1][i]; it != NULL; it = it->prox){
	int at = ((it->v+pot>=n) ? 0 : P[lim-1][it->v + pot]);
	if(at != ult)
	  ncnt++;
	else
	  para = false;
	P[lim][it->v] = ncnt;
	ult = at;
      }
    }
    if(!para)
      cnt = ncnt;
    pot <<= 1;
  }

  int k = 0;
  for(int i = 0; i <= cnt; i++)
    for(node *it = lista[1][i]; it != NULL; it = it->prox)
      sar[k++] = it->v;
}


// devolve o tamanho do maior prefixo comum 
// entre S[i .. n-1] e S[j .. n-1]
int iguais(int i, int j)
{
  int k = lim - 1;
  int r = 0;
  while(k >= 0 && i < n && j < n){
    if(P[k][i] == P[k][j]){
      r += (1 << k);
      i += (1 << k);
      j += (1 << k);
    }
    k--;
  }
  return r;
}

