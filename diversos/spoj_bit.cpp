#include <cstdio>

int val[4] = {50, 10, 5, 1};

int main()
{
  int v;
  for(int h = 1; ; h++){
    scanf(" %d", &v); if(v == 0) break;
    printf("Teste %d\n", h);
    for(int i = 0; i < 4; i++){
    	if(i > 0) printf(" ");
    	printf("%d", v / val[i]);
    	v %= val[i];
    }
    printf("\n\n");
  }
  return 0;
}

