#include <cstdio>
#include <cstring>

#define MAX 1000010

int divide[MAX];

void crivo()
{
  memset(divide, -1, sizeof divide);
  for(int i = 2; i <= MAX/i; i++){
    if(divide[i] != -1) continue;
    for(int j = i; j < MAX; j += i){
      divide[j] = i;
    }
  }
  for(int i = 2; i < MAX; i++)
    if(divide[i] == -1) divide[i] = i;
}

int main()
{
  crivo();
  
  while(1){
    int n;
    scanf(" %d", &n);
    if(n == 0) break;
    printf("%d : ", n);
    int c = (n == 1 ? 1 : 0);
    int ult = -1;
    while(n != 1){
      //fprintf(stderr, "%d %d\n", n, divide[n]);
      if(divide[n] != ult) c++;
      ult = divide[n];
      n /= divide[n];
    }
    printf("%d\n", c);
  }
  
  return 0;
}
