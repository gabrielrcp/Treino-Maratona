#include <cstdio>

#define MAX 2000000

int carta[9][4];
double memo[MAX];

int codifica(int *v)
{
  int r = 0;
  for(int i = 0; i < 9; i++)
    r = 5 * r + v[i];
  return r;
}

void decodifica(int r, int *v)
{
  for(int i = 8; i >= 0; i--){
    v[i] = r % 5;
    r /= 5;
  }
}

double vai(int c)
{
  if(c == 0)
    return 1.0;

  double &r = memo[c];
  if(r > -0.5) return r;


  r = 0.0;
  int conta = 0;
  int topo[9];
  decodifica(c, topo);

  for(int i = 0; i < 9; i++){
    if(topo[i] == 0) continue;
    for(int j = i+1; j < 9; j++){
      if(topo[j] == 0) continue;

      if(carta[i][topo[i]-1] == carta[j][topo[j]-1]){
	topo[i]--;
	topo[j]--;
	r += vai(codifica(topo));
	topo[i]++;
	topo[j]++;
	conta++;
      }
    }
  }
  if(conta > 0)
    r /= conta;
  return r;
}

int main()
{
  char buf[10];
  int topo[9];
  for(int i = 0; i < 9; i++){
    topo[i] = 4;
    for(int j = 0; j < 4; j++){
      scanf(" %s", buf);
      switch(buf[0]){
      case 'T':
	carta[i][j] = 10;
	break;
      case 'J':
	carta[i][j] = 11;
	break;
      case 'Q':
	carta[i][j] = 12;
	break;
      case 'K':
	carta[i][j] = 13;
	break;
      case 'A':
	carta[i][j] = 1;
	break;
      default:
	carta[i][j] = buf[0] - '0';
      }
    }
  }

  for(int i = 0; i < MAX; i++)
    memo[i] = -1.0;

  printf("%lf\n", vai(codifica(topo)));
  return 0;
}
