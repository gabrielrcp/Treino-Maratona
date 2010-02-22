#include <cstdio>
#include <cstring>

#define MAX 110

int conta[MAX];
int a;

int main()
{
  int v;
  for(int h = 1; scanf(" %d %d", &a, &v) && a; h++){
    memset(conta, 0, sizeof conta);
    v *= 2;
    while(v--){
      int i;
      scanf(" %d", &i);
      i--;
      conta[i]++;     
    }
    int mx = 0;
    for(int i = 0; i < a; i++)
      if(mx < conta[i])
      mx = conta[i];

    bool pri = true;
    printf("Teste %d\n", h);
    for(int i = 0; i < a; i++){
      if(conta[i] == mx){
	if(!pri) printf(" ");
	pri = false;
	printf("%d", i+1);
      }
    }
    printf("\n\n");
  }
  return 0;
}
