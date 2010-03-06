#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct resposta{
  int conta[10];
  int numdig;
  bool operator < (const resposta &o) const{
    if(numdig != o.numdig)
      return numdig < o.numdig;
    for(int i = 2; i < 10; i++)
      if(conta[i] != o.conta[i])
	return conta[i] > o.conta[i];
    return false;
  }
};

resposta memo[30][30];

resposta pd(int c2, int c3)
{
  resposta &r = memo[c2][c3];
  if(r.numdig != -1)
    return r;

  memset(r.conta, 0, sizeof r.conta);
  r.numdig = c2+c3;
  r.conta[2] = c2;
  r.conta[3] = c3;

  resposta at;
  
  if(c2 >= 3){
    at = pd(c2-3, c3);
    at.numdig++;
    at.conta[8]++;
    r = min(r, at);
  }
  if(c2 >= 2){
    at = pd(c2-2, c3);
    at.numdig++;
    at.conta[4]++;
    r = min(r, at);
  }
  if(c3 >= 2){
    at = pd(c2, c3-2);
    at.numdig++;
    at.conta[9]++;
    r = min(r, at);
  }
  if(c2 >= 1 && c3 >= 1){
    at = pd(c2-1, c3-1);
    at.numdig++;
    at.conta[6]++;
    r = min(r, at);
  }

  return r;
}

void vai(int n)
{
  int conta[10];
  memset(conta, 0, sizeof conta);

  if(n <= 1){
    printf("%d\n", (n==1 ? n : 10));
    return;
  }

  for(int i = 2; i < 10; i++){
    while(n % i == 0){
      conta[i]++;
      n /= i;
    }
  }

  if(n != 1){
    printf("-1\n");
    return;
  }

  for(int i = 0; i <= conta[2]; i++)
    for(int j = 0; j <= conta[3]; j++)
      memo[i][j].numdig = -1;


  resposta r = pd(conta[2], conta[3]);

  for(int i = 2; i < 10; i++)
    if(i != 5 && i != 7)
      conta[i] = r.conta[i];


  for(int i = 2; i < 10; i++){
    while(conta[i]--)
      printf("%d", i);
  }
  printf("\n");
}


int main()
{
  int n;

  scanf("%d", &n);
  vai(n);

  return 0;
}
