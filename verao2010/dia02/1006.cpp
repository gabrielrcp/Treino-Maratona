#include <cstdio>

int periodo[3] = {23, 28, 33};
int ini;
int pri[3];

int at[3];

inline int modulo(int x, int m)
{
  return (((x % m) + m)%m);
}

int main()
{
  for(int h = 1; ; h++){
    for(int i = 0; i < 3; i++)
      scanf(" %d", pri+i);
    ini = -1;
    scanf(" %d", &ini);
    if(ini < 0) break;

    for(int i = 0; i < 3; i++)
      at[i] = modulo(ini+1 - pri[i], periodo[i]);

    int r = 1;
    while(at[0] || at[1] || at[2]){
      r++;
      for(int i = 0; i < 3; i++){
	at[i]++;
	if(at[i] == periodo[i]) at[i] = 0;
      }
    }
    printf("Case %d: the next triple peak occurs in %d days.\n", h, r);
  }
  return 0;
}
