#include <stdio.h>

char matriz[100][100];
int n;

void confere()
{
  int i, j, s;
  int mi, mj;

  mi = mj= -1;

  for(i=0; i<n; i++){
    s = 0;
    for(j=0; j<n; j++)
      s += matriz[i][j];
    if(s % 2 != 0){
      if(mi == -1)
	mi = i;
      else{
	printf("Corrupt\n");
	return;
      }
    }
  }

  for(j=0; j<n; j++){
    s = 0;
    for(i=0; i<n; i++)
      s += matriz[i][j];
    if(s % 2 != 0){
      if(mj == -1)
	mj = j;
      else{
	printf("Corrupt\n");
	return;
      }
    }
  }

  if(mi == -1 && mj == -1){
    printf("OK\n");
    return;
  }

  if(mi == -1 || mj == -1){
    printf("Corrupt\n");
    return;
  }
  printf("Change bit (%d,%d)\n", mi+1, mj+1);
}


int main()
{

  int i, j, k;
  while(1)
    {
      scanf(" %d", &n);
      if(n == 0)
	break;
      for(i=0; i<n; i++)
	for(j=0; j<n; j++){
	  scanf(" %d", &k);
	  matriz[i][j] = (char)k;
	}
      confere();
    }
  return 0;
}
