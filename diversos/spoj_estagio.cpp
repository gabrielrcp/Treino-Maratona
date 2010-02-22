#include <cstdio>
#include <cstring>

#define MAX 1010

int n;
int cod[MAX], med[MAX];

int main()
{
  for(int h = 1; scanf(" %d ", &n) && n; h++){
    
    int mx = 0;
    for(int i = 0; i < n; i++){
      scanf(" %d %d", cod+i, med+i);
      if(mx < med[i])
	mx = med[i];
    }

    bool pri = true;
    printf("Turma %d\n", h);
    for(int i = 0; i < n; i++){
      if(med[i] == mx){
	if(!pri) printf(" ");
	pri = false;
	printf("%d", cod[i]);
      }
    }
    printf("\n\n");
  }
  return 0;
}
