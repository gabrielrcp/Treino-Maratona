#include <cstdio>

#define MAX 16000010

bool v[MAX];


int main()
{
  unsigned int a, c, m, r0;
  scanf(" %u %u %u %u", &a, &c, &m, &r0);

  for(int i = 0; i < m; i++)
    v[i] = false;

  while(!v[r0]){
    v[r0] = true;
    r0 = (a * r0  + c) % m;
  }

  int i = 0, j;
  int r = 0;
  while(!v[i]) i++;
  j = i + 1;
  while(j < m){
    if(v[j]){
      if(j - i > r)
	r = j - i;
      i = j;
    }
    j++;
  }
  printf("%d\n", r);
  
  return 0;
}
