#include <cstdio>


typedef long long ll;

ll v[1<<20];
int num;

int conta(ll x)
{
  int r = 0;
  int j = num-1;
  for(int i = 0; v[i] <= x && i <= j; i++){
    while(v[i] + v[j] > x && j > i) j--;
    if(v[i] + v[j] == x && j >= i)
      r++;
  }
  return r;
}


int main()
{
  int casos;
  scanf(" %d", &casos);

  for(num = 0; num < (1<<16); num++)
    v[num] = (ll)num*num;

  while(casos--){
    ll x;
    scanf(" %lld", &x);
    printf("%d\n", conta(x));
  }

  return 0;
}
