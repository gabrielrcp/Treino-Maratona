#include <cstdio>

#define MAX 1000000

int n, k;

int perde[MAX];
int np;

int busca(int *v, int val)
{
  int esq = 0, dir = np - 1;
  int resp = dir;
  while(esq <= dir){
    int m = (esq+dir)/2;
    if(v[m] >= val){
      resp = m;
      dir = m - 1;
    }
    else
      esq = m + 1;
  }
  return resp;
}

int resolve()
{

  if(n <= k + 1)
    return -1;

  np = 0;
  for(int i = 1; i <= k+1; i++)
    perde[np++] = i;

  int at = k+1;
  while(1){
    int x = at / k;
    if(at % k) x++;
    x = perde[busca(perde, x)];
    at += x;
    if(at > n)
      break;
    perde[np++] = at;
  }

  if(perde[np-1] == n)
    return -1;


  int resp = n - perde[np-1];
  while(resp > 1){
    int i = busca(perde, resp);
    if(perde[i] == resp)
      return resp;
    i--;
    resp = resp - perde[i];
  }

  return resp;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    scanf("%d %d", &n, &k);
    printf("Case %d: ", h);

    int r = resolve();
    if(r == -1)
      printf("lose\n");
    else
      printf("%d\n", r);
    /*
    if(h <= 5){
      int l = n;
      for(int i = 2; i <= l; i++){
	n = i;
	printf("-- %d %d %d\n", i, k, resolve());
      }
      //printf("\n");
    }
    */
    //printf("-- %d\n", np);
  }


  return 0;
}
