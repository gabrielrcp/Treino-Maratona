#include <cstdio>


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    int n;
    scanf(" %d", &n);
    int mx = 1, x;
    for(int i = 0; i < n; i++){
      scanf(" %d", &x);
      if(mx < x) mx = x;
    }
    if(mx > 1 || (n % 2 == 0))
      printf("John\n");
    else
      printf("Brother\n");
  }
  return 0;
}
