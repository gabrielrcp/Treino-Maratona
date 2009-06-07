/* UVA 10051 - Tower of cubes
   Accepted */

#include <stdio.h>
#include <string.h>

#define MAX 510

typedef struct{
  int cor[6];
  int max[6];
}Cubo;

Cubo pilha[MAX];
const char verso[6] = {1, 0, 3, 2, 5, 4};
int ultima[101];
int temp[101];
int n;

const char nomes[6][10] = {"front", "back", "left", "right", "top" ,"bottom"};

void proximo(int *mi, int *mj, int m, int c)
{
  int i, j;
  if(pilha[*mi].max[*mj] == m && pilha[*mi].cor[*mj] == c)
    return;
  for(i = *mi + 1; i < n; i++)
    for(j = 0; j < 6; j++)
      if(pilha[i].max[j] == m && pilha[i].cor[j] == c){
	*mi = i; *mj = j;
	return;
      }
}


int main()
{
  int i, j, k, l;
  int v;
  int h;
  int m, mi, mj;

  for(h = 1; ; h++){
    scanf(" %d",&n);
    if(n == 0)
      break;
    
    for(i = 0; i < n; i++)
      for(j = 0; j < 6; j++){
	scanf(" %d", &pilha[i].cor[j]);
	pilha[i].max[j] = 1;
      }
	
    for(i=0; i<101; i++)
      temp[i] = n;
    
    for(i = n-1; i>=0; i--){
      memcpy(ultima, temp, 101*sizeof(int));
      for(j = 0; j < 6; j++){
	v = verso[j];
	k = ultima[pilha[i].cor[v]];
	temp[pilha[i].cor[v]] = i;
	if(k == n)
	  continue;
	for(l = 0; l < 6; l++){
	  if(pilha[k].cor[l] == pilha[i].cor[v] && 
	     pilha[i].max[j] < pilha[k].max[l] + 1)
	    pilha[i].max[j] = pilha[k].max[l] + 1;
	  if(pilha[k].cor[verso[l]] == pilha[i].cor[v] && 
	     pilha[i].max[j] < pilha[k].max[l])
	    pilha[i].max[j] = pilha[k].max[l];
	}
      }
    }

    /*    
    for(i = 0; i<n; i++){
      for(j = 0; j < 6; j++)
	printf("%d ", pilha[i].max[j]);
      printf("\n");
    }
    */
    
    m = pilha[0].max[0];
    mi = mj = 0;
    for(i=0; i<n; i++)
      for(j=0; j<6; j++){
	if(pilha[i].max[j] >= m){
	  m = pilha[i].max[j];
	  mi = i; mj = j;
	}
      }
    
    if(h != 1)
      printf("\n");
    printf("Case #%d\n%d\n", h, m);

    while(m > 0){
      proximo(&mi, &mj, m, pilha[mi].cor[verso[mj]]);
      printf("%d %s\n", mi+1, nomes[mj]);
      m--;
    }
    
  }
  return 0;
}
