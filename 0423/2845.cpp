#include <cstdio>
#include <cstring>

#define MAX 100
int num1[MAX], num2[MAX];

void ler(int *num)
{
  char buf[MAX];
  scanf(" %s", buf);
  int n = strlen(buf);

  for(int i = 0; i < n; i++)
    num[i] = buf[n-1-i] - '0';
  for(int i = n; i < MAX; i++)
    num[i] = 0;
}

void somar()
{
  int r = 0;
  for(int i = 0; i < MAX; i++){
    num1[i] += r + num2[i];
    r = 0;
    while(num1[i] >= 2){
      num1[i] -= 2;
      r++;
    }
  }
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    ler(num1);
    ler(num2);
    somar();
    printf("%d ", h);
    int n = MAX - 1;
    while(n >= 0 && num1[n] == 0) n--;
    if(n < 0)
      printf("0");
    while(n >= 0){
      printf("%d", num1[n]);
      n--;
    }
    printf("\n");
  }
  return 0;
}
