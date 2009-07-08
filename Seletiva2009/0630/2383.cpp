#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXC 10000
#define MAX 1000

int xm, ym;
int n;

int cx[MAXC], cy[MAXC], raio[MAXC];
char cor[MAXC];

int pintado[MAX];
int le[MAXC], ld[MAXC];

int raiz[50000];

void inicializa()
{
  int lim = 0;
  for(int k = 0; k < n; k++)
    lim = max(lim, raio[k]);

  int at = 0;
  for(int k = 0; k <= lim; k++){
    while(at*at < k)
      at++;
    raiz[k] = (at*at == k ? at : at-1);
  }
}

void encontra_limites(int linha)
{
  for(int k = 0; k < n; k++){
    int r = (linha - cx[k]);
    r *= r;
    r = raio[k] - r;
    if(r < 0)
      le[k] = ld[k] = -1;
    else{
      r = raiz[r];
      le[k] = max(0, cy[k] - r);
      ld[k] = min(ym-1, cy[k] + r);
    }
  }
}

void imprime_linha(int linha)
{
  encontra_limites(linha);
  for(int j = 0; j < ym; j++)
    pintado[j] = -1;

  for(int k = n-1; k >= 0; k--){
    int j = le[k];
    if(j == -1) continue;
    while(j <= ld[k]){
      if(pintado[j] == -1)
	pintado[j] = k;
      else
	j = ld[pintado[j]];
      j++;
    }
  }
  for(int j = 0; j < ym; j++){
    if(pintado[j] == -1)
      putchar('0');
    else
      putchar(cor[pintado[j]]);
  }
  putchar('\n');
}


int main()
{
  scanf(" %d %d %d", &ym, &xm, &n);
  for(int i = 0; i < n; i++){
    scanf(" %d %d %d %c", cy+i, cx+i, raio+i, cor+i);
    raio[i] *= raio[i];
  }

  inicializa();

  for(int i = 0; i < xm; i++)
    imprime_linha(i);
  return 0;
}
